workspace "NyanEngine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "NyanEngine/vendor/GLFW/include"

include "NyanEngine/vendor/GLFW"

project "NyanEngine"
   location "NyanEngine"
   kind "SharedLib"
   language "C++"
   cppdialect "C++17"
   staticruntime "Off"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   pchheader "nyanpch.h"
   pchsource "NyanEngine/src/nyanpch.cpp"

   files {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
   }

   includedirs {
      "%{prj.name}/src",
      "%{prj.name}/vendor/spdlog/include",
      "%{IncludeDir.GLFW}"
   }
   
   links 
	{ 
		"GLFW",
		"opengl32",
      "gdi32"
	}

   filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"

      defines {
         "NYAN_PLATFORM_WINDOWS",
         "NYAN_BUILD_DLL"
      }

      postbuildcommands
      {
         ("if not exist \"../bin/" .. outputdir .. "/Sandbox\" mkdir \"../bin/" .. outputdir .. "/Sandbox\""),         
         ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
      }

   filter "configurations:Debug"
      defines "NYAN_DEBUG"
      symbols "On"

   filter "configurations:Release"
      defines "NYAN_RELEASE"
      optimize "On"

   filter "configurations:Dist"
      defines "NYAN_DIST"
      optimize "On"

project "Sandbox"
   location "Sandbox"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "Off"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
   }

   includedirs {
      "NyanEngine/src",
      "NyanEngine/vendor/spdlog/include"
   }

   links {
      "NyanEngine"
   }

   filter "system:windows"
      cppdialect "C++17"
      staticruntime "On"
      systemversion "latest"

      defines {
         "NYAN_PLATFORM_WINDOWS"
      }

   filter "configurations:Debug"
      defines "NYAN_DEBUG"
      symbols "On"

   filter "configurations:Release"
      defines "NYAN_RELEASE"
      optimize "On"

   filter "configurations:Dist"
      defines "NYAN_DIST"
      optimize "On"