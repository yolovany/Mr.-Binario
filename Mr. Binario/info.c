#define TRANSICION 500

void acerca_de(BITMAP *buffer, BITMAP *cursor);
void how_to_play(BITMAP *buffer, int modo_vista);

void acerca_de(BITMAP *buffer, BITMAP *cursor)
{
	BITMAP *acerca_de = load_bitmap ("images\\menu_principal\\acerca_de\\acerca_de.bmp",NULL);
	BITMAP *acerca_de_volver = load_bitmap ("images\\menu_principal\\acerca_de\\acerca_de_volver.bmp",NULL);

    int mov = 1;
	while(!(mouse_x > 20 && mouse_x < 144 && mouse_y > 527 && mouse_y < 566 && mouse_b&1 ) && !key[KEY_ENTER] )
	{
		blit(acerca_de,buffer,0,0,0,0,800,600);

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
		if(mouse_x > 20 && mouse_x < 144 && mouse_y > 527 && mouse_y < 566)
		{
			blit(acerca_de_volver,buffer,0,0,0,0,800,600);
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
		}
		blit(buffer,screen,0,0,0,0,800,600);
		clear_bitmap(buffer);
	}
	destroy_bitmap(acerca_de);
	destroy_bitmap(acerca_de_volver);
}

void how_to_play(BITMAP *buffer, int modo_vista)
{
	clear_keybuf();
	if(modo_vista==AUTOMATICO)
	{
		int i=TRANSICION;
		BITMAP *instruccion1 = load_bitmap("images\\how_to_play\\instruccion1.bmp", NULL);
		BITMAP *instruccion2 = load_bitmap("images\\how_to_play\\instruccion2.bmp", NULL);
		BITMAP *instruccion3 = load_bitmap("images\\how_to_play\\instruccion3.bmp", NULL);
		BITMAP *instruccion4 = load_bitmap("images\\how_to_play\\instruccion4.bmp", NULL);
		BITMAP *instruccion5 = load_bitmap("images\\how_to_play\\instruccion5.bmp", NULL);
		BITMAP *instruccion6 = load_bitmap("images\\how_to_play\\instruccion6.bmp", NULL);
		BITMAP *instruccion7 = load_bitmap("images\\how_to_play\\instruccion7.bmp", NULL);
		BITMAP *instruccion8 = load_bitmap("images\\how_to_play\\instruccion8.bmp", NULL);
		BITMAP *demostracion = load_bitmap("images\\menu_principal\\menu_hello.bmp", NULL);

		int posicion_x=mouse_x;
		int posicion_y=mouse_y;
		while(posicion_x==mouse_x&&posicion_y==mouse_y)
		{
			blit(demostracion,buffer,0,0,0,i,800,600); //imprime fondo documento en buffer, avanza conforme i
			blit(buffer,screen,0,0,0,0,800,600);
			for(i=600;i>=0;i--) // transcición apertura de documento
			{
				blit(demostracion,buffer,0,0,0,i-600,800,600);
				blit(instruccion1,buffer,0,0,0,i,800,600); //imprime fondo documento en buffer, avanza conforme i
				blit(buffer,screen,0,0,0,0,800,600);
				if(posicion_x!=mouse_x&&posicion_y!=mouse_y)
				{
					destroy_bitmap(instruccion1);
					destroy_bitmap(instruccion2);
					destroy_bitmap(instruccion3);
					destroy_bitmap(instruccion4);
					destroy_bitmap(instruccion5);
					destroy_bitmap(instruccion6);
					destroy_bitmap(instruccion7);
					destroy_bitmap(instruccion8);
					destroy_bitmap(demostracion);
					return;
				}
			}
			rest(400);
			i=TRANSICION;
			do
			{
				i--;
				blit(instruccion1,buffer,0,0,0,0,800,600);
				blit(buffer,screen,0,0,0,0,800,600);
				if(posicion_x!=mouse_x&&posicion_y!=mouse_y)
				{
					destroy_bitmap(instruccion1);
					destroy_bitmap(instruccion2);
					destroy_bitmap(instruccion3);
					destroy_bitmap(instruccion4);
					destroy_bitmap(instruccion5);
					destroy_bitmap(instruccion6);
					destroy_bitmap(instruccion7);
					destroy_bitmap(instruccion8);
					destroy_bitmap(demostracion);
					return;
				}
			}while(i!=0);
			deinit();
			for(i=600;i>=0;i--) // transcición apertura de documento
			{
				blit(instruccion1,buffer,0,0,0,i-600,800,600);
				blit(instruccion2,buffer,0,0,0,i,800,600); //imprime fondo documento en buffer, avanza conforme i
				blit(buffer,screen,0,0,0,0,800,600);
				if(posicion_x!=mouse_x&&posicion_y!=mouse_y)
				{
					destroy_bitmap(instruccion1);
					destroy_bitmap(instruccion2);
					destroy_bitmap(instruccion3);
					destroy_bitmap(instruccion4);
					destroy_bitmap(instruccion5);
					destroy_bitmap(instruccion6);
					destroy_bitmap(instruccion7);
					destroy_bitmap(instruccion8);
					destroy_bitmap(demostracion);
					return;
				}
			}
			i=TRANSICION;
			do
			{
				i--;
				blit(instruccion2,buffer,0,0,0,0,800,600);
				blit(buffer,screen,0,0,0,0,800,600);
				if(posicion_x!=mouse_x&&posicion_y!=mouse_y)
				{
					destroy_bitmap(instruccion1);
					destroy_bitmap(instruccion2);
					destroy_bitmap(instruccion3);
					destroy_bitmap(instruccion4);
					destroy_bitmap(instruccion5);
					destroy_bitmap(instruccion6);
					destroy_bitmap(instruccion7);
					destroy_bitmap(instruccion8);
					destroy_bitmap(demostracion);
					return;
				}
			}while(i!=0);
			deinit();
			rest(200);
			i=TRANSICION;
			do
			{
				i--;
				blit(instruccion3,buffer,0,0,0,0,800,600);
				blit(buffer,screen,0,0,0,0,800,600);
				if(posicion_x!=mouse_x&&posicion_y!=mouse_y)
				{
					destroy_bitmap(instruccion1);
					destroy_bitmap(instruccion2);
					destroy_bitmap(instruccion3);
					destroy_bitmap(instruccion4);
					destroy_bitmap(instruccion5);
					destroy_bitmap(instruccion6);
					destroy_bitmap(instruccion7);
					destroy_bitmap(instruccion8);
					destroy_bitmap(demostracion);
					return;
				}
			}while(i!=0);
			deinit();
			rest(200);
			i=TRANSICION;
			do
			{
				i--;
				blit(instruccion4,buffer,0,0,0,0,800,600);
				blit(buffer,screen,0,0,0,0,800,600);
				if(posicion_x!=mouse_x&&posicion_y!=mouse_y)
				{
					destroy_bitmap(instruccion1);
					destroy_bitmap(instruccion2);
					destroy_bitmap(instruccion3);
					destroy_bitmap(instruccion4);
					destroy_bitmap(instruccion5);
					destroy_bitmap(instruccion6);
					destroy_bitmap(instruccion7);
					destroy_bitmap(instruccion8);
					destroy_bitmap(demostracion);
					return;
				}
			}while(i!=0);
			deinit();
			rest(200);
			i=TRANSICION;
			do
			{
				i--;
				blit(instruccion5,buffer,0,0,0,0,800,600);
				blit(buffer,screen,0,0,0,0,800,600);
				if(posicion_x!=mouse_x&&posicion_y!=mouse_y)
				{
					destroy_bitmap(instruccion1);
					destroy_bitmap(instruccion2);
					destroy_bitmap(instruccion3);
					destroy_bitmap(instruccion4);
					destroy_bitmap(instruccion5);
					destroy_bitmap(instruccion6);
					destroy_bitmap(instruccion7);
					destroy_bitmap(instruccion8);
					destroy_bitmap(demostracion);
					return;
				}
			}while(i!=0);
			deinit();
			rest(200);
			i=TRANSICION;
			do
			{
				i--;
				blit(instruccion6,buffer,0,0,0,0,800,600);
				blit(buffer,screen,0,0,0,0,800,600);
				if(posicion_x!=mouse_x&&posicion_y!=mouse_y)
				{
					destroy_bitmap(instruccion1);
					destroy_bitmap(instruccion2);
					destroy_bitmap(instruccion3);
					destroy_bitmap(instruccion4);
					destroy_bitmap(instruccion5);
					destroy_bitmap(instruccion6);
					destroy_bitmap(instruccion7);
					destroy_bitmap(instruccion8);
					destroy_bitmap(demostracion);
					return;
				}
			}while(i!=0);
			deinit();
			rest(200);
			i=TRANSICION;
			do
			{
				i--;
				blit(instruccion7,buffer,0,0,0,0,800,600);
				blit(buffer,screen,0,0,0,0,800,600);
				if(posicion_x!=mouse_x&&posicion_y!=mouse_y)
				{
					destroy_bitmap(instruccion1);
					destroy_bitmap(instruccion2);
					destroy_bitmap(instruccion3);
					destroy_bitmap(instruccion4);
					destroy_bitmap(instruccion5);
					destroy_bitmap(instruccion6);
					destroy_bitmap(instruccion7);
					destroy_bitmap(instruccion8);
					destroy_bitmap(demostracion);
					return;
				}
			}while(i!=0);
			deinit();
			rest(200);
			i=TRANSICION;
			do
			{
				i--;
				blit(instruccion8,buffer,0,0,0,0,800,600);
				blit(buffer,screen,0,0,0,0,800,600);
				if(posicion_x!=mouse_x&&posicion_y!=mouse_y)
				{
					destroy_bitmap(instruccion1);
					destroy_bitmap(instruccion2);
					destroy_bitmap(instruccion3);
					destroy_bitmap(instruccion4);
					destroy_bitmap(instruccion5);
					destroy_bitmap(instruccion6);
					destroy_bitmap(instruccion7);
					destroy_bitmap(instruccion8);
					destroy_bitmap(demostracion);
					return;
				}
			}while(i!=0);
			rest(500);
			deinit();
			for(i=600;i>=0;i--) // transcición apertura de documento
			{
				blit(instruccion8,buffer,0,0,0,i-600,800,600);
				blit(demostracion,buffer,0,0,0,i,800,600); //imprime fondo documento en buffer, avanza conforme i
				blit(buffer,screen,0,0,0,0,800,600);
				if(posicion_x!=mouse_x&&posicion_y!=mouse_y)
				{
					destroy_bitmap(instruccion1);
					destroy_bitmap(instruccion2);
					destroy_bitmap(instruccion3);
					destroy_bitmap(instruccion4);
					destroy_bitmap(instruccion5);
					destroy_bitmap(instruccion6);
					destroy_bitmap(instruccion7);
					destroy_bitmap(instruccion8);
					destroy_bitmap(demostracion);
					return;
				}
			}
			rest(2500);
		}
	}
	if(modo_vista==MANUAL)
	{
		int i;
		BITMAP *instruccion1 = load_bitmap("images\\how_to_play\\instruccion1.bmp", NULL);
		BITMAP *instruccion2 = load_bitmap("images\\how_to_play\\instruccion2.bmp", NULL);
		BITMAP *instruccion3 = load_bitmap("images\\how_to_play\\instruccion3.bmp", NULL);
		BITMAP *instruccion4 = load_bitmap("images\\how_to_play\\instruccion4.bmp", NULL);
		BITMAP *instruccion5 = load_bitmap("images\\how_to_play\\instruccion5.bmp", NULL);
		BITMAP *instruccion6 = load_bitmap("images\\how_to_play\\instruccion6.bmp", NULL);
		BITMAP *instruccion7 = load_bitmap("images\\how_to_play\\instruccion7.bmp", NULL);
		BITMAP *instruccion8 = load_bitmap("images\\how_to_play\\instruccion8.bmp", NULL);

		do
		{
			blit(instruccion1,buffer,0,0,0,0,800,600);
			blit(buffer,screen,0,0,0,0,800,600);
		}while( !key[KEY_ENTER] && !mouse_b&1);
		deinit();
		for(i=600;i>=0;i=i-2) // transcición apertura de documento
		{
			blit(instruccion1,buffer,0,0,0,i-600,800,600);
			blit(instruccion2,buffer,0,0,0,i,800,600); //imprime fondo documento en buffer, avanza conforme i
			blit(buffer,screen,0,0,0,0,800,600);
		}
		do
		{
			blit(instruccion2,buffer,0,0,0,0,800,600);
			blit(buffer,screen,0,0,0,0,800,600);
		}while( !key[KEY_ENTER] && !mouse_b&1);
		deinit();
		rest(200);
		do
		{
			blit(instruccion3,buffer,0,0,0,0,800,600);
			blit(buffer,screen,0,0,0,0,800,600);
		}while( !key[KEY_ENTER] && !mouse_b&1);
		deinit();
		rest(200);
		do
		{
			blit(instruccion4,buffer,0,0,0,0,800,600);
			blit(buffer,screen,0,0,0,0,800,600);
		}while( !key[KEY_ENTER] && !mouse_b&1);
		deinit();
		rest(200);
		do
		{
			blit(instruccion5,buffer,0,0,0,0,800,600);
			blit(buffer,screen,0,0,0,0,800,600);
		}while( !key[KEY_ENTER] && !mouse_b&1);
		deinit();
		rest(200);
		do
		{
			blit(instruccion6,buffer,0,0,0,0,800,600);
			blit(buffer,screen,0,0,0,0,800,600);
		}while( !key[KEY_ENTER] && !mouse_b&1);
		deinit();
		rest(200);
		do
		{
			blit(instruccion7,buffer,0,0,0,0,800,600);
			blit(buffer,screen,0,0,0,0,800,600);
		}while( !key[KEY_ENTER] && !mouse_b&1);
		deinit();
		rest(200);
		do
		{
			blit(instruccion8,buffer,0,0,0,0,800,600);
			blit(buffer,screen,0,0,0,0,800,600);
		}while( !key[KEY_ENTER] && !mouse_b&1);
		rest(200);
		deinit();
		destroy_bitmap(instruccion1);
		destroy_bitmap(instruccion2);
		destroy_bitmap(instruccion3);
		destroy_bitmap(instruccion4);
		destroy_bitmap(instruccion5);
		destroy_bitmap(instruccion6);
		destroy_bitmap(instruccion7);
		destroy_bitmap(instruccion8);
	}

}

