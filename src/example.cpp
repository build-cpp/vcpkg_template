#include <cstdio>
#include <fmt/format.h>
#include <sqlite3.h>

int main()
{
    fmt::print("SQLite version: {}\n", sqlite3_libversion());
}