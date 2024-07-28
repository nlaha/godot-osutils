#ifndef OSUTILS_REGISTER_TYPES_H
#define OSUTILS_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_osutils_module(ModuleInitializationLevel p_level);
void uninitialize_osutils_module(ModuleInitializationLevel p_level);

#endif // OSUTILS_REGISTER_TYPES_H