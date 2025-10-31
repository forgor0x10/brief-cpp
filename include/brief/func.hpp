#pragma once

#include <vector>

template <typename T, typename F> auto map(const std::vector<T> &container, F &&func) {
    using U = decltype(func(container.front()));
    std::vector<U> result;
    result.reserve(container.size());

    for (const auto &element : container) {
        result.push_back(func(element));
    }

    return result;
}

template <typename T, typename F> auto filter(const std::vector<T> &container, F &&func) {
    std::vector<T> result;

    for (const auto &element : container) {
        if (func(element)) { result.push_back(element); }
    }

    return result;
}

template <typename T, typename U, typename F>
auto reduce(const std::vector<T> &container, U init, F &&func) {
    for (const auto &element : container) {
        init = func(init, element);
    }

    return init;
}

template <typename T, typename F> void for_each(const std::vector<T> &container, F &&func) {
    for (const auto &element : container) {
        func(element);
    }
}

template <typename T, typename F> void map_in_place(std::vector<T> &container, F &&func) {
    for (auto &element : container) {
        element = func(element);
    }
}
