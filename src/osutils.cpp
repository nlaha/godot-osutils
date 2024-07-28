#include "osutils.h"

using namespace godot;

void OsUtils::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_user_full_name"), &OsUtils::get_user_full_name);
    ClassDB::bind_method(D_METHOD("set_user_full_name", "user_full_name"), &OsUtils::set_user_full_name);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "user_full_name"), "set_user_full_name", "get_user_full_name");

    ClassDB::bind_method(D_METHOD("get_is_steam_deck"), &OsUtils::get_is_steam_deck);
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "is_steam_deck"), "", "get_is_steam_deck");

    ClassDB::bind_method(D_METHOD("get_os_type"), &OsUtils::get_os_type);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "os_type"), "", "get_os_type");
}

/// @brief Constructor
OsUtils::OsUtils() {
    
    // initialize default values
    this->is_steam_deck = false;
    this->user_full_name = "Unknown";
    this->os_type = "Unknown";

#ifdef __linux__
    this->os_type = "Linux";
    char *lgn;
    struct passwd *pw;

    if ((lgn = getlogin()) == NULL || (pw = getpwnam(lgn)) == NULL) {
        this->user_full_name = "Unknown";
    }
    else {
        this->user_full_name = pw->pw_gecos;
        if (this->user_full_name == "Steam Deck User")
        {
            // we're running on a Steam Deck so the user's name is always "Steam Deck User"
            this->user_full_name = "Unknown";
            this->is_steam_deck = true;
        }
    }
#elif _WIN32
    this->os_type = "Windows";
    // ULEN + 1 is the maximum length of a user's name in windows
    TCHAR name [ UNLEN + 1 ];
    DWORD size = UNLEN + 1;

    if (GetUserNameEx(EXTENDED_NAME_FORMAT::NameDisplay, (TCHAR*)name, &size ))
    {
        this->user_full_name = name;
    }
    else
    {
        this->user_full_name = "Unknown";
    }
#endif
}

/// @brief Destructor
OsUtils::~OsUtils() {
}
