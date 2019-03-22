#include <allegro.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



#define MENU 20
#define GAME 30
#define LOAD 40
#define FINAL_LEVEL 45
#define DESTROY 50

void music_play(int menu_game_option, int load_destroy_option, MIDI *music);
int init();
void deinit();

void music_play(int menu_game_option, int load_destroy_option, MIDI *music)
{
	int random_music;
	if(load_destroy_option == LOAD)
	{
		if(menu_game_option==MENU)
		{
			random_music = rand()%19;
			if(random_music==0)
			{
				music = load_midi("music\\menu_music\\menu_music0.mid");
			}

			if(random_music==1)
			{
				music = load_midi("music\\menu_music\\menu_music1.mid");
			}

			if(random_music==2)
			{
				music = load_midi("music\\menu_music\\menu_music2.mid");
			}
			if(random_music==3)
			{
				music = load_midi("music\\menu_music\\menu_music3.mid");
			}
			if(random_music==4)
			{
				music = load_midi("music\\menu_music\\menu_music4.mid");
			}
			if(random_music==5)
			{
				music = load_midi("music\\menu_music\\menu_music5.mid");
			}
			if(random_music==6)
			{
				music = load_midi("music\\menu_music\\menu_music6.mid");
			}
			if(random_music==7)
			{
				music = load_midi("music\\menu_music\\menu_music7.mid");
			}
			if(random_music==8)
			{
				music = load_midi("music\\menu_music\\menu_music8.mid");
			}
			if(random_music==9)
			{
				music = load_midi("music\\menu_music\\menu_music9.mid");
			}
			if(random_music==10)
			{
				music = load_midi("music\\menu_music\\menu_music10.mid");
			}
			if(random_music==11)
			{
				music = load_midi("music\\menu_music\\menu_music11.mid");
			}
			if(random_music==12)
			{
				music = load_midi("music\\menu_music\\menu_music12.mid");
			}
			if(random_music==13)
			{
				music = load_midi("music\\menu_music\\menu_music13.mid");
			}
			if(random_music==14)
			{
				music = load_midi("music\\menu_music\\menu_music14.mid");
			}
			if(random_music==15)
			{
				music = load_midi("music\\menu_music\\menu_music15.mid");
			}
			if(random_music==16)
			{
				music = load_midi("music\\menu_music\\menu_music16.mid");
			}
			if(random_music==17)
			{
				music = load_midi("music\\menu_music\\menu_music17.mid");
			}
			if(random_music==18)
			{
				music = load_midi("music\\menu_music\\menu_music18.mid");
			}
			if(random_music==19)
			{
				music = load_midi("music\\menu_music\\menu_music19.mid");
			}
			play_midi(music,TRUE);
		}
		if(menu_game_option==GAME)
		{
			random_music = rand()%13;
			if(random_music==0)
			{
				music = load_midi("music\\game_music\\game_music0.mid");
			}

			if(random_music==1)
			{
				music = load_midi("music\\game_music\\game_music1.mid");
			}

			if(random_music==2)
			{
				music = load_midi("music\\game_music\\game_music2.mid");
			}
			if(random_music==3)
			{
				music = load_midi("music\\game_music\\game_music3.mid");
			}
			if(random_music==4)
			{
				music = load_midi("music\\game_music\\game_music4.mid");
			}
			if(random_music==5)
			{
				music = load_midi("music\\game_music\\game_music5.mid");
			}
			if(random_music==6)
			{
				music = load_midi("music\\game_music\\game_music6.mid");
			}
			if(random_music==7)
			{
				music = load_midi("music\\game_music\\game_music7.mid");
			}
			if(random_music==8)
			{
				music = load_midi("music\\game_music\\game_music8.mid");
			}
			if(random_music==9)
			{
				music = load_midi("music\\game_music\\game_music9.mid");
			}
			if(random_music==10)
			{
				music = load_midi("music\\game_music\\game_music10.mid");
			}
			if(random_music==11)
			{
				music = load_midi("music\\game_music\\game_music11.mid");
			}
			if(random_music==12)
			{
				music = load_midi("music\\game_music\\game_music12.mid");
			}
			if(random_music==13)
			{
				music = load_midi("music\\game_music\\game_music13.mid");
			}
			play_midi(music,TRUE);
		}
		if(menu_game_option==FINAL_LEVEL)
		{
			random_music=0;
			random_music=rand()%1;
			if(random_music==0)
			{
				music = load_midi("music\\game_music\\final_level\\final_level0.mid");
			}
			if(random_music==1)
			{
				music = load_midi("music\\game_music\\final_level\\final_level1.mid");
			}
			play_midi(music,TRUE);
		}
	}

	if(menu_game_option==DESTROY)
	{
		free(music);
	}
}

int init()
{
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 800, 600, 0, 0);
	if (res != 0)
	{
		allegro_message(allegro_error);
		exit(-1);
	}

	if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
	{
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }
	install_keyboard();
	install_mouse();
	set_mouse_speed(2,2);
}

void deinit()
{
	clear_keybuf();
}

