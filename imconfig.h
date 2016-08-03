//-----------------------------------------------------------------------------
// USER IMPLEMENTATION
// This file contains compile-time options for ImGui.
// Other options (memory allocation overrides, callbacks, etc.) can be set at runtime via the ImGuiIO structure - ImGui::GetIO().
//-----------------------------------------------------------------------------

#pragma once

#include "Math/Vector2.h"
#include "Math/Vector4.h"

//---- Define assertion handler. Defaults to calling assert().
//#define IM_ASSERT(_EXPR)  MyAssert(_EXPR)

//---- Define attributes of all API symbols declarations, e.g. for DLL under Windows.
//#define IMGUI_API __declspec( dllexport )
//#define IMGUI_API __declspec( dllimport )

#ifndef _WIN32
    #define IMGUI_API
#endif

#ifndef IMGUI_API
    #define IMGUI_API __declspec( dllexport )
#else
    #undef IMGUI_API
    #define IMGUI_API
#endif

#define IMGUI_USE_MUSASHI 1
#if IMGUI_USE_MUSASHI
namespace Musashi
{
    class Engine;
}

void MusaImGui_RefTexture2D( void* userTexture );

#endif

//---- Include imgui_user.h at the end of imgui.h
//#define IMGUI_INCLUDE_IMGUI_USER_H

//---- Don't implement default handlers for Windows (so as not to link with OpenClipboard() and others Win32 functions)
//#define IMGUI_DISABLE_WIN32_DEFAULT_CLIPBOARD_FUNCS
//#define IMGUI_DISABLE_WIN32_DEFAULT_IME_FUNCS

//---- Don't implement help and test window functionality (ShowUserGuide()/ShowStyleEditor()/ShowTestWindow() methods will be empty)
//#define IMGUI_DISABLE_TEST_WINDOWS

//---- Don't define obsolete functions names
//#define IMGUI_DISABLE_OBSOLETE_FUNCTIONS

//---- Implement STB libraries in a namespace to avoid conflicts
//#define IMGUI_STB_NAMESPACE     ImGuiStb

//---- Define constructor and implicit cast operators to convert back<>forth from your math types and ImVec2/ImVec4.
#define IM_VEC2_CLASS_EXTRA                                                 \
        ImVec2(const ::CoreMath::Vector2& f) { x = f.x; y = f.y; }                       \
        operator ::CoreMath::Vector2() const { return ::CoreMath::Vector2::C(x,y); }

#define IM_VEC4_CLASS_EXTRA                                                 \
        ImVec4(const ::CoreMath::Vector4& f) { x = f.x; y = f.y; z = f.z; w = f.w; }     \
        operator ::CoreMath::Vector4() const { return ::CoreMath::Vector4::C(x,y,z,w); }
/*
*/

//---- Tip: You can add extra functions within the ImGui:: namespace, here or in your own headers files.
//---- e.g. create variants of the ImGui::Value() helper for your low-level math types, or your own widgets/helpers.
/*
namespace ImGui
{
    void    Value(const char* prefix, const MyMatrix44& v, const char* float_format = NULL);
}
*/

