add_rules("mode.debug", "mode.release")
add_requires("raylib")

target("raypong")
    set_kind("binary")
    add_files("src/*.c")
    add_packages("raylib")
