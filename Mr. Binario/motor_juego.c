#define TIEMPO 8000

int nivel_8bits (FONT *letras, BITMAP *buffer, BITMAP *cursor, BITMAP *lose, BITMAP *win, BITMAP *numero, BITMAP *ok, BITMAP *tiempo_agotado, BITMAP *fondo, int numero_planteado);
int nivel_16bits(FONT *letras, BITMAP *buffer, BITMAP *cursor, BITMAP *lose, BITMAP *win, BITMAP *numero, BITMAP *ok, BITMAP *tiempo_agotado, BITMAP *fondo,int numero_planteado);
int nivel_32bits(FONT *letras, BITMAP *buffer, BITMAP *cursor, BITMAP *lose, BITMAP *win, BITMAP *numero, BITMAP *ok, BITMAP *tiempo_agotado, BITMAP *fondo,int numero_planteado);
int nivel_64bits (FONT *letras, BITMAP *buffer, BITMAP *cursor, BITMAP *lose, BITMAP *win, BITMAP *numero, BITMAP *ok, BITMAP *tiempo_agotado, BITMAP *fondo, MIDI *music,int numero_planteado);

int centinela_1bit,centinela_2bits,centinela_4bits,centinela_8bits,centinela_16bits,centinela_32bits,centinela_64bits=0;
int ubicado_1bit,ubicado_2bits,ubicado_4bits,ubicado_8bits,ubicado_16bits,ubicado_32bits,ubicado_64bits=0;
int juego_iniciado=0;
int respuesta,suma=0,centinela_error=0;
int temporalizador=TIEMPO;

int nivel_8bits (FONT *letras, BITMAP *buffer, BITMAP *cursor, BITMAP *lose, BITMAP *win, BITMAP *numero, BITMAP *ok, BITMAP *tiempo_agotado, BITMAP *fondo, int numero_planteado)
{
	SAMPLE *correcto = load_wav("music\\correct.wav");
	SAMPLE *error = load_wav("music\\error.wav");
	centinela_1bit=0;centinela_2bits=0;centinela_4bits=0;centinela_8bits=0;
	ubicado_1bit=0;ubicado_2bits=0;ubicado_4bits=0;ubicado_8bits=0;
	respuesta=0;suma=0;centinela_error=0;
	temporalizador=TIEMPO;

	if(juego_iniciado==0)
	{
		respuesta=0;
		juego_iniciado=1;
	}
	int mov = 1;
	while(temporalizador>0) // RUTINA
	{
		textprintf_ex(screen, letras, 84, 194, makecol(0, 0, 0), -1, "%d", numero_planteado);
		textprintf_ex(screen, letras, 698, 470, makecol(0, 0, 0), -1, "%d", temporalizador);
		temporalizador--;
		blit(fondo,buffer,0,0,0,0,800,600); // IMPRIME FONDO NIVEL 8 BITS

// ------------------------------------------------- ZONA 1 BITS -----------------------------------------------------
		if(centinela_1bit==1)
		{
			blit(numero,buffer,0,0,582,290,54,53);
		}
		if(mouse_x > 550 && mouse_x < 652 && mouse_y > 273 && mouse_y < 372)
		{
			if((key[KEY_ENTER] || mouse_b&1) && centinela_1bit==0)
			{
				ubicado_1bit=1;
				centinela_1bit=1;
				blit(numero,buffer,0,0,582,290,54,53);
				suma=1;
			}

			if(!key[KEY_ENTER] || !mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 1 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 2 BITS -----------------------------------------------------
		if(centinela_2bits==1)
		{
			blit(numero,buffer,0,0,450,290,54,53);
		}

		if(mouse_x > 420 && mouse_x < 515 && mouse_y > 273 && mouse_y < 372)
		{
			if((key[KEY_ENTER] || mouse_b&1) && centinela_2bits==0)
			{
				ubicado_2bits=1;
				centinela_2bits=1;
				blit(numero,buffer,0,0,450,290,54,53);
				suma=2;
			}

			if(!key[KEY_ENTER] || !mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 2 bits
				suma=0;
			}

		}

// ------------------------------------------------- ZONA 4 BITS -----------------------------------------------------
		if(centinela_4bits==1)
		{
			blit(numero,buffer,0,0,322,290,54,53);
		}
		if(mouse_x > 296 && mouse_x < 385 && mouse_y > 273 && mouse_y < 372)
		{
			if((key[KEY_ENTER] || mouse_b&1) && centinela_4bits==0)
			{
				ubicado_4bits=1;
				centinela_4bits=1;
				blit(numero,buffer,0,0,322,290,54,53);
				suma=4;
			}

			if(!key[KEY_ENTER] || !mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 4 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 8 BITS -----------------------------------------------------
		if(centinela_8bits==1)
		{
			blit(numero,buffer,0,0,193,290,54,53);
		}
		if(mouse_x > 170 && mouse_x < 260 && mouse_y > 273 && mouse_y < 372)
		{
			if((key[KEY_ENTER] || mouse_b&1) && centinela_8bits==0)
			{
				ubicado_8bits=1;
				centinela_8bits=1;
				suma=8;
				blit(numero,buffer,0,0,193,290,54,53);
			}

			if(!key[KEY_ENTER] || !mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 8 bits
				suma=0;
			}
		}

// --------------------------------------------------------------------------------------------------------------------

		if(mouse_x > 352 && mouse_x < 446 && mouse_y > 450 && mouse_y < 495) // MARCAR IMAGEN OK
		{
			blit(ok,buffer,0,0,352,450,95,46);
			if( respuesta==numero_planteado)
			{
				respuesta=0;
				play_sample(correcto, 200, 150, 1000, 0);
				blit(win,screen,0,0,0,0,800,600);
				rest(1000);
				clear_bitmap(buffer);
				clear_bitmap(screen);
				return temporalizador;
		    }
		     else
		     {
		     	 respuesta=0;
				 centinela_1bit,centinela_2bits,centinela_4bits,centinela_8bits,centinela_16bits,centinela_32bits,centinela_64bits=0;
	             ubicado_1bit,ubicado_2bits,ubicado_4bits,ubicado_8bits,ubicado_16bits,ubicado_32bits,ubicado_64bits=0;

			     blit(lose,screen,0,0,0,0,800,600);
			     play_sample(error, 200, 150, 1000, 0);
			     rest(1000);
			     clear_bitmap(buffer);
				 clear_bitmap(screen);
			     return -300;   // si pierde, se le quitan 1500 puntos sobre el record final
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
		blit(buffer,screen,0,0,0,0,800,600); //IMPRIME TODOS LOS EVENTOS EN PANTALLA
		clear_bitmap(buffer);

	} // FIN DE RUTINA

	if(temporalizador==0)
	{
		blit(tiempo_agotado,screen,0,0,0,0,800,600);
		play_sample(error, 200, 150, 1000, 0);
		rest(2500);
		clear_bitmap(buffer);
		clear_bitmap(screen);
		return -100;
	}
}

int nivel_16bits (FONT *letras, BITMAP *buffer, BITMAP *cursor, BITMAP *lose, BITMAP *win, BITMAP *numero, BITMAP *ok, BITMAP *tiempo_agotado, BITMAP *fondo, int numero_planteado)
{
	SAMPLE *correcto = load_wav("music\\correct.wav");
	SAMPLE *error = load_wav("music\\error.wav");
	centinela_1bit=0;centinela_2bits=0;centinela_4bits=0;centinela_8bits=0;centinela_16bits=0;
	ubicado_1bit=0;ubicado_2bits=0;ubicado_4bits=0;ubicado_8bits=0;ubicado_16bits=0;
	respuesta=0;suma=0;centinela_error=0;
	temporalizador=TIEMPO;

	blit(fondo,buffer,0,0,0,0,800,600);
	blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
	blit(buffer,screen,0,0,0,0,800,600);
	rest(250);
	int mov = 1;
	while(temporalizador>0) // RUTINA
	{
		textprintf_ex(screen, letras, 84, 194, makecol(0, 0, 0), -1, "%d", numero_planteado);
		textprintf_ex(screen, letras, 698, 470, makecol(0, 0, 0), -1, "%d", temporalizador);
		temporalizador--;
		blit(fondo,buffer,0,0,0,0,800,600); // IMPRIME FONDO NIVEL 8 BITS
		blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);


// ------------------------------------------------- ZONA 1 BITS -----------------------------------------------------
		if(centinela_1bit==1)
		{
			blit(numero,buffer,0,0,612,290,54,53);
		}
		if(mouse_x > 605 && mouse_x < 670 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_1bit==0)
			{
				ubicado_1bit=1;
				centinela_1bit=1;
				suma=1;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 1 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 2 BITS -----------------------------------------------------
		if(centinela_2bits==1)
		{
			blit(numero,buffer,0,0,493,290,54,53);
		}

		if(mouse_x > 486 && mouse_x < 551 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_2bits==0)
			{
				ubicado_2bits=1;
				centinela_2bits=1;
				suma=2;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 2 bits
				suma=0;
			}

		}

// ------------------------------------------------- ZONA 4 BITS -----------------------------------------------------
		if(centinela_4bits==1)
		{
			blit(numero,buffer,0,0,373,290,54,53);
		}
		if(mouse_x > 366 && mouse_x < 431 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_4bits==0)
			{
				ubicado_4bits=1;
				centinela_4bits=1;
				suma=4;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 4 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 8 BITS -----------------------------------------------------
		if(centinela_8bits==1)
		{
			blit(numero,buffer,0,0,265,290,54,53);
		}
		if(mouse_x > 257 && mouse_x < 323 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_8bits==0)
			{
				ubicado_8bits=1;
				centinela_8bits=1;
				suma=8;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 8 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 16 BITS -----------------------------------------------------
		if(centinela_16bits==1)
		{
			blit(numero,buffer,0,0,142,290,54,53);
		}
		if(mouse_x > 135 && mouse_x < 200 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_16bits==0)
			{
				ubicado_16bits=1;
				centinela_16bits=1;
				suma=16;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 16 bits
				suma=0;
			}
		}


// --------------------------------------------------------------------------------------------------------------------

		if(mouse_x > 352 && mouse_x < 446 && mouse_y > 450 && mouse_y < 495) // MARCAR IMAGEN OK
		{
			blit(ok,buffer,0,0,352,450,95,46);
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if(respuesta==numero_planteado)
			{
				respuesta=0;
				blit(win,screen,0,0,0,0,800,600);
				play_sample(correcto, 200, 150, 1000, 0);
				rest(1000);
				clear_bitmap(buffer);
			    clear_bitmap(screen);
				return temporalizador;
		    }
		     else
		     {
		     	 respuesta=0;
				 centinela_1bit,centinela_2bits,centinela_4bits,centinela_8bits,centinela_16bits,centinela_32bits,centinela_64bits=0;
	             ubicado_1bit,ubicado_2bits,ubicado_4bits,ubicado_8bits,ubicado_16bits,ubicado_32bits,ubicado_64bits=0;
			     blit(lose,screen,0,0,0,0,800,600);
			     play_sample(error, 200, 150, 1000, 0);
			     rest(1000);
			     clear_bitmap(buffer);
			     clear_bitmap(screen);
			     return -300;   // si pierde, se le quitan 1500 puntos sobre el record final
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
		blit(buffer,screen,0,0,0,0,800,600); //IMPRIME TODOS LOS EVENTOS EN PANTALLA
		clear_bitmap(buffer);

	} // FIN DE RUTINA

	if(temporalizador==0)
	{
		blit(tiempo_agotado,screen,0,0,0,0,800,600);
		play_sample(error, 200, 150, 1000, 0);
		rest(2000);
		clear_bitmap(buffer);
		clear_bitmap(screen);
		return -100;
	}
}

int nivel_32bits (FONT *letras, BITMAP *buffer, BITMAP *cursor, BITMAP *lose, BITMAP *win, BITMAP *numero, BITMAP *ok, BITMAP *tiempo_agotado, BITMAP *fondo,int numero_planteado)
{
	SAMPLE *correcto = load_wav("music\\correct.wav");
	SAMPLE *error = load_wav("music\\error.wav");
	centinela_1bit=0;centinela_2bits=0;centinela_4bits=0;centinela_8bits=0;centinela_16bits=0;centinela_32bits=0;
	ubicado_1bit=0;ubicado_2bits=0;ubicado_4bits=0;ubicado_8bits=0;ubicado_16bits=0;ubicado_32bits=0;
	respuesta=0;suma=0;centinela_error=0;
	temporalizador=TIEMPO;

	blit(fondo,buffer,0,0,0,0,800,600);
	blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
	blit(buffer,screen,0,0,0,0,800,600);
	rest(250);
	int mov = 1;
	while(temporalizador>0) // RUTINA
	{
		textprintf_ex(screen, letras, 84, 194, makecol(0, 0, 0), -1, "%d", numero_planteado);
		textprintf_ex(screen, letras, 698, 470, makecol(0, 0, 0), -1, "%d", temporalizador);
		temporalizador--;
		blit(fondo,buffer,0,0,0,0,800,600); // IMPRIME FONDO NIVEL 8 BITS
		blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);


// ------------------------------------------------- ZONA 1 BITS -----------------------------------------------------
		if(centinela_1bit==1)
		{
			blit(numero,buffer,0,0,681,290,54,53);
		}
		if(mouse_x > 674 && mouse_x < 739 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_1bit == 0)
			{
				ubicado_1bit=1;
				centinela_1bit=1;
				suma=1;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 1 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 2 BITS -----------------------------------------------------
		if(centinela_2bits==1)
		{
			blit(numero,buffer,0,0,561,290,54,53);
		}

		if(mouse_x > 554 && mouse_x < 619 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_2bits == 0)
			{
				ubicado_2bits=1;
				centinela_2bits=1;
				suma=2;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 2 bits
				suma=0;
			}

		}

// ------------------------------------------------- ZONA 4 BITS -----------------------------------------------------
		if(centinela_4bits==1)
		{
			blit(numero,buffer,0,0,442,290,54,53);
		}
		if(mouse_x > 435 && mouse_x < 500 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_4bits == 0)
			{
				ubicado_4bits=1;
				centinela_4bits=1;
				suma=4;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 4 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 8 BITS -----------------------------------------------------
		if(centinela_8bits==1)
		{
			blit(numero,buffer,0,0,321,290,54,53);
		}
		if(mouse_x > 314 && mouse_x < 379 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_8bits == 0)
			{
				ubicado_8bits=1;
				centinela_8bits=1;
				suma=8;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 8 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 16 BITS -----------------------------------------------------
		if(centinela_16bits==1)
		{
			blit(numero,buffer,0,0,202,290,54,53);
		}
		if(mouse_x > 195 && mouse_x < 260 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_16bits == 0)
			{
				ubicado_16bits=1;
				centinela_16bits=1;
				suma=16;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 16 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 32 BITS -----------------------------------------------------
		if(centinela_32bits==1)
		{
			blit(numero,buffer,0,0,77,290,54,53);
		}
		if(mouse_x > 70 && mouse_x < 135 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_32bits == 0)
			{
				ubicado_32bits=1;
				centinela_32bits=1;
				suma=32;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 32 bits
				suma=0;
			}
		}


// --------------------------------------------------------------------------------------------------------------------

		if(mouse_x > 352 && mouse_x < 446 && mouse_y > 450 && mouse_y < 495) // MARCAR IMAGEN OK
		{
			blit(ok,buffer,0,0,352,450,95,46);
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if(respuesta==numero_planteado)
			{
				respuesta=0;
				blit(win,screen,0,0,0,0,800,600);
				play_sample(correcto, 200, 150, 1000, 0);
				rest(1000);
				clear_bitmap(buffer);
			    clear_bitmap(screen);
				return temporalizador;
		    }
		     else
		     {
		     	 respuesta=0;
				 centinela_1bit,centinela_2bits,centinela_4bits,centinela_8bits,centinela_16bits,centinela_32bits,centinela_64bits=0;
	             ubicado_1bit,ubicado_2bits,ubicado_4bits,ubicado_8bits,ubicado_16bits,ubicado_32bits,ubicado_64bits=0;

			     blit(lose,screen,0,0,0,0,800,600);
			     play_sample(error, 200, 150, 1000, 0);
			     rest(1000);
			     clear_bitmap(buffer);
			     clear_bitmap(screen);
			     return -300;   // si pierde, se le quitan 1500 puntos sobre el record final
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
		blit(buffer,screen,0,0,0,0,800,600); //IMPRIME TODOS LOS EVENTOS EN PANTALLA
		clear_bitmap(buffer);

	} // FIN DE RUTINA

	if(temporalizador==0)
	{
		blit(tiempo_agotado,screen,0,0,0,0,800,600);
		play_sample(error, 200, 150, 1000, 0);
		rest(2000);
		clear_bitmap(buffer);
		clear_bitmap(screen);
		return -100;
	}
}

int nivel_64bits (FONT *letras, BITMAP *buffer, BITMAP *cursor, BITMAP *lose, BITMAP *win, BITMAP *numero, BITMAP *ok, BITMAP *tiempo_agotado, BITMAP *fondo, MIDI *music,int numero_planteado)
{
	SAMPLE *correcto = load_wav("music\\correct.wav");
	SAMPLE *error = load_wav("music\\error.wav");
	BITMAP *bit_final = load_bitmap("images\\menu_niveles\\fondos_niveles\\bit_final.bmp", NULL);

	blit(bit_final,screen,0,0,0,0,800,600);
	rest(1500);
	destroy_bitmap(bit_final);

	centinela_1bit=0;centinela_2bits=0;centinela_4bits=0;centinela_8bits=0;centinela_16bits=0;centinela_32bits=0;centinela_64bits=0;
	ubicado_1bit=0;ubicado_2bits=0;ubicado_4bits=0;ubicado_8bits=0;ubicado_16bits=0;ubicado_32bits=0;ubicado_64bits=0;
	respuesta=0;suma=0;centinela_error=0;
	temporalizador=TIEMPO;

	blit(fondo,buffer,0,0,0,0,800,600);
	blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
	blit(buffer,screen,0,0,0,0,800,600);
	rest(250);
	int mov = 1;
	while(temporalizador>0) // RUTINA
	{

		textprintf_ex(screen, letras, 84, 194, makecol(0, 0, 0), -1, "%d", numero_planteado);
		textprintf_ex(screen, letras, 698, 470, makecol(0, 0, 0), -1, "%d", temporalizador);
		temporalizador--;
		blit(fondo,buffer,0,0,0,0,800,600); // IMPRIME FONDO NIVEL 8 BITS
		blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);


// ------------------------------------------------- ZONA 1 BITS -----------------------------------------------------
		if(centinela_1bit==1)
		{
			blit(numero,buffer,0,0,722,290,54,53);
		}
		if(mouse_x > 715 && mouse_x < 780 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_1bit == 0)
			{
				ubicado_1bit=1;
				centinela_1bit=1;
				suma=1;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 1 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 2 BITS -----------------------------------------------------
		if(centinela_2bits==1)
		{
			blit(numero,buffer,0,0,615,290,54,53);
		}

		if(mouse_x > 607 && mouse_x < 673 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_2bits == 0)
			{
				ubicado_2bits=1;
				centinela_2bits=1;
				suma=2;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 2 bits
				suma=0;
			}

		}

// ------------------------------------------------- ZONA 4 BITS -----------------------------------------------------
		if(centinela_4bits==1)
		{
			blit(numero,buffer,0,0,501,290,54,53);
		}
		if(mouse_x > 494 && mouse_x < 559 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_4bits == 0)
			{
				ubicado_4bits=1;
				centinela_4bits=1;
				suma=4;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 4 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 8 BITS -----------------------------------------------------
		if(centinela_8bits==1)
		{
			blit(numero,buffer,0,0,381,290,54,53);
		}
		if(mouse_x > 374 && mouse_x < 439 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_8bits == 0)
			{
				ubicado_8bits=1;
				centinela_8bits=1;
				suma=8;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 8 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 16 BITS -----------------------------------------------------
		if(centinela_16bits==1)
		{
			blit(numero,buffer,0,0,260,290,54,53);
		}
		if(mouse_x > 252 && mouse_x < 318 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_16bits == 0)
			{
				ubicado_16bits=1;
				centinela_16bits=1;
				suma=16;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 16 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 32 BITS -----------------------------------------------------
		if(centinela_32bits==1)
		{
			blit(numero,buffer,0,0,148,290,54,53);
		}
		if(mouse_x > 141 && mouse_x < 206 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_32bits == 0)
			{
				ubicado_32bits=1;
				centinela_32bits=1;
				suma=32;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 32 bits
				suma=0;
			}
		}

// ------------------------------------------------- ZONA 64 BITS -----------------------------------------------------
		if(centinela_64bits==1)
		{
			blit(numero,buffer,0,0,40,290,54,53);
		}
		if(mouse_x > 32 && mouse_x < 98 && mouse_y > 273 && mouse_y < 372)
		{
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if((key[KEY_ENTER] || mouse_b&1) && centinela_64bits == 0)
			{
				ubicado_64bits=1;
				centinela_64bits=1;
				suma=64;
			}
			if(!mouse_b&1)
			{
				respuesta=respuesta+suma; //suma 64 bits
				suma=0;
			}
		}

// --------------------------------------------------------------------------------------------------------------------

		if(mouse_x > 352 && mouse_x < 446 && mouse_y > 450 && mouse_y < 495) // MARCAR IMAGEN OK
		{
			blit(ok,buffer,0,0,352,450,95,46);
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			if(respuesta==numero_planteado)
			{
				respuesta=0;
				blit(win,screen,0,0,0,0,800,600);
				play_sample(correcto, 200, 150, 1000, 0);
				rest(1000);
				clear_bitmap(buffer);
			    clear_bitmap(screen);
				return temporalizador;
		    }
		     else
		     {
		     	 respuesta=0;
				 centinela_1bit,centinela_2bits,centinela_4bits,centinela_8bits,centinela_16bits,centinela_32bits,centinela_64bits=0;
	             ubicado_1bit,ubicado_2bits,ubicado_4bits,ubicado_8bits,ubicado_16bits,ubicado_32bits,ubicado_64bits=0;
			     blit(lose,screen,0,0,0,0,800,600);
			     play_sample(error, 200, 150, 1000, 0);
			     rest(1000);
			     clear_bitmap(buffer);
			     clear_bitmap(screen);
			     return -300;   // si pierde, se le quitan 1500 puntos sobre el record final
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

		blit(buffer,screen,0,0,0,0,800,600); //IMPRIME TODOS LOS EVENTOS EN PANTALLA
		clear_bitmap(buffer);

	} // FIN DE RUTINA

	if(temporalizador==0)
	{
		blit(tiempo_agotado,screen,0,0,0,0,800,600);
		play_sample(error, 200, 150, 1000, 0);
		rest(2000);
		clear_bitmap(buffer);
		clear_bitmap(screen);
		return -100;
	}

}
