add_rules("mode.debug", "mode.release")

add_requires("lua", "sol2")

add_requires("spdlog")

add_requires("glm")

add_requires("stb")

add_requires("wgpu-native", "glfw3webgpu")

add_requires("glfw")

set_policy("build.warning", true) -- show warnings
set_warnings("all") -- warn about many things

target("helloworld")
    set_kind("binary")
    set_languages("cxx17")
    
    add_deps("GaemEngine")
    set_rundir("$(projectdir)")

    add_files("demo/helloworld.cpp")

target("GaemEngine")
    set_kind("static")
    set_languages("cxx20")

    -- Declare our engine's header path.
    -- This allows targets that depend on the engine to #include them.
    add_includedirs("src", {public = true})
    
    -- Add all .cpp files in the `src` directory.
    add_files("src/*.cpp")

    add_packages("sol2", {public = true})
    add_packages("lua")
    add_packages("stb")
    add_packages("glm", {public = true})
    add_packages("spdlog")
    add_packages("glfw", {public = true})
    add_packages("wgpu-native", "glfw3webgpu", {public = true})