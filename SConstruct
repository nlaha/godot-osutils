#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "game/addons/godot-osutils/bin/libgodotosutils.{}.{}.framework/libgodotosutils.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "game/addons/godot-osutils/bin/libgodotosutils{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

# link Advapi32.lib and Secur32 on Windows
if env["platform"] == "windows":
    env.Append(LIBS=["Advapi32", "Secur32"])

Default(library)
