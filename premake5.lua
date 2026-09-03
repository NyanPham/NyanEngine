workspace "NyanEngine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "NyanEngine"
   location "NyanEngine"
   kind "SharedLib"
   language "C++"
   cppdialect "C++17"
   staticruntime "Off"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp"
   }

   defines {
      "NYAN_PLATFORM_WINDOWS",
      "NYAN_BUILD_DLL"
   }

   filter "configurations:Debug"
      defines "NYAN_DEBUG"
      symbols "On"

   filter "configurations:Release"
      defines "NYAN_RELEASE"
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
      "NyanEngine/src"
   }

   links {
      "NyanEngine"
   }

   defines {
      "NYAN_PLATFORM_WINDOWS"
   }

   filter "configurations:Debug"
      defines "NYAN_DEBUG"
      symbols "On"

   filter "configurations:Release"
      defines "NYAN_RELEASE"
      optimize "On"