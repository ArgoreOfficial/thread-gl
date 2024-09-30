workspace "thread-gl"
	configurations { "Debug", "Release" }
	platforms { "x64", "x86" }
	location "../../"
	startproject "thread-gl"

	flags { "MultiProcessorCompile" }

project "thread-gl"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir "../../bin"
	objdir "../../bin/obj/"

	location "../../build"

	includedirs { "../../libs/glad/include/" }

	files { 
		"../../src/thread-gl/**.h", 
		"../../src/thread-gl/**.cpp" 
	}

project "testbed"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir "../../bin"
	objdir "../../bin/obj/"
	
	location "../../build"

	includedirs { 
		"../../include/", 
		"../../libs/glad/include/", 
		"../../libs/glfw/include/"
	}

	files { 
		"../../src/test/**.h", 
		"../../src/test/**.cpp" 
	}

	links { "GLFW", "GLAD" }

include "../../libs/glfw.lua"
include "../../libs/glad.lua"