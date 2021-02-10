set_config("cxxflags", "-Wall -g")

target("console")
    set_kind("binary")
    add_includedirs("./")
    add_files("console/*.cpp")