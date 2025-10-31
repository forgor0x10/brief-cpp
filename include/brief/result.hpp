#pragma once

#include <iostream>
#include <utility>

#define etry(expr)                                                                                 \
    ({                                                                                             \
        auto res = (expr);                                                                         \
        if (res.is_err()) return Err(res.unwrap_err());                                            \
    })

#define atry(expr)                                                                                 \
    ({                                                                                             \
        auto res = (expr);                                                                         \
        if (res.is_err()) { return Err(res.unwrap_err()); }                                        \
        res.unwrap();                                                                              \
    })

#if !defined(__GNUC__) && !defined(__clang__)
#warning                                                                                           \
    "Block expressions ({ ... }) are not supported on this compiler. Disabling 'atry' and 'etry'"
#undef atry
#undef etry
#endif

template <typename T> struct Ok {
  public:
    explicit Ok(T val) : value(std::move(val)) {}
    auto get_value() const -> const T & { return value; }
    auto get_value() -> T & { return value; }

  private:
    T value;
};

template <typename E> struct Err {
  public:
    explicit Err(E val) : value(std::move(val)) {}
    auto get_value() const -> const E & { return value; }
    auto get_value() -> E & { return value; }

  private:
    E value;
};

template <typename T> Ok(T) -> Ok<T>;
template <typename E> Err(E) -> Err<E>;

template <typename T, typename E> class Result {
  private:
    bool m_is_ok;
    union {
        T m_ok_value;
        E m_err_value;
    };

  public:
    Result(Ok<T> ok_v) : m_is_ok(true) { new (&m_ok_value) T(std::move(ok_v.get_value())); }

    Result(Err<E> err_v) : m_is_ok(false) { new (&m_err_value) E(std::move(err_v.get_value())); }

    Result(const Result &other) : m_is_ok(other.m_is_ok) {
        if (m_is_ok) {
            new (&m_ok_value) T(other.m_ok_value);
        } else {
            new (&m_err_value) E(other.m_err_value);
        }
    }

    Result(Result &&other) : m_is_ok(other.m_is_ok) {
        if (m_is_ok) {
            new (&m_ok_value) T(std::move(other.m_ok_value));
        } else {
            new (&m_err_value) E(std::move(other.m_err_value));
        }
    }

    auto operator=(const Result &other) -> Result & {
        if (this != &other) {
            if (m_is_ok) {
                m_ok_value.~T();
            } else {
                m_err_value.~E();
            }

            m_is_ok = other.m_is_ok;

            if (m_is_ok) {
                new (&m_ok_value) T(other.m_ok_value);
            } else {
                new (&m_err_value) E(other.m_err_value);
            }
        }

        return *this;
    }

    auto operator=(Result &&other) noexcept -> Result & {
        if (this != &other) {
            if (m_is_ok) {
                m_ok_value.~T();
            } else {
                m_err_value.~E();
            }

            m_is_ok = other.m_is_ok;

            if (m_is_ok) {
                new (&m_ok_value) T(std::move(other.m_ok_value));
            } else {
                new (&m_err_value) E(std::move(other.m_err_value));
            }
        }

        return *this;
    }

    ~Result() {
        if (m_is_ok) {
            m_ok_value.~T();
        } else {
            m_err_value.~E();
        }
    }

    [[nodiscard]] auto is_ok() const -> bool { return m_is_ok; }
    [[nodiscard]] auto is_err() const -> bool { return !m_is_ok; }

    auto unwrap() const -> const T & {
        if (!m_is_ok) {
            std::cerr << "Called `Result::unwrap()` on an `Err` value: " << m_err_value << "\n";
            std::abort();
        }

        return m_ok_value;
    }

    auto unwrap_err() const -> const E & {
        if (m_is_ok) {
            std::cerr << "Called `Result::unwrap_err()` on an `Ok` value: " << m_ok_value << "\n";
            std::abort();
        }

        return m_err_value;
    }

    auto unwrap_or(const T &default_v) const -> T { return m_is_ok ? m_ok_value : default_v; }

    template <typename FnType> auto unwrap_or_else(FnType func) const -> T {
        if (!m_is_ok) { func(m_err_value); }
        return m_ok_value;
    }

    template <typename OkFn, typename ErrFn>
    auto match(OkFn ok_func, ErrFn err_func) const -> void {
        if (!m_is_ok) {
            err_func(m_err_value);
            return;
        }

        ok_func(m_ok_value);
    }

    template <typename Fn>
    auto map_err(Fn func) const -> Result<T, decltype(func(std::declval<E>()))> {
        if (is_err()) { return Err<decltype(func(std::declval<E>()))>(func(m_err_value)); }
        return Ok<T>(m_ok_value);
    }

    auto expect(const std::string &message) const -> const T & {
        if (!m_is_ok) {
            std::cerr << message << "\n";
            std::exit(1);
        }

        return m_ok_value;
    }
};
