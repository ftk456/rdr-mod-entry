#include "types.h"
#include "constants.h"
#include "intrinsics.h"
#include "natives.h"
#include "common.h"

void main_loop()
{
	while (true)
	{
		//your code

		WAIT(0);
	}
}

void start_script(int scriptID, char* scriptName)
{
	if (IS_SCRIPT_VALID(scriptID))
	{
		STREAMING_REQUEST_SCRIPT(scriptID);

		while (!STREAMING_IS_SCRIPT_LOADED(scriptID))
		{
			WAIT(0);
		}

		if (STREAMING_IS_SCRIPT_LOADED(scriptID))
		{
			if (scriptName != "")
			{
				START_NEW_SCRIPT(scriptName, 0);
			}
			else {
				START_NEW_SCRIPT(GET_SCRIPT_NAME(), 0);
			}
		}
	}
}

void main()
{
	int scriptID = _GET_ID_OF_THIS_SCRIPT();
	if (IS_PLAYER_CONTROLLABLE(0) == 1)
	{
		if (!IS_GAME_PAUSED())
		{
			if (DOES_SCRIPT_EXIST("$/content/release/scripting/designerdefined/ui/fuieventmonitor.csc"))
			{
				LAUNCH_NEW_SCRIPT("$/content/release/scripting/designerdefined/ui/fuieventmonitor.csc", 0);
				start_script(scriptID, "");
				main_loop();
			}
		}
	}
}