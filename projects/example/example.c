#include "types.h"
#include "constants.h"
#include "intrinsics.h"
#include "natives.h"
#include "common.h"

void main_loop()
{
	while (true)
	{
		//ton code ici

		WAIT(0);
	}
}

void start_script(int scriptID, char* scriptName) //démarer le script pour pouvoir l'utiliser dans le jeu
{
	if (IS_SCRIPT_VALID(scriptID))
	{
		STREAMING_REQUEST_SCRIPT(scriptID); //on demande d'éxecuter le script

		while (!STREAMING_IS_SCRIPT_LOADED(scriptID))
		{
			WAIT(0);
		}

		if (STREAMING_IS_SCRIPT_LOADED(scriptID)) //quand il est chargé
		{
			if (scriptName != "")
			{
				START_NEW_SCRIPT(scriptName, 0);
			}
			else {
				START_NEW_SCRIPT(GET_SCRIPT_NAME(), 0); //je ne connais pas vraiment le 2ème paramètre
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
			if (DOES_SCRIPT_EXIST("$/content/release/scripting/designerdefined/ui/fuieventmonitor.csc")) //script d'affichage
			{
				LAUNCH_NEW_SCRIPT("$/content/release/scripting/designerdefined/ui/fuieventmonitor.csc", 0);
				start_script(scriptID, "");
				main_loop(); //on passe à notre boucle principale
			}
		}
	}
}
