set(HOOKS_SRC
    DInputHook.hpp
    DInputHook.cpp
    D3D11Hook.hpp
    D3D11Hook.cpp
    D3D12Hook.hpp
    D3D12Hook.cpp
    WindowsMessageHook.hpp
    WindowsMessageHook.cpp
    PositionHooks.hpp
    PositionHooks.cpp
)

set(MODS_SRC
    DeveloperTools.hpp
    DeveloperTools.cpp
	ObjectExplorer.hpp
    ObjectExplorer.cpp
	IntegrityCheckBypass.hpp
	IntegrityCheckBypass.cpp
	Speedrun.h
	Speedrun.cpp
)

set(SDK_SRC
    sdk/ReClass.hpp
    sdk/ReClass_Internal.hpp
    sdk/ReClass_Internal_RE3.hpp
    sdk/Enums_Internal.hpp

    sdk/REArray.hpp
    sdk/REComponent.hpp
    sdk/REContext.hpp
    sdk/REContext.cpp
    sdk/REGlobals.hpp
    sdk/REGlobals.cpp
    sdk/REManagedObject.hpp
    sdk/REMath.hpp
    sdk/REString.hpp
    sdk/RETransform.hpp
    sdk/RETypes.hpp
    sdk/RETypes.cpp
    sdk/RopewaySweetLightManager.hpp
)

set(RE2IMGUI_SRC
    re2-imgui/imgui_impl_win32.h
    re2-imgui/imgui_impl_win32.cpp
    re2-imgui/imgui_impl_dx11.h
    re2-imgui/imgui_impl_dx11.cpp
)

set(UTILITY_SRC
    utility/Address.hpp
    utility/Address.cpp
    utility/Config.hpp
    utility/Config.cpp
    utility/FunctionHook.hpp
    utility/FunctionHook.cpp
    utility/Memory.hpp
    utility/Memory.cpp
    utility/Module.hpp
    utility/Module.cpp
    utility/Patch.hpp
    utility/Patch.cpp
    utility/Pattern.hpp
    utility/Pattern.cpp
    utility/Scan.hpp
    utility/Scan.cpp
    utility/String.hpp
    utility/String.cpp
	utility/DroidFont.cpp
)

set(FRAMEWORK_SRC
    Mod.hpp
    Mods.hpp
    Mods.cpp
    REFramework.hpp
    REFramework.cpp
	#		RenderHook.h
	#		D3D12Hook.cpp
	#		D3D12Hook.h
)

source_group("re2-imgui" FILES ${RE2IMGUI_SRC})
source_group("Hooks" FILES ${HOOKS_SRC})
source_group("Mods" FILES ${MODS_SRC})
source_group("SDK" FILES ${SDK_SRC})
source_group("Utility" FILES ${UTILITY_SRC})
source_group("Framework" FILES ${FRAMEWORK_SRC})

add_library(RE2 SHARED
            Main.cpp
            LicenseStrings.hpp
            ${SDK_SRC}
            ${MODS_SRC}
            ${HOOKS_SRC}
            ${RE2IMGUI_SRC}
            ${UTILITY_SRC}
            ${FRAMEWORK_SRC}
)

target_link_libraries(RE2 PUBLIC imgui minhook d3d11 glm_static shlwapi)
target_compile_options(RE2 PUBLIC /GS /GR /EHa)
target_compile_features(RE2 PUBLIC cxx_std_17)

include_directories(RE2 ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(RE2 PROPERTIES OUTPUT_NAME dinput8)

string(REGEX REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
option(DEVELOPER_MODE "Adds DeveloperTools option to menu" OFF)
option(RE3 "RE3 build" OFF)

if(DEVELOPER_MODE)
	target_compile_definitions(RE2 PUBLIC DEVELOPER)
    target_compile_options(RE2 PUBLIC /EHa)
endif()

if (RE3)
    target_compile_definitions(RE2 PUBLIC RE3)
endif()