#include <cstdlib>

#include <brief/aliases.hpp>
#include <brief/io.hpp>
#include <brief/result.hpp>

// For read_line()
// It's possible to use io as brief::io without this statement
use(io);

namespace {
fn prompt_str() -> Result<String, String> {
    mut input = String();

    // etry() - Expression try
    // Will propagate the error on Err
    etry(io::cin().read_line(&input).map_err(
        [](String err) { return "Error processing input: " + err; }));

    return Ok(input);
}

fn prompt_i32() -> Result<i32, String> {
    mut num = i32(0);

    // atry() - Assignment try
    // Same as etry(), but will also return the value on Ok
    let input = atry(prompt_str());

    mut stream = StrStream(input);
    if (!(stream >> num)) { return Err("Error converting '" + input + "' to i32"); }

    return Ok(num);
}

fn do_operation(const i32 x_v, const i32 y_v, const String operation) -> Result<i32, String> {
    if (operation == "+") { return Ok(x_v + y_v); }
    if (operation == "-") { return Ok(x_v - y_v); }
    if (operation == "*") { return Ok(x_v * y_v); }
    if (operation == "/") { return Ok(x_v / y_v); }
    if (operation == "%") { return Ok(x_v % y_v); }

    return Err("Unknown operation '" + operation + "'");
}

template <typename T, typename E> fn handle(Result<T, E> result) -> T {
    if (result.is_err()) {
        eprintln("The calculator exploded");
        eprintln("  " + result.unwrap_err());
        std::exit(1);
    }

    return result.unwrap();
}

template <typename T, typename F> fn get_input(const str &message, F func) -> T {
    print(message);
    return handle(func());
}
} // namespace

fn main() {
    let nums = Vec<i32>({
        get_input<i32>("Enter x: ", prompt_i32),
        get_input<i32>("Enter y: ", prompt_i32),
    });

    let operation = get_input<String>("Enter operation: ", prompt_str);
    let result = handle(do_operation(nums[0], nums[1], operation));

    println("x " + operation + " y = ", result);
}
