#include <iostream>
#include <String>

using namespace std;

//this needs to be changed to the sdl version instead of windows version

int LoadAudio(const char * filename)
{
	int handle = 1; //change later

	//has to load the 5 audio files, -sounds when brick, if the player has died, bounced from the player and wall same sound, destroyed brick, the ball being shot.
		
	// this would be a reference to a memory handle or index, loads wav files

//C:\Users\Norco College\Desktop\audio file  | replace the *wav. with the address PlaySound("*.wav", GetModuleHandle(NULL), SND_FILENAME); this was for windows audio version replace this with the sdl version

	return handle; // test?
}

	


void PlayAudio(int handle) 
{
	//this will play the loaded audio file when called upon
	cout << "this should play some audio";
}

// test program 

class GameState {
public:
	float player_x, player_y;
};


int main()
{
	GameState gamestate;
	
	bool isDead = false, gameCompletion = false;
	int lives = 3;
	// double lastTime = getCurrentTime();
	do
	{
		//double current = getCurrentTime(); these two functions will keep the game from running to slowly or to quickly between frames of the ball and player moving
		//double elapsed = current - lastTime;
		// processInput(); this function will process user input calls on sub system user input functions -user input(player movement, ball being shot)
		// update(elasped); this funtion should update the input to the system 
		// render(); this should update the system to the screen the ball moving across the screen the player see's this
		//lastTime = current;

		update(&gamestate);

		draw(&gamestate);

	} while (isDead == false || gameCompletion == false);

	system("PAUSE");

}