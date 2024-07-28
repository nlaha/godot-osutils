extends Label

var osutils: OsUtils

# Called when the node enters the scene tree for the first time.
func _ready():
	osutils = OsUtils.new()
	
	text = "Name: " + osutils.user_full_name

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
