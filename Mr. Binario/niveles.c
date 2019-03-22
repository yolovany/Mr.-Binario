#include "motor_juego.c"

void menu_niveles (Tscore jugador, FONT *letras, BITMAP *buffer, BITMAP *cursor, MIDI *music);

void menu_niveles (Tscore jugador, FONT *letras, BITMAP *buffer, BITMAP *cursor, MIDI *music)
{
	int bandera_music_final = 0;
 	int vector[((NUMERO_ACIERTOS)*(4))+NUMERO_ERRORES]; //SUMA ERRORES, PARA EVITAR DESBORDE EN CASO DE ERROR EN RESPUESTA...
	// BITMAPS para el menu...
	music_play(0,DESTROY,music);
	music_play(GAME,LOAD,music);
	SAMPLE *sonido1 = load_wav("music\\grow!.wav");
	BITMAP *estrella = load_bitmap("images\\msges\\estrella.bmp", NULL);
	BITMAP *ready = load_bitmap("images\\msges\\ready.bmp", NULL);
	BITMAP *go = load_bitmap("images\\msges\\go.bmp", NULL);
	BITMAP *elige_ayuda = load_bitmap("images\\menu_niveles\\menu_elige_ayuda.bmp", NULL);
	BITMAP *elige = load_bitmap("images\\menu_niveles\\menu_elige.bmp", NULL);
	BITMAP *elige_final = load_bitmap("images\\menu_niveles\\menu_elige_final.bmp", NULL);
	BITMAP *elige8 = load_bitmap("images\\menu_niveles\\menu_elige8.bmp", NULL);
	BITMAP *elige16 = load_bitmap("images\\menu_niveles\\menu_elige16.bmp", NULL);
	BITMAP *elige32 = load_bitmap("images\\menu_niveles\\menu_elige32.bmp", NULL);
	BITMAP *elige64 = load_bitmap("images\\menu_niveles\\menu_elige64.bmp", NULL);
	BITMAP *salir = load_bitmap("images\\menu_niveles\\menu_elige_salir.bmp", NULL);
	BITMAP *logo = load_bitmap("images\\msges\\portada.bmp", NULL);
	BITMAP *nivel_completo = load_bitmap("images\\msges\\nivel_completo.bmp",NULL);
	BITMAP *you_lose = load_bitmap("images\\msges\\YOU LOSE PAPU.bmp",NULL);
	BITMAP *bloqueado = load_bitmap("images\\msges\\bloqueado.bmp",NULL);
	BITMAP *juego_terminado = load_bitmap("images\\msges\\juego_concluido.bmp",NULL);
	BITMAP *gracias = load_bitmap("images\\msges\\gracias.bmp",NULL);
	BITMAP *instruccion0 = load_bitmap("images\\how_to_play\\instruccion0.bmp", NULL);

	// BITMAPS para los niveles...
	BITMAP *lose = load_bitmap("images\\msges\\LOSE.bmp", NULL);
	BITMAP *win = load_bitmap("images\\msges\\ostia_tio.bmp", NULL);
	BITMAP *numero = load_bitmap("images\\msges\\Casilla_seleccionada.bmp",NULL);
	BITMAP *ok = load_bitmap("images\\msges\\OK.bmp",NULL);
	BITMAP *tiempo_agotado = load_bitmap("images\\msges\\tiempo_agotado.bmp", NULL);

	BITMAP *fondo8 = load_bitmap("images\\menu_niveles\\fondos_niveles\\FONDO NIVEL 8 BITS.bmp",NULL);
	BITMAP *fondo16 = load_bitmap("images\\menu_niveles\\fondos_niveles\\FONDO  NIVEL 16 BITS.bmp",NULL);
	BITMAP *fondo32 = load_bitmap("images\\menu_niveles\\fondos_niveles\\FONDO NIVEL 32 BITS.bmp",NULL);
	BITMAP *fondo64 = load_bitmap("images\\menu_niveles\\fondos_niveles\\FONDO NIVEL 64 BITS.bmp",NULL);

	blit(logo,screen,0,0,0,0,800,600);
	rest(800);
	int i;
	for(i=800;i>=0;i=i-5)
	{
		blit(logo,buffer,0,0,i-800,0,800,600); //imprime fondo documento en buffer, avanza conforme i
		blit(elige,buffer,0,0,i,0,800,600);
		blit(buffer,screen,0,0,0,0,800,600);
		clear_bitmap(buffer);
	}
	rest(800);
	long score=0;
	int aciertos=0;
	int errores=0;
	int numero_aciertos=0;
	int numero_errores=0;

	int corrige_bug=0;

	int centinela_nivel_8bits_completado=0;
	int centinela_nivel_16bits_completado=0;
	int centinela_nivel_32bits_completado=0;
	int centinela_nivel_64bits_completado=0;
	int juego_iniciado=0;

	int	numero_planteado; // VARIABLES PARA LA VALIDACION DE NO REPETIDOS
	int longitud=0; // VARIABLES PARA LA VALIDACION DE NO REPETIDOS
	int z=0; // VARIABLES PARA LA VALIDACION DE NO REPETIDOS
	int bandera=0;
	int mov = 1;

	while(bandera==0)
	{
		if(numero_errores==NUMERO_ERRORES)
		{
			clear_bitmap(buffer);
			blit(you_lose,buffer,0,0,0,0,800,600);
			blit(buffer,screen,0,0,0,0,800,600);
			rest(2500);
			for(i=0;i>=-800;i=i-2)
			{
				blit(you_lose,buffer,0,0,i,0,800,600); //imprime fondo documento en buffer, avanza conforme i
				blit(buffer,screen,0,0,0,0,800,600);
				clear_bitmap(buffer);
			}
			rest(450);
			bandera=1;
		}
		if(juego_iniciado==0)
		{
			blit(elige,buffer,0,0,0,0,800,600);
			blit(ready,buffer,0,0,0,75,800,450);
			blit(buffer,screen,0,0,0,0,800,600);
			rest(1000);
			blit(go,buffer,0,0,0,75,800,450);
			blit(buffer,screen,0,0,0,0,800,600);
			rest(1000);
			juego_iniciado=1;
		}
		if(bandera!=1) // evita que el fondo menu_elige salga en pantalla despues del you_lose_papu
		{
			blit(elige,buffer,0,0,0,0,800,600);
			textprintf_ex(buffer, font, 175, 556, makecol(0, 10, 0), -1, "SCORE: %d", score);
			textprintf_ex(buffer, font, 290, 556, makecol(0, 10, 0), -1, "NUMERO DE ACIERTOS: %d", numero_aciertos);
			textprintf_ex(buffer, font, 495, 556, makecol(0, 10, 0), -1, "NUMERO DE ERRORES: %d", numero_errores);
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
		}
		if(mouse_x > 611 && mouse_x < 789 && mouse_y > 469 && mouse_y < 520)
		{
			blit(elige_ayuda,buffer,0,0,0,0,800,600);
			textprintf_ex(buffer, font, 175, 556, makecol(0, 10, 0), -1, "SCORE: %d", score);
			textprintf_ex(buffer, font, 290, 556, makecol(0, 10, 0), -1, "NUMERO DE ACIERTOS: %d", numero_aciertos);
			textprintf_ex(buffer, font, 495, 556, makecol(0, 10, 0), -1, "NUMERO DE ERRORES: %d", numero_errores);
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if(mouse_b&1 || key[KEY_ENTER])
			{
				int i;
				for(i=600;i>=0;i=i-3)
				{
					blit(elige,buffer,0,0,0,0,800,600);
					if(centinela_nivel_8bits_completado==1)
					{
						blit(estrella,buffer,0,0,67,182,90,90);  /////
						blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
					}
					if(centinela_nivel_16bits_completado==1)
					{
						blit(estrella,buffer,0,0,267,182,90,90);
						blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
					}
					if(centinela_nivel_32bits_completado==1)
					{
						blit(estrella,buffer,0,0,453,182,90,90);
						blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
					}
					blit(instruccion0,buffer,0,0,0,i,800,600); //imprime fondo documento en buffer, avanza conforme i
					blit(buffer,screen,0,0,0,0,800,600);
				}
				do
				{
					blit(instruccion0,buffer,0,0,0,0,800,600);
					blit(buffer,screen,0,0,0,0,800,600);
					clear_bitmap(buffer);
				}while( !key[KEY_ENTER] && !mouse_b&1);
				rest(300);
				deinit();
				how_to_play(buffer,MANUAL);
				position_mouse(400,300);
			}
		}

		if(mouse_x > 32 && mouse_x < 191 && mouse_y > 147 && mouse_y < 306) // en casilla 8 bits
		{
			blit(elige8,buffer,0,0,0,0,800,600);
			textprintf_ex(buffer, font, 175, 556, makecol(0, 10, 0), -1, "SCORE: %d", score);
			textprintf_ex(buffer, font, 290, 556, makecol(0, 10, 0), -1, "NUMERO DE ACIERTOS: %d", numero_aciertos);
			textprintf_ex(buffer, font, 495, 556, makecol(0, 10, 0), -1, "NUMERO DE ERRORES: %d", numero_errores);
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);

			if(mouse_b&1 || key[KEY_ENTER])
			{
				clear_bitmap(buffer);
				if(aciertos<NUMERO_ACIERTOS&&centinela_nivel_8bits_completado==0)
				{
					int bandera1=0;
					int x;
					do
					{
						numero_planteado = rand()%16;
						x = buscar(numero_planteado,vector);
						if(x<0)
						{
							bandera1=1;
						}
					}while(bandera1==0);
					vector[z]=numero_planteado;
					for(i=0;i<=600;i=i+4)
					{
						blit(elige8,buffer,0,0,0,0,800,600);
						if(centinela_nivel_8bits_completado==1)
						{
							blit(estrella,buffer,0,0,67,182,90,90);  /////
						}
						blit(fondo8,buffer,0,0,0,i-600,800,600); //imprime fondo documento en buffer, avanza conforme i
						blit(buffer,screen,0,0,0,0,800,600);
					}
																		// funcion nivel_8bits en "motor_juego.c"

					int resultado= nivel_8bits(letras,buffer,cursor,lose,win,numero,ok,tiempo_agotado,fondo8,vector[z]);
					z++;
					if(resultado<0)
					{
						errores++;
						numero_errores++;
					}
					else if(resultado!=0)
				 	{
				 		aciertos++;
				 		numero_aciertos++;
				 		corrige_bug++;
				 	}
				 	score=score+resultado;
				}
				else
				 {
				 	 if(centinela_nivel_8bits_completado==0)
				 	 {
				 	 	errores=0;
					 	aciertos=0;
					 }
					 blit(nivel_completo,screen,0,0,0,0,800,600);
					  int vector[NUMERO_ACIERTOS+NUMERO_ERRORES]; //SUMA ERRORES, PARA EVITAR DESBORDE EN CASO DE ERROR EN RESPUESTA...
					 rest(1000);
					 clear_bitmap(buffer);
					 clear_bitmap(screen);
				 }
			 }
		}

		if(aciertos==NUMERO_ACIERTOS)
		{
			centinela_nivel_8bits_completado=1;
			errores=0;
			aciertos=0;
		}

		if(mouse_x > 232 && mouse_x < 391 && mouse_y > 147 && mouse_y < 306) // casilla 16 bits
		{
			blit(elige16,buffer,0,0,0,0,800,600);
			textprintf_ex(buffer, font, 175, 556, makecol(0, 10, 0), -1, "SCORE: %d", score);
			textprintf_ex(buffer, font, 290, 556, makecol(0, 10, 0), -1, "NUMERO DE ACIERTOS: %d", numero_aciertos);
			textprintf_ex(buffer, font, 495, 556, makecol(0, 10, 0), -1, "NUMERO DE ERRORES: %d", numero_errores);
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if(mouse_b&1 || key[KEY_ENTER])
			{
				clear_bitmap(buffer);
				if(aciertos<NUMERO_ACIERTOS&&centinela_nivel_16bits_completado==0)
				{

					if(centinela_nivel_8bits_completado==1)
					{
						int bandera1=0;
						int x;
						do
						{
							numero_planteado=rand()%(15+1)+16;
							x = buscar(numero_planteado,vector);
							if(x<0)
							{
								bandera1=1;
							}
						}while(bandera1==0);
						vector[z]=numero_planteado;
						for(i=0;i<=600;i=i+4)
						{
							blit(elige16,buffer,0,0,0,0,800,600);
							if(centinela_nivel_8bits_completado==1)
							{
								blit(estrella,buffer,0,0,67,182,90,90);  /////
							}
							if(centinela_nivel_16bits_completado==1)
							{
								blit(estrella,buffer,0,0,67,182,90,90);  /////
							}
							blit(fondo16,buffer,0,0,0,i-600,800,600); //imprime fondo documento en buffer, avanza conforme i
							blit(buffer,screen,0,0,0,0,800,600);
						}
																			// funcion nivel_16bits en "motor_juego.c"
						int resultado= nivel_16bits(letras,buffer,cursor,lose,win,numero,ok,tiempo_agotado,fondo16,vector[z]);
						z++;
						if(resultado<0)
						{
							errores++;
							numero_errores++;
						}
						else if(resultado!=0)
				 		{
				 			aciertos++;
				 			numero_aciertos++;
				 			corrige_bug++;
				 		}
				 		score=score+resultado;
					}
					else
					{
						blit(bloqueado,screen,0,0,0,0,800,600);
						rest(1000);
						clear_bitmap(buffer);
					}
			    }
				else
				 {
				 	 if(centinela_nivel_16bits_completado==0)
				 	 {
				 	 	errores=0;
					 	aciertos=0;
					 }

					centinela_nivel_16bits_completado=1;
					blit(nivel_completo,screen,0,0,0,0,800,600);
					rest(1000);

				 }
			}
		}

		if(aciertos==NUMERO_ACIERTOS)
		{
			centinela_nivel_16bits_completado=1;
			errores=0;
			aciertos=0;
		}

		if(mouse_x > 418 && mouse_x < 578 && mouse_y > 147 && mouse_y < 306) // casilla 32 bits
		{
			blit(elige32,buffer,0,0,0,0,800,600);
			textprintf_ex(buffer, font, 175, 556, makecol(0, 10, 0), -1, "SCORE: %d", score);
			textprintf_ex(buffer, font, 290, 556, makecol(0, 10, 0), -1, "NUMERO DE ACIERTOS: %d", numero_aciertos);
			textprintf_ex(buffer, font, 495, 556, makecol(0, 10, 0), -1, "NUMERO DE ERRORES: %d", numero_errores);
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if(mouse_b&1 || key[KEY_ENTER])
			{
				clear_bitmap(buffer);
				if(aciertos<NUMERO_ACIERTOS&&centinela_nivel_32bits_completado==0)
				{
					if(centinela_nivel_16bits_completado==1)
					{
						int bandera1=0;
						int x;
						do
						{
							numero_planteado=rand()%(31+1)+32;
							x = buscar(numero_planteado,vector);
							if(x<0)
							{
								bandera1=1;
							}
						}while(bandera1==0);
						vector[z]=numero_planteado;
						for(i=0;i<=600;i=i+4)
						{
							blit(elige32,buffer,0,0,0,0,800,600);
							if(centinela_nivel_8bits_completado==1)
							{
								blit(estrella,buffer,0,0,67,182,90,90);  /////
							}
							if(centinela_nivel_16bits_completado==1)
							{
								blit(estrella,buffer,0,0,267,182,90,90);
							}
							if(centinela_nivel_32bits_completado==1)
							{
								blit(estrella,buffer,0,0,453,182,90,90);
							}
							blit(fondo32,buffer,0,0,0,i-600,800,600); //imprime fondo documento en buffer, avanza conforme i
							blit(buffer,screen,0,0,0,0,800,600);
						}
																			// funcion nivel_32bits en "motor_juego.c"
						int resultado= nivel_32bits(letras,buffer,cursor,lose,win,numero,ok,tiempo_agotado,fondo32,vector[z]);
						z++;
						if(resultado<0)
						{
							errores++;
							numero_errores++;
						}
						else if(resultado!=0)
				 		{
				 			aciertos++;
				 			numero_aciertos++;
				 			corrige_bug++;
				 		}
				 		score=score+resultado;
					}
					else
					{
						blit(bloqueado,screen,0,0,0,0,800,600);
						rest(1000);
						clear_bitmap(buffer);
					}
			    }
				else
				 {
				 	 if(centinela_nivel_32bits_completado==0)
				 	 {
				 	 	errores=0;
					 	aciertos=0;
					 }
					centinela_nivel_32bits_completado=1;
					blit(nivel_completo,screen,0,0,0,0,800,600);
					rest(1000);
				 }
			}
		}

		if(aciertos==NUMERO_ACIERTOS)
		{
			centinela_nivel_32bits_completado=1;
			errores=0;
			aciertos=0;
		}

		if(mouse_x > 605 && mouse_x < 765 && mouse_y > 147 && mouse_y < 306) // casilla 64 bits
		{
			if(centinela_nivel_32bits_completado==1)
			{
				blit(elige_final,buffer,0,0,0,0,800,600);
				if(bandera_music_final==0)
				{
					music_play(0,DESTROY,music);
					music_play(FINAL_LEVEL,LOAD,music);
					bandera_music_final=1;
				}
			}
			else
			{
				blit(elige64,buffer,0,0,0,0,800,600);
			}
			textprintf_ex(buffer, font, 175, 556, makecol(0, 10, 0), -1, "SCORE: %d", score);
			textprintf_ex(buffer, font, 290, 556, makecol(0, 10, 0), -1, "NUMERO DE ACIERTOS: %d", numero_aciertos);
			textprintf_ex(buffer, font, 495, 556, makecol(0, 10, 0), -1, "NUMERO DE ERRORES: %d", numero_errores);
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if(mouse_b&1 || key[KEY_ENTER])
			{
				clear_bitmap(buffer);

				if(aciertos<NUMERO_ACIERTOS&&centinela_nivel_64bits_completado==0)
				{
					if(centinela_nivel_32bits_completado==1)
					{
						int bandera1=0;
						int x;
						do
						{
							numero_planteado=rand()%(63+1)+64;
							x = buscar(numero_planteado,vector);
							if(x<0)
							{
								bandera1=1;
							}
						}while(bandera1==0);
						vector[z]=numero_planteado;
																			// funcion nivel_64bits en "motor_juego.c"
						int resultado= nivel_64bits(letras,buffer,cursor,lose,win,numero,ok,tiempo_agotado,fondo64,music,vector[z]);
						z++;
						if(resultado<0)
						{
							errores++;
							numero_errores++;
						}
						else if(resultado!=0)
				 		{
				 			aciertos++;
				 			numero_aciertos++;
				 			corrige_bug++;
				 		}
				 		score=score+resultado;
				 		if(aciertos==NUMERO_ACIERTOS)
						{
							blit(juego_terminado,screen,0,0,0,0,800,600);
							rest(2500);
							bandera=1;
						}
					}
					else
					{
						blit(bloqueado,screen,0,0,0,0,800,600);
						rest(1000);
						clear_bitmap(buffer);
					}
			    }
				else
				 {
				 	 if(centinela_nivel_64bits_completado==0)
				 	 {
				 	 	errores=0;
					 	aciertos=0;
					 }
				 	 centinela_nivel_64bits_completado=1;
				 	if(aciertos==NUMERO_ACIERTOS)
					{
						blit(juego_terminado,screen,0,0,0,0,800,600);
						rest(1000);
						bandera=1;
					}
					 blit(nivel_completo,screen,0,0,0,0,800,600);
					 rest(1500);
					 bandera=1;
				 }
			}

		}
		if(mouse_x > 32 && mouse_x < 80 && mouse_y > 539 && mouse_y < 571)
		{
			blit(salir,buffer,0,0,0,0,800,600);
			textprintf_ex(buffer, font, 175, 556, makecol(0, 10, 0), -1, "SCORE: %d", score);
			textprintf_ex(buffer, font, 290, 556, makecol(0, 10, 0), -1, "NUMERO DE ACIERTOS: %d", numero_aciertos);
			textprintf_ex(buffer, font, 495, 556, makecol(0, 10, 0), -1, "NUMERO DE ERRORES: %d", numero_errores);
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if(mouse_b&1 || key[KEY_ENTER])
			{
				bandera=1;
			}
		}
		if(centinela_nivel_8bits_completado==1)
		{
			blit(estrella,buffer,0,0,67,182,90,90);  /////
		}
		if(centinela_nivel_16bits_completado==1)
		{
			blit(estrella,buffer,0,0,267,182,90,90);
		}
		if(centinela_nivel_32bits_completado==1)
		{
			blit(estrella,buffer,0,0,453,182,90,90);
		}

		 if(key[KEY_5])
        {
            mouse_y = mouse_y - mov;
             position_mouse(mouse_x, mouse_y);
        }

	    if(key[KEY_2])
        {
            mouse_y = mouse_y + mov;
             position_mouse(mouse_x, mouse_y);
        }

        if(key[KEY_1])
        {
            mouse_x = mouse_x - mov;
             position_mouse(mouse_x, mouse_y);
        }

         if(key[KEY_3])
        {
            mouse_x = mouse_x +mov;
             position_mouse(mouse_x, mouse_y);
        }

		blit(buffer,screen,0,0,0,0,800,600);
		clear_bitmap(buffer);

	}


	jugador.score=score;
	jugador.numero_aciertos=numero_aciertos;
	jugador.numero_errores=numero_errores;

	if(jugador.score>400)
	{
		login(jugador,letras,buffer,cursor,gracias);
	}


	clear_bitmap(buffer);
	clear_bitmap(screen);
	destroy_bitmap(estrella);
	destroy_bitmap(ready);
	destroy_bitmap(go);
	destroy_bitmap(elige);
	destroy_bitmap(elige_ayuda);
	destroy_bitmap(elige8);
	destroy_bitmap(elige16);
	destroy_bitmap(elige32);
	destroy_bitmap(elige64);
	destroy_bitmap(salir);
	destroy_bitmap(nivel_completo);
	destroy_bitmap(you_lose);
	destroy_bitmap(bloqueado);
	destroy_bitmap(juego_terminado);
	destroy_bitmap(lose);
	destroy_bitmap(win);
	destroy_bitmap(numero);
	destroy_bitmap(ok);
	destroy_bitmap(tiempo_agotado);
	destroy_bitmap(fondo8);
	destroy_bitmap(fondo16);
	destroy_bitmap(fondo32);
	destroy_bitmap(fondo64);
	destroy_bitmap(gracias);
	destroy_bitmap(elige_final);
	destroy_bitmap(instruccion0);
	destroy_bitmap(logo);
	destroy_sample(sonido1);

}
