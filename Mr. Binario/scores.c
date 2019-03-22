#define NUMERO_PUNTUACIONES 15
#define ANCHO 800
#define ALTO 600

typedef struct _dato
{
	char nombre[101];
	long score;
	int numero_errores;
	int numero_aciertos;

} Tscore;

void login(Tscore jugador, FONT *letras, BITMAP *buffer, BITMAP *cursor, BITMAP *gracias);
void genera_archivo(Tscore jugador);
void scores(FONT *letras, BITMAP *buffer, BITMAP *cursor);

void login(Tscore jugador, FONT *letras, BITMAP *buffer, BITMAP *cursor, BITMAP *gracias)
{

	BITMAP *login = load_bitmap("images\\menu_principal\\login.bmp",NULL);
	int i=0;
	char letra;
	char cadena[30];
	int bandera=0;
	cadena[0]='\0';
	jugador.nombre[0]='\0';
    clear_keybuf();
	while(!key[KEY_ENTER])
	{
		blit(login,buffer,0,0,0,0,ANCHO,ALTO);
		textprintf_ex(buffer, font, 355, 405, 0x000000, -1, "SCORE: %ld", jugador.score);
		textprintf_ex(buffer, font, 345, 440, 0x000000, -1, "CARACTERES RESTANTES: %d", 22-i);
		blit(buffer,screen,0,0,0,0,ANCHO,ALTO);
		do
		{
			blit(login,buffer,0,0,0,0,ANCHO,ALTO);
			textprintf_ex(buffer, font, 337, 373, makecol(0, 0, 0), -1, "%s", jugador.nombre);
			textprintf_ex(buffer, font, 355, 405, 0x000000, -1, "SCORE: %ld", jugador.score);
			textprintf_ex(buffer, font, 302, 440, 0x000000, -1, "CARACTERES RESTANTES: %d", 16-i);
			blit(buffer,screen,0,0,0,0,ANCHO,ALTO);
			letra = readkey();
			if( letra>=65 && letra <=90 || letra>=97 && letra <=122 && letra!=-32 || letra==32 || letra==13||letra!=8)
			{
				letra=toupper(letra);
				cadena[i]=letra;
				jugador.nombre[i]=cadena[i];
				jugador.nombre[i+1]='\0';
				blit(buffer,screen,0,0,0,0,ANCHO,ALTO);
				i++;
				if(i>16)
				{
					bandera=1;
				}
			}
			if(letra==8&&i)
			{
				i--;
				jugador.nombre[i]='\0';
				fflush(stdin);
			}
		} while(letra!=13&&bandera==0);
		textprintf_ex(buffer, font, 337, 373, makecol(0, 0, 0), -1, "%s", jugador.nombre);
		blit(buffer,screen,0,0,0,0,ANCHO,ALTO);
		rest(1200);
		blit(gracias,buffer,0,0,0,0,ANCHO,ALTO);
		blit(buffer,screen,0,0,0,0,ANCHO,ALTO);
		rest(2800);
		break;
	}
	jugador.nombre[i-1]='\0';

	genera_archivo(jugador);
	scores(letras,buffer,cursor);
	clear_bitmap(screen);
	clear_bitmap(buffer);
	destroy_bitmap(login);
}

void genera_archivo(Tscore jugador) // para generar el archivo binario.
{									// Recibe como parametro la estructura que contiene el nombre y score del jugador
	FILE *fd; //PUNTERO AL ARCHIVO
	fd = fopen("scores.bin", "ab"); //APRETURA DEL ARCHIVO BINARIO EN MODO ESCRITURA...
	fwrite(&jugador,sizeof(struct _dato),1,fd); // ESCRITURA DEL NUEVO BLOQUE DE PUNTUACION EN EL ARCHIVO

	// NOTA/ LA ESTRUCTURA jugador ALMACENA EL NOMBRE DEL JUGADOR JUNTO CON SU PUNTUACION...

	fclose(fd); // CIERRE DE ARCHIVO
}

void scores(FONT *letras, BITMAP *buffer, BITMAP *cursor) // imprime los scores en el menu de scores, mostrándolos en orden del mayor al menor
{
	Tscore puntuaciones[1000]; // CADENA DE ESTRUCTURAS QUE SE UTILIZARÁ PARA ALMACENAR LAS ESTRUCTURAS,
	int i,j,k;				   // MOSTRÁNDOLOS EN ORDEN DESENDENTE (MAYOR A MENOR PUNTUACIÓN.
	Tscore registro_scores; // VARIABLE AUXILIAR PARA EL METODO DE ORDENACION (BURBUJA)...

	BITMAP *fondo = load_bitmap("images\\menu_principal\\scores\\scores.bmp",NULL);
	BITMAP *salir = load_bitmap("images\\menu_principal\\scores\\scores_salir.bmp",NULL);

	FILE *fd ; // APERTURA DEL ARCHIVO
	char nombre_archivo[]="scores.bin";
	fd=fopen(nombre_archivo,"rb"); // MODO LECTURA DE ARCHIVO BINARIO

	int mov = 1;
	while(!(mouse_x > 35 && mouse_x < 91 && mouse_y > 460 && mouse_y < 517 && mouse_b&1) && !key[KEY_ESC] && !key[KEY_ENTER] ) // RUTINA
	{
		blit(fondo,buffer,0,0,0,0,ANCHO,ALTO); // CARGA DE IMAGEN FONDO EN BUFFER

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

		blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21); // CARGA DE IMAGEN CURSOR EN BUFFER CON COORDENADAS DE LA POSICION
		i=0;										   // DEL CURSOR
		k=0;
		textprintf_ex(buffer, font, 140, 120, 0x000000, -1, "%s","-------------------------------------------------------------------------------");
		textprintf_ex(buffer, font, 163, 140, 0x000000, -1, "%-15s %-20s %-15s %-10s %-10s", "LUGAR", "NOMBRE", "ACIERTOS","ERRORES","PUNTUACION");
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ORDENAR DATOS ANTES DE MOSTRARLOS EN PANTALLA

		while(fread(&puntuaciones[i], sizeof(struct _dato), 1, fd)) // CUENTA LA CANTIDAD DE PUNTUACIONES REGISTRADOS DE MOMENTO
        {														    // ACCEDIENDO AL ARCHIVO BINARIO...
            i++;
        }
        for (j=0; j<i-1; j++) // UNA VEZ OBTENIDO EL ARREGLO CON LONGITUD i, SE ORDENA Y SE ALMACENA EN MEMORIA ESTÁTICA (BURBUJA)...
        {
            for (k=j+1; k<i; k++) //BURBUJA
            {
                if(puntuaciones[j].score < puntuaciones[k].score) // BURBUJA
                {
                    registro_scores = puntuaciones[j]; //BURBUJA
                    puntuaciones[j] = puntuaciones[k]; //BURBUJA
                    puntuaciones[k] = registro_scores; //BURBUJA
                }
            }
         }
     	fseek(fd, 0, SEEK_SET); // REGRESA AL PRINCIPIO DEL ARCHIVO PARA SU LECTURA.


     	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// UNA VEZ ORDENADOS... SIGUE LA IMPRESIÓN EN PANTALLA

		for (i=0;i<NUMERO_PUNTUACIONES;i++) // LECTURA E IMPRESIÓN EN PANTALLA
        {
        	fseek(fd, i*sizeof(struct _dato), SEEK_SET);
         	if(fread(&registro_scores,sizeof(struct _dato),1,fd)) // MIENTRAS EXISTA UNA ESTRUCTURA EN EL ARCHIVO
            {
            	// IMPRIME EL ARREGLO DE PUNTUACIONES ORDENADAS PREVIAMENTE CON EL METODO BUBUJA (score puntuaciones[])...
            	textprintf_ex(buffer, font, 140, 154+i*25, 0x000000, -1, "%s","-------------------------------------------------------------------------------");
            	textprintf_ex(buffer, font, 175, 165+i*25, 0x000000, -1, "%-5d %-32s %-15d %-10d %-5d", i+1, puntuaciones[i].nombre, puntuaciones[i].numero_aciertos, puntuaciones[i].numero_errores, puntuaciones[i].score);
            	// NOTA: LA INFORMACIÓN EN EL ARCHIVO BINARIO ESTÁ DESORDENADO
            	// LO QUE SE MUESTRA EN PANTALLA ES LA INFORMACIÓN DE EL ARREGLO DE ESTRUCTURAS ALMACENADO EN
            	// MEMORIA ESTÁTICA (puntuaciones[1000] es un arreglo estático).
			}
			textprintf_ex(buffer, font, 140, 154+i*25, 0x000000, -1, "%s","-------------------------------------------------------------------------------");
            fseek(fd,0, SEEK_SET); //  MOVER CURSOR AL INICIO DEL ARCHIVO

        }

		if(mouse_x > 35 && mouse_x < 91 && mouse_y > 460 && mouse_y < 517) // EN CASO DE QUE EL CURSOR ESTÉ EN FLECHA SALIR
		{
			blit(salir,buffer,0,0,0,0,ANCHO,ALTO);
			textprintf_ex(buffer, font, 140, 120, 0x000000, -1, "%s","-------------------------------------------------------------------------------");
			textprintf_ex(buffer, font, 163, 140, 0x000000, -1, "%-15s %-20s %-15s %-10s %-10s", "LUGAR", "NOMBRE", "ACIERTOS","ERRORES","PUNTUACION");
			blit(cursor,buffer,0,0,mouse_x,mouse_y,21,21);
			for (i=0;i<NUMERO_PUNTUACIONES;i++) // LECTURA E IMPRESIÓN EN PANTALLA
       	    {
        		fseek(fd, i*sizeof(struct _dato), SEEK_SET);
         		if(fread(&registro_scores,sizeof(struct _dato),1,fd)) // MIENTRAS EXISTA UNA ESTRUCTURA EN EL ARCHIVO
            	{
            		// IMPRIME EL ARREGLO DE PUNTUACIONES ORDENADAS PREVIAMENTE CON EL METODO BUBUJA (score puntuaciones[])...
            		textprintf_ex(buffer, font, 140, 154+i*25, 0x000000, -1, "%s","-------------------------------------------------------------------------------");
            		textprintf_ex(buffer, font, 175, 165+i*25, 0x000000, -1, "%-5d %-32s %-15d %-10d %-5d", i+1, puntuaciones[i].nombre, puntuaciones[i].numero_aciertos, puntuaciones[i].numero_errores, puntuaciones[i].score);
            		// NOTA: LA INFORMACIÓN EN EL ARCHIVO BINARIO ESTÁ DESORDENADO
            		// LO QUE SE MUESTRA EN PANTALLA ES LA INFORMACIÓN DE EL ARREGLO DE ESTRUCTURAS ALMACENADO EN
            		// MEMORIA ESTÁTICA (puntuaciones[1000] es un arreglo estático).
				}
				textprintf_ex(buffer, font, 140, 154+i*25, 0x000000, -1, "%s","-------------------------------------------------------------------------------");
            	fseek(fd,0, SEEK_SET); //  MOVER CURSOR AL INICIO DEL ARCHIVO
        	}
		}
		textprintf_ex(buffer, font, 140, 154+i*25, 0x000000, -1, "%s","-------------------------------------------------------------------------------");
		blit(buffer,screen,0,0,0,0,ANCHO,ALTO); //IMPRIME BUFFER FINAL..
		clear_bitmap(buffer); // LIMPIA BUFFER...
	}
	fclose(fd);	// CIERRE DE ARCHIVO

	destroy_bitmap(fondo);
	destroy_bitmap(salir);
}
