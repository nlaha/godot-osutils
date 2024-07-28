#ifndef OSUTILS_H
#define OSUTILS_H

#ifdef __linux__
    #include <unistd.h>
    #include <pwd.h>
#elif _WIN32
    #include <windows.h>
    #include <Lmcons.h>
    #include <WinBase.h>
    #define SECURITY_WIN32
    #include <Security.h>
#else
    #error "Unknown compiler"
#endif

#include <godot_cpp/classes/ref.hpp>

namespace godot {

class OsUtils : public RefCounted {
    GDCLASS(OsUtils, RefCounted);

protected:
	static void _bind_methods();
    
    String user_full_name;
    bool is_steam_deck;
    String os_type;

public:
	OsUtils();
	~OsUtils();

    String get_user_full_name() const { return user_full_name; }
    void set_user_full_name(const String &p_user_full_name) { user_full_name = p_user_full_name; }

    bool get_is_steam_deck() const { return is_steam_deck; }

    String get_os_type() const { return os_type; }
};

}

#endif