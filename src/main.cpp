#include <fmt/format.h>
#include <sqlite3.h>
#include <mylib/version.hpp>
#include <mylib/stringutils.hpp>

int main()
{
    fmt::print("SQLite version: {}\n", sqlite3_libversion());
    fmt::print("{} version: {}\n", mylib::reverse("bilym"), mylib::version());
}