#include <fmt/format.h>
#include <sqlite3.h>
#include <mylib/version.hpp>
#include <mylib/stringutils.hpp>

int main()
{
    fmt::print("SQLite version: {} (DBSTAT={}, JSON1={})\n",
        sqlite3_libversion(),
        sqlite3_compileoption_used("SQLITE_ENABLE_DBSTAT_VTAB"),
        sqlite3_compileoption_used("SQLITE_ENABLE_JSON1")
    );

    fmt::print("{} version: {}\n", mylib::reverse("bilym"), mylib::version());
}
