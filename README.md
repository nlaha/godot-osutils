# Godot OSUtils

Godot OSUtils is a helper addon that fetches various information about the user and the OS.

## Example Usage

```gdscript
func _ready():
	osutils = OsUtils.new()
	
	print("Name: " + osutils.user_full_name)
    print("Is SteamDeck? " + str(osutils.is_steam_deck))
    print("OS Type: " + osutils.os_type)
```