#pragma once

#include <iostream>

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
