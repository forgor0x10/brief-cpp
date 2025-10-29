<h1 align="center">brief-cpp</h1>
<p align="center">
    <img src="https://img.shields.io/badge/C%2B%2B-17-b4befe?style=for-the-badge&labelColor=1e1e2e" />
    <img src="https://img.shields.io/badge/license-MIT-a6e3a1?style=for-the-badge&labelColor=1e1e2e" />
    <img src="https://img.shields.io/badge/version-1.0.0-fab387?style=for-the-badge&labelColor=1e1e2e" />
</p>

A lightweight, zero-overhead C++17 utility header with aliases and helper macros inspired by modern languages like **Python** and **Rust**

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
    let name = String("World");
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

## Installation

Simply clone the repo and run `install.sh`:

```bash
git clone https://github.com/forgor0x10/brief-cpp.git
cd brief-cpp
./install.sh
```

Then include it in your source:

```cpp
#include <brief/brief.hpp>
```
