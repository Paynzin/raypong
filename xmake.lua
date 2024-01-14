add_rules("mode.debug", "mode.release")
add_requires("raylib")

if is_plat("windows", "msys", "mingw") then
    set_config("ldflags", "-mwindows")
    set_config("cflags", "-Wl,--subsystem,windows")
    add_rules("win.sdk.application")
end

target("raypong")
    set_kind("binary")
    add_files("src/*.c")
    add_packages("raylib")

