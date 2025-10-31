#pragma once

#include <iostream>

#include "result.hpp"

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

namespace brief::io {
class Cin {
  public:
    auto read_line(std::string *str) const -> Result<unsigned long long, std::string> {
        (void)this;

        if (!std::getline(std::cin, *str)) {
            if (std::cin.bad()) { return Err(std::string("I/O failure (badbit)")); }
            if (std::cin.fail()) { return Err(std::string("Extraction error (failbit)")); }
            if (std::cin.eof()) { return Err(std::string("End of file error (eofbit)")); }
        }

        return Ok((*str).length());
    };
};

inline auto cin() -> Cin { return {}; }
} // namespace brief::io
