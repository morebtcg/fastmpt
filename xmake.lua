set_config("cxxflags", "-Wall -g -std=c++17")

target("console")
    set_kind("binary")
    set_toolchains("clang", "yasm")
    add_includedirs("./")
    add_files("console/*.cpp")
