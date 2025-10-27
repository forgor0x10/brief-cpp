<h1 align="center">brief-cpp</h1>

A lightweight, zero-overhead C++17 utility header providing aliases and helper macros inspired by modern languages like **Python** and **Rust**

## Features

- Type aliases (`i32`, `u64`, `str`, etc.)
- Container aliases (`Vec<T>`, `Map<K, V>`)
- Utility macros (`fn`, `let`, `mut`)
- Print helpers (`print`, `println`, `eprint`)
- Header-only, no dependencies

## Example

```cpp
#include <brief/brief.hpp>

fn main() -> i32 {
    let name = "World";
    println("Hello, ", name, "!");

    let nums = Vec<i32>({1, 2, 3, 4, 5});
    for (let num in nums) { print(num, " "); }
    println();

    let maybe = Optional<i32>(42);
    if (maybe) {
        println("Value: ", maybe.value());
    } else {
        println("None");
    }

    return 0;
}
```

## Supported Compilers

- GCC ≥ 7.0
- Clang ≥ 6.0
- MSVC ≥ 2019 (v16.0)

All supporting **C++17**

## Installation

Simply drop `brief.hpp` into your include path:

```bash
git clone https://github.com/forgor0x10/brief-cpp.git
```

Then include it in your source:

```cpp
#include <brief/brief.hpp>
```

No build system integration needed - it's header-only
