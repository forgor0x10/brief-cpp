#pragma once

#include <chrono>
#include <cstdint>
#include <deque>
#include <filesystem>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <queue>
#include <ratio>
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

#define main(...) main(__VA_ARGS__)->int

#define use(x) namespace x = brief::x;

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

template <typename T> using Stack = std::stack<T>;
template <typename T> using Queue = std::queue<T>;
template <typename T> using PQueue = std::priority_queue<T>;

template <typename T> using Set = std::set<T>;
template <typename T> using USet = std::unordered_set<T>;
template <typename K, typename V> using Map = std::map<K, V>;
template <typename K, typename V> using UMap = std::unordered_map<K, V>;

template <typename T1, typename T2> using Pair = std::pair<T1, T2>;
template <typename... Args> using Tuple = std::tuple<Args...>;
template <typename... Args> using Variant = std::variant<Args...>;
template <typename T> using Optional = std::optional<T>;

template <typename T> using SharedPtr = std::shared_ptr<T>;
template <typename T> using UniquePtr = std::unique_ptr<T>;
template <typename T> using WeakPtr = std::weak_ptr<T>;

using StrStream = std::stringstream;
using IStrStream = std::istringstream;
using OStrStream = std::ostringstream;

using FileStream = std::fstream;
using IFileStream = std::ifstream;
using OFileStream = std::ofstream;

using Mutex = std::mutex;
using LockGuard = std::lock_guard<Mutex>;
using UniqueLock = std::unique_lock<Mutex>;

using std::cerr;
using std::cout;
using std::nullopt;

using std::endl;

using std::make_shared;
using std::make_unique;

using std::forward;
using std::move;
using std::swap;

namespace chr {
template <typename Rep, typename Period> using Duration = std::chrono::duration<Rep, Period>;

using Nanoseconds = std::chrono::nanoseconds;
using Microseconds = std::chrono::microseconds;
using Milliseconds = std::chrono::milliseconds;
using Seconds = std::chrono::seconds;
using Minutes = std::chrono::minutes;
using Hours = std::chrono::hours;

using SteadyClock = std::chrono::steady_clock;
using SystemClock = std::chrono::system_clock;
} // namespace chr

namespace fs {
using Path = std::filesystem::path;
using DirEntry = std::filesystem::directory_entry;
using DirIter = std::filesystem::directory_iterator;
using RecDirIter = std::filesystem::recursive_directory_iterator;

using FileStatus = std::filesystem::file_status;
using FileType = std::filesystem::file_type;
using Perms = std::filesystem::perms;
using SpaceInfo = std::filesystem::space_info;

using DirOptions = std::filesystem::directory_options;
using CopyOptions = std::filesystem::copy_options;
using FileTime = std::filesystem::file_time_type;
} // namespace fs
