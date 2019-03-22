
#define NUMERO_ACIERTOS 3
#define NUMERO_ERRORES 5
#define INACTIVIDAD 3000

#define AUTOMATICO 70 // PARA PARAMETROS DE LA FUNCION how_to_play(int modo_vista);
#define MANUAL 90  // PARA PARAMETROS DE LA FUNCION how_to_play(int modo_vista);



#include "allegro_lib.h"
#include "funciones_complementarias.h"
#include "info.c"
#include "scores.c"
#include "niveles.c"

void menu_principal();
void servidor_gamepad();
int main()
{
	init();
	srand(time(NULL));
	menu_principal();
	deinit();
	return 0;
}
END_OF_MAIN()

void menu_principal()
{
	Tscore jugador;
	MIDI *music;
	music_play(MENU,LOAD,music);
	int bandera_howtoplay=0; // bandera que se utilizará para mostrar instrucciones de juego sólo una vez

	FONT *letras = load_font("engine\\letra.pcx", NULL, NULL);
	BITMAP *buffer = create_bitmap(800,600); //BUFFERS DONDE SE IMPRIMIRÁN TODOS LOS EVENTOS
	BITMAP *cursor = load_bitmap("engine\\cursor.bmp", NULL);
	BITMAP *fondo_color = load_bitmap("images\\msges\\fondo_color.bmp",NULL);
	BITMAP *portada = load_bitmap("images\\msges\\portada.bmp", NULL);
	blit(fondo_color,screen,0,0,0,0,800,600);
	rest(500);
	blit(portada,screen,0,0,0,0,800,600);
	rest(1900);
	BITMAP *menu = load_bitmap("images\\Menu_principal\\menu.bmp",NULL);
	BITMAP *menu_iniciar = load_bitmap("images\\Menu_principal\\menu_iniciar.bmp",NULL);
	BITMAP *menu_scores = load_bitmap("images\\Menu_principal\\menu_scores.bmp",NULL);
	BITMAP *menu_acerca = load_bitmap("images\\Menu_principal\\menu_acerca.bmp",NULL);
	BITMAP *menu_hello = load_bitmap("images\\Menu_principal\\menu_hello.bmp",NULL);
	BITMAP *click = load_bitmap("images\\how_to_play\\click.bmp", NULL);
	int inactivo=INACTIVIDAD;
	int posicion_x=mouse_x;
	int posicion_y=mouse_y;
	int mov = 1;
	while(!key[KEY_ESC])
	{
		if(posicion_x==mouse_x&&posicion_y==mouse_y)
		{
			inactivo--;
		}
		else
		{
			inactivo=INACTIVIDAD;
			posicion_x=mouse_x;
			posicion_y=mouse_y;
		}
		if(inactivo==0)
		{
			int i;
			for(i=600;i>=0;i=i-3)
			{
				blit(menu,buffer,0,0,0,0,800,600);
				blit(menu_hello,buffer,0,0,0,i,800,600); //imprime fondo documento en buffer, avanza conforme i
				blit(buffer,screen,0,0,0,0,800,600);
			}
			i=1000;
			do
			{
				i--;
				blit(menu_hello,buffer,0,0,0,0,800,600);
				blit(buffer,screen,0,0,0,0,800,600);
				if(posicion_x!=mouse_x||posicion_y!=mouse_y)
				{
					i=0;
					inactivo=INACTIVIDAD;
					posicion_x=mouse_x;
					posicion_y=mouse_y;
				}

			}while(i!=0);
			deinit();
			how_to_play(buffer,AUTOMATICO);
			position_mouse(400,200);
		}

		blit(menu,buffer,0,0,0,0,800,600);
		if(mouse_x > 252 && mouse_x < 546 && mouse_y > 156 && mouse_y < 230)
		{
			blit(menu_iniciar,buffer,0,0,0,0,800,600);
			if(mouse_b&1 || key[KEY_ENTER])
			{
				int i;
				for(i=800;i>=0;i=i-4)
				{
					blit(menu_iniciar,buffer,0,0,i-800,0,800,600); //imprime fondo documento en buffer, avanza conforme i
					blit(fondo_color,buffer,0,0,i,0,800,600);
					blit(buffer,screen,0,0,0,0,800,600);
				}

				if(bandera_howtoplay==0)
				{
					rest(1000);
					int i;
					for(i=600;i>=0;i=i-6)
					{
						blit(fondo_color,buffer,0,0,0,0,800,600);
						blit(click,buffer,0,0,0,i,800,600); //imprime fondo documento en buffer, avanza conforme i
						blit(buffer,screen,0,0,0,0,800,600);
					}
					do
					{
						blit(click,buffer,0,0,0,0,800,600);
						blit(buffer,screen,0,0,0,0,800,600);
						clear_bitmap(buffer);
					}while( key[KEY_ENTER] && !mouse_b&1);
					rest(200);
					deinit();
					how_to_play(buffer,MANUAL);
				}
				menu_niveles(jugador,letras,buffer,cursor,music);
				music_play(MENU,LOAD,music);
				bandera_howtoplay=1;
				blit(portada,buffer,0,0,0,0,800,600);
				blit(buffer,screen,0,0,0,0,800,600);
				rest(800);
			}
		}
		if(mouse_x > 252 && mouse_x < 546 && mouse_y > 262 && mouse_y < 336)
		{

			blit(menu_scores,buffer,0,0,0,0,800,600);
			if(mouse_b&1 || key[KEY_ENTER])
			{
				clear_bitmap(buffer);
				int i;
				for(i=800;i>=0;i=i-4)
				{
					blit(menu_iniciar,buffer,0,0,i-800,0,800,600); //imprime fondo documento en buffer, avanza conforme i
					blit(fondo_color,buffer,0,0,i,0,800,600);
					blit(buffer,screen,0,0,0,0,800,600);
				}
				rest(500);
				scores(letras,buffer,cursor);
			}
		}
		if(mouse_x > 252 && mouse_x < 546 && mouse_y > 372 && mouse_y < 446)
		{
			blit(menu_acerca,buffer,0,0,0,0,800,600);
			if(mouse_b&1 || key[KEY_ENTER])
			{
				clear_bitmap(buffer);
				int i;
				for(i=800;i>=0;i=i-4)
				{
					blit(menu_iniciar,buffer,0,0,i-800,0,800,600); //imprime fondo documento en buffer, avanza conforme i
					blit(fondo_color,buffer,0,0,i,0,800,600);
					blit(buffer,screen,0,0,0,0,800,600);
				}
				rest(500);
				acerca_de(buffer,cursor);
			}
		}

		if(key[KEY_5])
        {
            mouse_y = mouse_y - mov;
        }

	    if(key[KEY_2])
        {
            mouse_y = mouse_y + mov;
        }

        if(key[KEY_1])
        {
            mouse_x = mouse_x - mov;
        }

         if(key[KEY_3])
        {
            mouse_x = mouse_x +mov;
        }

		blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
		blit(buffer,screen,0,0,0,0,800,600);
		clear_bitmap(buffer);
	}
	blit(portada,buffer,0,0,0,0,800,600);
	blit(buffer,screen,0,0,0,0,800,600);
	rest(1500);

	destroy_bitmap(cursor);
	destroy_bitmap(fondo_color);
	destroy_bitmap(portada);
	destroy_bitmap(buffer);
	destroy_bitmap(menu_iniciar);
	destroy_bitmap(menu_scores);
	destroy_bitmap(menu_acerca);
	destroy_bitmap(menu_hello);
	destroy_font(letras);
	destroy_bitmap(click);
	music_play(0,DESTROY,music);
}

void servidor_gamepad()
{

}






