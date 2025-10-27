/*
 * brief.hpp
 * A tiny C++17 header to make your code feel modern and effortless
 *
 * Copyright (c) 2025 forgor0x10
 *
 * Licensed under the MIT License
 * See the LICENSE file in the project root for details
 * https://github.com/forgor0x10/brief-cpp
 */

#pragma once

#include <cstdint>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

#define fn auto
#define let const auto
#define mut auto
#define in :

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using f32 = float;
using f64 = double;

using str = std::string_view;
using String = std::string;
using WString = std::wstring;
using U16String = std::u16string;
using U32String = std::u32string;

template <typename T> using Vec = std::vector<T>;
template <typename T> using List = std::list<T>;
template <typename T> using Deque = std::deque<T>;
template <typename T, std::size_t N> using Array = std::array<T, N>;
template <typename T> using Set = std::set<T>;
template <typename T> using USet = std::unordered_set<T>;
template <typename Key, typename Value> using Map = std::map<Key, Value>;
template <typename Key, typename Value> using UMap = std::unordered_map<Key, Value>;
template <typename T> using Stack = std::stack<T>;
template <typename T> using Queue = std::queue<T>;
template <typename T> using PQueue = std::priority_queue<T>;
template <typename T1, typename T2> using Pair = std::pair<T1, T2>;
template <typename... Args> using Tuple = std::tuple<Args...>;
template <typename T> using SharedPtr = std::shared_ptr<T>;
template <typename T> using UniquePtr = std::unique_ptr<T>;
template <typename T> using WeakPtr = std::weak_ptr<T>;
template <typename T> using Optional = std::optional<T>;
template <typename... Args> using Variant = std::variant<Args...>;

inline constexpr std::nullopt_t none = std::nullopt;

template <typename T, typename... Args>
inline auto make_shared(Args &&...args) -> std::shared_ptr<T> {
    return std::make_shared<T>(std::forward<Args>(args)...);
}

template <typename T, typename... Args>
inline auto make_unique(Args &&...args) -> std::unique_ptr<T> {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename... Args> inline void print(Args... args) { ((std::cout << args), ...); }

inline void println() { std::cout << "\n"; }

template <typename... Args> inline void println(Args... args) {
    ((std::cout << args), ...) << "\n";
}

template <typename... Args> inline void eprint(Args... args) { ((std::cerr << args), ...); }

inline void eprintln() { std::cerr << "\n"; }

template <typename... Args> inline void eprintln(Args... args) {
    ((std::cerr << args), ...) << "\n";
}
