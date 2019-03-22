#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
////////////////////////////////////////////////////////////////////////////////        
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7
#define H 8
#define I 9
#define J 10
#define K 11
#define L 12
#define M 13
#define N 14
#define O 15
#define P 16
#define Q 17
#define R 18
#define S 19
#define T 20
#define U 21
#define V 22
#define W 23
#define X 24
#define Y 25
#define Z 26
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct tdato{
        char nombre[30];
        char appat[30];
        char apmat[30]; 
        char palabra[30];
        char sexo[9];     
        int edad;
        int dato;
        int aski;
        int stat;
        long matri;
        struct tdato *sig;   
        }Tdato;  
typedef Tdato *Tnodo;      


Tnodo Eliminar(Tnodo *lista, int num);
Tnodo EliminarLCD(Tnodo *listaC, Tnodo *fin,int num);
Tnodo EliminarLCA(Tnodo *listaC, Tnodo *fin, long matri);
Tnodo EliminarLP(Tnodo *lista, char* palabra);
Tnodo EliminarLCP(Tnodo *listaC,Tnodo *fin, char* palabra);
Tnodo eliminar_LC(Tnodo *listaC,int num,Tnodo *fin);

int BuscarL(Tnodo *lista, int busqueda);
int BuscarLCA(Tnodo *listaC, Tnodo *fin,long matri);
Tnodo buscarLCP(Tnodo *listaC, char *palabra);

Tnodo AgregarLCA(Tnodo *listaC, Tnodo *nuevo, Tnodo *fin);
Tnodo AgregarLC(Tnodo *listaC, Tnodo *nuevo, Tnodo *fin);
Tnodo Agregar(Tnodo *lista, Tnodo *nuevo);
Tnodo AgregarTXT(Tnodo *lista, Tnodo *nuevo);
Tnodo AgregarpalabraLCP(Tnodo *listaC, Tnodo *nuevo, Tnodo *fin);

void LeerListaS(Tnodo *lista);
void LeerListaC(Tnodo *listaC);
void LeerListaCP(Tnodo *listaC);

void Servicio(Tnodo temp);
void ServicioA(Tnodo temp);
void ServicioL(Tnodo temp);
void ServicioP(Tnodo temp);

void LiberarmemoriaLCA(Tnodo *listaC);
void LiberarmemoriaLCP(Tnodo *listaC);

Tnodo llenaDatos(void);
Tnodo llenaDatosA(void);
Tnodo llenaDatosTxt(char* palabra);


void PUSH_S(Tnodo *pila, Tnodo *nuevo);
Tnodo POP_S(Tnodo *pila);
Tnodo POP_Q(Tnodo *cola, Tnodo *ultimo);
Tnodo POP_Q(Tnodo *cola, Tnodo *ultimo);

int ValidaRepetidos (Tnodo *listaC, char *palabra, Tnodo *fin);
char* leecadena (char*msge);  
int validanum(int n1, int n2, char *msge, char *merror);  
void validaaski(Tnodo *palabra);
void delay(int tiempo);
void Generartxt(Tnodo *lista,Tnodo *fin);

///////////////////////////Listas Circulares DATO//////////////////////////////////////////////////////////////////////////////////////////////////
Tnodo AgregarLC(Tnodo *listaC, Tnodo *nuevo, Tnodo *fin)
{
    Tnodo temp=NULL,nodo=NULL;
    if(!(*listaC))
    {
        *listaC=*nuevo;
        *fin=*listaC;
        (*fin)->sig=*listaC;      
    }
    else
    {     
        if((*nuevo)->dato< (*listaC)->dato)
        {
            (*nuevo)->sig=*listaC;
            *listaC=*nuevo;
            (*fin)->sig=*listaC;                                                    
        }
        else
        {
            temp=*listaC;
            while(temp!=*fin && (temp->sig)->dato <= (*nuevo)->dato)
            {           
                temp=(temp->sig);                       
            }                  
            if((temp->dato)==(*nuevo)->dato)
            {                                          
                return *nuevo;                                                                     
            }     
            else
            {
                (*nuevo)->sig=(temp->sig);
                (temp->sig)=*nuevo;
                if(temp==*fin)
                {
                    *fin=*nuevo;          
                }
                return nodo;  
            }                              
        }          
    } 
}

Tnodo EliminarLCD(Tnodo *listaC, Tnodo *fin, int num)
{
    Tnodo temp=NULL,nodo=NULL;
    temp=*listaC;
	if(!(*listaC))              
    {
        return nodo;                  
    }  
    else
    {
    	if((*listaC)->dato==num)
        {
        	if((*listaC)==*fin)
            {
                nodo=*listaC;
                *listaC=NULL;
                *fin=NULL;
                return nodo;            
            }            
            else
            {
                nodo=*listaC;
                *listaC=(*listaC)->sig;
                (*fin)->sig=*listaC;           
            }                
        } 
        else
    	{
            while(temp!=(*fin) && (temp->sig)->dato < num)
            {
                temp=(temp->sig);
            }    
            if((temp->sig)->dato==num)
            {
                nodo=(temp->sig);
                temp=(nodo->sig);
                return nodo;            
            }                    
        }      
                  
    } 
    return nodo;              
}               

Tnodo AgregarLCA(Tnodo *listaC, Tnodo *nuevo, Tnodo *fin)
{
    Tnodo temp=NULL,nodo=NULL;
    if(!(*listaC))
    {
        *listaC=*nuevo;
        *fin=*listaC;
        (*fin)->sig=*listaC;                              
    }
    else
    {     
        if((*nuevo)->matri <(*listaC)->matri)
        {
            (*nuevo)->sig=*listaC;
            *listaC=*nuevo;
            (*fin)->sig=*listaC;                                                    
        }
        else
        {
            temp=*listaC;
            while(temp!=*fin && (temp->sig)->matri <= (*nuevo)->matri)
            {           
                temp=(temp->sig);                       
            }                  
            if((temp->matri)==(*nuevo)->matri)
            {                                          
                return *nuevo;                                                                     
            }     
            else
            {
                (*nuevo)->sig=(temp->sig);
                (temp->sig)=*nuevo;
                if(temp==*fin)
                {
                    *fin=*nuevo;          
                }
                return nodo;  
            }                              
        }          
    }
    return nodo;  
}        
       
Tnodo EliminarLCA(Tnodo *listaC,Tnodo *fin, long matricula)
{
	Tnodo nodo=NULL;
   	nodo=*listaC;

	do 
   {
      	if(((*listaC)->sig)->matri != matricula) 
	  	{
	  		*listaC = (*listaC)->sig;
		}
   	}while(((*listaC)->sig)->matri != matricula && *listaC != nodo);
  
   if(((*listaC)->sig)->matri == matricula) 
   {
      
      if(*listaC == (*listaC)->sig) 
	  {
        
        nodo=*listaC;
        *listaC=NULL;
        *fin=NULL;  
        return *listaC;
      }
      else 
	  {
         
        nodo = (*listaC)->sig;
        (*listaC)->sig = nodo->sig;
        return nodo;
      }
   }
   return nodo;           
}

int BuscarLCA(Tnodo *listaC, Tnodo *fin,long matri)
{
    int cont=0;              
    Tnodo temp=NULL,nodo=NULL;
    temp=*listaC;
    if(temp)
    {
    	do
		{
            cont=cont+1;
            if(temp && (temp)->matri == matri )
            {
                return cont;
            }
            temp=(temp->sig);
        }while(temp != *listaC);      
    }    
    return 0;    
}   
            
void LeerListaC(Tnodo *listaC)
{
    Tnodo temp=NULL;  
    temp=*listaC;
    if (temp)
    {
        do
		{
            ServicioA(temp);
            temp=(temp->sig);
        } 
        while(temp != *listaC);
    }                       
}   

Tnodo AgregarpalabraLCP(Tnodo *listaC, Tnodo *nuevo, Tnodo *fin)
{
    Tnodo temp=NULL,nodo=NULL;
	if(!(*listaC))
    {
        *listaC=*nuevo;
        *fin=*listaC;
        (*fin)->sig=*listaC;                                
    }
    else
    {     
        if((*nuevo)->aski <(*listaC)->aski)
        {
            (*nuevo)->sig=*listaC;
            *listaC=*nuevo;
            (*fin)->sig=*listaC;                                                    
        }
        else
        {
            temp=*listaC;
            while(temp!=*fin && (temp->sig)->aski <= (*nuevo)->aski)
            {           
                temp=(temp->sig);                       
            }                  
            if((temp->aski)==(*nuevo)->palabra[0])
            {                                          
                return *nuevo;                                                                     
            }     
            else
            {
                (*nuevo)->sig=(temp->sig);
                (temp->sig)=*nuevo;
                if(temp==*fin)
                {
                    *fin=*nuevo;          
                }
                return nodo;  
            }                              
        }          
    }
	return nodo;  	
}
    
void LeerListaCP(Tnodo *listaC)
{
    Tnodo temp=NULL;  
    temp=*listaC;
    if (temp)
    {
        do
		{
            ServicioP(temp);
            temp=(temp->sig);                                 
        } 
        while(temp != *listaC);
    }                       
}    
         
Tnodo buscarLCP(Tnodo *listaC, char *palabra)
{
	Tnodo temp=NULL,nodo=NULL;
	if(*listaC)
	{
		temp=*listaC;
		
		do{
			if(strcmp((temp->palabra),palabra)==0) 
			{
				return temp;
			}
			temp=(temp->sig);
		}while(temp != *listaC);
	}
	return nodo;
}

Tnodo eliminar_LC(Tnodo *listaC,int num,Tnodo *fin)
{
	Tnodo temp=NULL, nodo=NULL;
	temp=*listaC;	
	if(!(*listaC))
	{
		return nodo;
	}
	else
	{
		if((*listaC)->dato == num)
		{
			if(*listaC == *fin)
			{
				nodo=*listaC;
				*listaC=NULL;
				*fin=NULL;
				return nodo;
			}
			else
			{
				nodo=*listaC;
				*listaC=nodo->sig;
				(*fin)->sig=*listaC;
				nodo->sig=NULL;
				
				return nodo;
			}
		}
		else
		{
			while(temp != *fin && (temp->sig)->dato < num)
			{
				temp=temp->sig;
			}
			if((temp->sig)->dato == num)
			{
				if(temp->sig == *fin)
				{
					*fin =temp;
				}
				nodo = (temp->sig);
				temp->sig=nodo->sig;
				nodo->sig=NULL;
				return nodo;
			}
			else
			{
				return nodo;
			}
		}	
	}
}


Tnodo EliminarLCP(Tnodo *listaC,Tnodo *fin, char* palabra)
{
    Tnodo temp=NULL,nodo=NULL;
    temp=*listaC;
    if(!(*listaC))              
    {
        return nodo;                  
    }  
    else
    {
    	if(strcmp(palabra,(*listaC)->palabra)==0)
        {
            if((*listaC)==*fin)
            {
                nodo=*listaC;
                *listaC=NULL;
                *fin=NULL;
                return nodo;            
            }            
            else
            {
                nodo=*listaC;
                *listaC=(*listaC)->sig;
                (*fin)->sig=*listaC;           
            }                                         
        } 
        else
        {
            while(temp!=(*fin) && temp->sig&&strcmp(palabra,temp->sig->palabra)>0||strcmp(palabra,(temp->sig)->palabra)<0 )
            {
                temp=(temp->sig);
            }    
            if(strcmp(nodo->palabra,palabra)==0)
            {
                nodo=(temp->sig);
                temp=(nodo->sig);   
            	return nodo; 
                                                       
            }                       
    	}                
    } 
    return nodo;                   
}     

//////////////////////////////////////////////////////////////////////////Listas SIMPLES///////////
Tnodo Agregar(Tnodo *lista, Tnodo *nuevo)
{
    Tnodo temp=NULL,nodo=NULL;
    temp=*lista;
    if(temp && (*nuevo)->dato>=(temp->dato))
    {
    	while(temp->sig && (temp->sig)->dato < (*nuevo)->dato )
        {
        	temp=(temp->sig);
                   
        }
        if((*nuevo)->dato==(temp->dato))
        {   
            return *nuevo;
        }                 
        (*nuevo)->sig=(temp->sig);
        (temp->sig)=*nuevo;
        return nodo;
    } 
    (*nuevo)->sig=*lista;
    *lista=*nuevo;
    return nodo; 
                     
}
Tnodo Eliminar(Tnodo *lista, int num)
{
    Tnodo temp=NULL,nodo=NULL;
    if(!(lista))
    {
    	return nodo;
    }
    else
    {
        temp=*lista;
        if(num==(*lista)->dato)
        {
            *lista=(temp->sig);
            (temp->sig)=NULL;
            return temp;
        }
        else
        {
            while((temp->sig) && (temp->sig)->dato < num)
            {
                temp=(temp->sig);
            }
            nodo=(temp->sig);
        }    
        if(nodo && (nodo->dato)==num)
        {
            (temp->sig)=(nodo->sig);
            (nodo->sig)=NULL;
            return nodo;    
        }
        else
    	{
            nodo=NULL;            
        } 
        return nodo;
    }                                    
}      
int BuscarL(Tnodo *lista, int busqueda)
{
    int cont=0,aux;
    Tnodo temp=NULL;
    if(*lista)
    {
        temp=*lista;
    	while(temp && (temp->dato))
        { 
            cont++;
            if(busqueda==(temp->dato))
            {                    
            	return cont;                                                       
            }
            if(temp==NULL)
            {
                cont=-1;
                return cont;
            }  
            temp=(temp->sig);  
    	}                       
    }   
}      
      
void LeerListaS(Tnodo *lista)  
{  
    Tnodo temp=NULL;   
    if(*lista)
    {
        temp=*lista;
        while(temp)
        {
            ServicioL(temp); 
            temp=(temp->sig);                                     
        }
    }
    else
    {
        printf("Lista Vacia\n");
        system("PAUSE");
    }  
}        
///////////////////////////////////////////Lista Simple Palabras////////////
Tnodo AgregarTXT(Tnodo *lista, Tnodo *nuevo)
{
	Tnodo temp=NULL;
	Tnodo nodo=NULL;
	int i=0;
	temp=*lista;
	if(temp&&(*nuevo)->palabra[i]>=temp->palabra[i])
	{
        
		while(temp->sig&&(temp->sig)->palabra[i]<(*nuevo)->palabra[i])
		{
			
	
		  if((*nuevo)->palabra[i]==temp->palabra[i])
		    {
			return *nuevo;
		    }
		    
		    temp=temp->sig;
		}
		
		(*nuevo)->sig=temp->sig;
		temp->sig=*nuevo;
		return nodo;
	}
	(*nuevo)->sig=*lista;
	*lista=*nuevo;
	return nodo;
	
}
Tnodo EliminarLP(Tnodo *lista, char* palabra)
{
    Tnodo temp=NULL,nodo=NULL;
    if(!(lista))
    {
        return nodo;
    }
    else
    {
        temp=*lista;
        if(palabra[0]==(*lista)->palabra[0])
        {
            *lista=(temp->sig);
        	(temp->sig)=NULL;
        	return temp;
        }
        else
        {
        	while((temp->sig) && (temp->sig)->palabra[0] != palabra[0])
            {
                temp=(temp->sig);
            }
            nodo=(temp->sig);
    	}  
        if(nodo && (nodo->palabra[0])==palabra[0])
        {
            (temp->sig)=(nodo->sig);
            (nodo->sig)=NULL;
            return nodo;        
        }
        else
        {
            nodo=NULL;
        } 
        return nodo;  
    }
}        
////////////////Liberacion de memoria Listas Circulares////////////////////////                   
void LiberarmemoriaLCA(Tnodo *listaC)  
{  
    Tnodo temp=NULL;   
    if(*listaC)
    {
        temp=*listaC;
        do
		{
            ServicioA(temp); 
            delay(100);
            free(temp);
            temp=(temp->sig);       
                                                
        }while(*listaC && temp != *listaC);
	}
    printf("MEMORIA LIBERADA");  
                            
}                            
void LiberarmemoriaLCP(Tnodo *listaC)  
{  
	Tnodo temp=NULL;   
    if(*listaC)
    {
    	temp=*listaC;
    	do
		{
    		ServicioP(temp); 
        	delay(50);
        	free(temp);
        	temp=(temp->sig);       
        }while(*listaC && temp != *listaC);           
	}
    printf("MEMORIA LIBERADA");  
}    
//////////////////////////////SERVICIOS///////////////////////////////////////////

void Servicio(Tnodo temp)
{
    printf("%d \n",(temp->dato));    
}    
    
void ServicioA(Tnodo temp)
{
    printf("Nombre :%s \n",(temp->nombre));
    printf("Apellido Paterno :%s \n",(temp->appat));
    printf("Apellido Materno :%s \n",(temp->apmat));
    printf("Sexo :%s \n",(temp->sexo));
    printf("Edad :%d \n",(temp->edad));
    printf("Status: %d \n",(temp->stat));
    printf("Matricula: %ld \n",(temp->matri));              
    printf("--\n");  
} 
void ServicioL(Tnodo temp)
{         
    printf("%s \n",(temp->palabra));               
}
void ServicioP(Tnodo temp)
{         
    printf("%s \n",(temp->palabra));               
}         
           
////////////LLENA DATOS, CREACION DE MEMORIA CON MALLOC///////////////////    
Tnodo llenaDatosTxt(char* palabra)
{
    Tnodo nodo=NULL;
    nodo=(Tnodo)malloc(sizeof(Tdato));
    (nodo)->sig=NULL;
    strcpy(nodo->palabra,palabra);       
    return nodo; 
}

 
    
Tnodo llenaDatos(void)
{
	Tnodo nodo=NULL;
    nodo=(Tnodo)malloc(sizeof(Tdato));
    nodo->sig=NULL;
    nodo->dato=rand()%3000+1;
    return nodo;
}      
      
Tnodo llenaDatosA(void)
{
    Tnodo nodo=NULL;
    nodo=(Tnodo)malloc(sizeof(Tdato));
    (nodo)->sig=NULL;
    int sexo;
    char NombreFem[40][30]={" CECILIA"," LILIANA"," LIDIA"," KAREN"," MARIA"," ITZEL"," DENISSE"," PATRICIA"," MELISSA"," YURIANA"," JASMIN"," CASSANDRA"," YULISA"," YESENIA"," DANIELA"," ALEJANDRA"," LUZ"," ERIKA"," JACKELINE"," SOL"," MARIANA"," ELSA"," CAROLINA"," KARINA"," MIRANDA"," DULCE"," CARMEN"," CATALINA"," SARAI"," REBECA"," SALMA"," TAMARA", " ZULEMA"," SELENE"," MIRIAN"," ANDREA"," MONICA"," BLANCA"," ROSA", " GENESIS"};
    char NombreMas[140][30]={" GABRIEL"," RAFAEL"," BRANDON"," COMBO"," ERICK"," EDGAR"," MESSI"," HECTOR"," IGOR"," JOVANNY"," JOHANN"," ROMULO"," PEDRO"," DAVID"," BERNARDO"," ENRIQUE"," MARCO"," GERARDO"," RICARDO"," JHONATHAN"," ALBERTO"," LUIS"," GUILLERMO"," LUIS"," VALENTIN", " ALAN"," OSCAR"," ANTONIO"," JAVIER"," ISMAEL"," IVAN"," CESAR"," ALEJANDRO"," RENE"," CALEB"," MARIO"," LUIGI"," AARON"," DIEGO"," ELBRAYAN", " ADAN","ADELIO ","ADRIANO ","AGUSTIN ","ALANZO ","ALBERTO ","ALEJANDRO ","ALFONSO ","ALFREDO ","ALONSO ","ALVARO ","ALVINO ","AMADEO ","AMADO ","ANDREO ","ANDRES ","ANGEL ","ANGELINO ","ANGELITO ","ANGELO ","ANIBAL ","ANTONIO ","AQUILA ","AQUILINO ","ARCHIBALDO ","ARLO ","ARMANDO ","ARNOLDO ","ARTURO ","AURELIO ","BARTOLO ","BELTRAN ","BEMABE ","BENEDICTO ","BERNARDO ","BERTO ","BLANCO ","CALVINO ","CARLOS ","CESAR ","CHAVEZ ","CHAYO ","CICERON ","CLAUDIO ","CONSTANTINO ","CORNELIO ","CORTEZ ","CRISTIAN ","CRISTIANO ","CRISTOBAL ","CRISTOPHER ","DARIO ","EDUARDO ","EFRAIN ","ELIAS ","ELOY ","ELVIO ","EMANUEL ","EMILIO ","ENRIQUE ","ERASMO ","ERNESTO ","ESEQUIEL ","ESTEBAN ","ESTEFAN ","ESTEVAN ","EUGENIO ","EVERARDO ","EZEQUIEL ","FAUSTO ","FEDERICO ","FELIPE ","FELIX ","FERMIN ","FERNANDO ","FIDEL ","FLORINIO ","FRANCISCO ","FRESCO ","GABRIEL ","GALTERO ","GASPAR ","GERARDO ","GERMAN ","GILBERTO ","GREGORIO ","GUADALUPE ","GUILLERMO ","GUSTAVO ","HECTOR ","ABRAHAM ","HERIBERTO ","HERNAN ","HIDALGO ","HUGO ","HUMBERTO ","JAVIER ","JUAQUIN ","JORGE ","OSCAR "};
    char Apellido[50][30]={" MELCHOR"," YEPIZ"," GUERRERO"," BELTRAN"," CORTEZ"," CRUZ"," DIAZ"," DOMINGUEZ"," SALAZAR"," ESTRADA"," FLORES"," FERNANDEZ"," GONZALEZ"," GOMEZ"," JHONSON"," HUERTA"," INFANTE"," IGLESIAS"," JIMENEZ"," JUAREZ"," LOPEZ"," LEON"," MARTINEZ"," MORENO"," NAVARRO"," NIETO"," ORTIZ"," OJEDA"," PEREZ"," PINEDA"," QUINTANA"," QUESADA"," RAMIREZ"," RODRIGUEZ"," SANCHEZ"," SANTANA"," TORRES"," TRUJILLO"," URIBE"," URBANO"," VEGA"," VIDAL"," ZAVALA"," ZAPATA"," GALINDO"," GARCIA"," ACOSTA"," AGUILERA"," WILLIAMS"," EZEQUIAZ"};
    sexo=(rand()%2)+1;
          
    if (sexo==1)
    {
        strcpy(nodo->nombre,NombreMas[(rand()%140)]);
        strcpy(nodo->sexo,"MASCULINO");
    }
    else
    { 
        strcpy(nodo->nombre,NombreFem[(rand()%40)]);
        strcpy(nodo->sexo,"FEMENINO");
    }
	strcpy(nodo->appat,Apellido[(rand()%50)]);
    strcpy(nodo->apmat,Apellido[(rand()%50)]);
    (nodo)->edad=(rand()%20)+17;
    (nodo)->stat=1;
    (nodo)->matri=(rand()%99000)+300000-(rand()%99);
    return nodo;            
}            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//FUNCION PUSH DE PILAS
void PUSH_S(Tnodo *pila, Tnodo *nuevo)
{
    (*nuevo)->sig=*pila;
    *pila=*nuevo;           
}
//FUNCION POP DE PILAS
Tnodo POP_S(Tnodo *pila)
{
    Tnodo temp=NULL;
    if(*pila)
    {
    	temp=*pila;
        *pila=(*pila)->sig;
        temp->sig=NULL;
    }
    return temp;          
}        
    
//FUNCION PUSH DE COLAS
void PUSH_Q(Tnodo *cola, Tnodo *ultimo, Tnodo *nuevo)
{
    if(!(*cola))
    {
        *cola=*nuevo;
    }
    else
    {
        (*ultimo)->sig=*nuevo;
    }
        *ultimo=*nuevo;               
}
//FUNCION POP DE COLAS
Tnodo POP_Q(Tnodo *cola, Tnodo *ultimo)
{
    Tnodo temp=NULL;
    if(*cola)
    {
        if(*cola==*ultimo)
    	{
            *ultimo=NULL;
        }
    	temp=*cola;
        *cola=(*cola)->sig;
        (temp->sig)=NULL;
    }      
    return temp;        
}
    
// Funciones de Validacion     
int validanum(int n1, int n2, char *msge, char *merror)
{
	char elnum[100];
	int num;
	do{
		
		printf("\n%s",msge);
		fflush(stdin);
		gets(elnum);
		num=atoi(elnum);
		if(num<n1||num>n2)
		{
			printf("%s",merror);
			delay(250);
		}
		
	}while(num<n1||num>n2);
}

int ValidaRepetidos (Tnodo *listaC, char *palabra, Tnodo *fin)
{
    Tnodo temp=NULL;
	char aux[100];
	aux[0]='\0';
	strcpy(aux,palabra);
	temp=*listaC;
	while(temp && (temp->sig) != *fin)
	{
		if(strcmp((temp)->palabra,palabra)==0)
		{
			return 1;
		}
		
		temp=(temp->sig);
	}
	return 0;
}

char* leecadena (char*msge)
{
    int x,letra,i;
    char cadena[40];
    printf("%s.",msge);
    i=0;
    do 
	{
        letra=getch();
        if (letra>=97 && letra<=122)
        {
            letra=letra-32;        
        }
        if ((letra>=65) && (letra<=90) || (letra==32))
        {
            cadena[i]=letra;
            i++;
            printf("%c",letra); 
        }
    }while (letra!=13);
    cadena[i]='\0';
    
	return cadena;     
}       
void Generartxt(Tnodo *listaC, Tnodo *fin)
{
    FILE *Archivo;
    Tnodo temp=NULL;  
    temp=*listaC;  
    char NombreArch[40];
    if(temp)
	{
		strcpy(NombreArch,(leecadena("Escriba el nombre para archivo.")));
		strcat(NombreArch,".txt");
		Archivo=fopen(NombreArch,"w");
		do
		{
			printf("%s ",temp->palabra);
			fprintf(Archivo,"%s\n",(temp->palabra));
			temp=temp->sig;
		}while(temp != (*listaC) );
		fclose(Archivo);
		system("cls");
		puts("Archivo Creado\n");
		system("PAUSE");
	}
}      
void validaaski(Tnodo *palabra)
{
	if((*palabra)->palabra[0]=='a')
	{
		(*palabra)->aski=A;
	}
	if((*palabra)->palabra[0]=='b')
	{
		(*palabra)->aski=B;
	}
	if((*palabra)->palabra[0]=='c')
	{
		(*palabra)->aski=C;
	}
	if((*palabra)->palabra[0]=='d')
	{
		(*palabra)->aski=D;
	}
	if((*palabra)->palabra[0]=='e')
	{
		(*palabra)->aski=E;
	}
	if((*palabra)->palabra[0]=='f')
	{
		(*palabra)->aski=F;
	}
	if((*palabra)->palabra[0]=='g')
	{
		(*palabra)->aski=G;
	}
	if((*palabra)->palabra[0]=='h')
	{
		(*palabra)->aski=H;
	}
	if((*palabra)->palabra[0]=='i')
	{
		(*palabra)->aski=I;
	}
	if((*palabra)->palabra[0]=='j')
	{
		(*palabra)->aski=J;
	}
	if((*palabra)->palabra[0]=='k')
	{
		(*palabra)->aski=K;
	}
	if((*palabra)->palabra[0]=='l')
	{
		(*palabra)->aski=L;
	}
	if((*palabra)->palabra[0]=='m')
	{
		(*palabra)->aski=M;
	}
	if((*palabra)->palabra[0]=='n')
	{
		(*palabra)->aski=N;
	}
	if((*palabra)->palabra[0]=='o')
	{
		(*palabra)->aski=O;
	}
	if((*palabra)->palabra[0]=='p')
	{
		(*palabra)->aski=P;
	}
	if((*palabra)->palabra[0]=='q')
	{
		(*palabra)->aski=Q;
	}
	if((*palabra)->palabra[0]=='r')
	{
		(*palabra)->aski=R;
	}
	if((*palabra)->palabra[0]=='s')
	{
		(*palabra)->aski=S;
	}
	if((*palabra)->palabra[0]=='t')
	{
		(*palabra)->aski=T;
	}
	if((*palabra)->palabra[0]=='u')
	{
		(*palabra)->aski=U;
	}
	if((*palabra)->palabra[0]=='v')
	{
		(*palabra)->aski=V;
	}
	if((*palabra)->palabra[0]=='w')
	{
		(*palabra)->aski=W;
	}
	if((*palabra)->palabra[0]=='x')
	{
		(*palabra)->aski=X;
	}
	if((*palabra)->palabra[0]=='y')
	{
		(*palabra)->aski=Y;
	}
	if((*palabra)->palabra[0]=='z')
	{
		(*palabra)->aski=Z;
	}
	if((*palabra)->palabra[0]=='A')
	{
		(*palabra)->aski=A;
	}
	if((*palabra)->palabra[0]=='B')
	{
		(*palabra)->aski=B;
	}
	if((*palabra)->palabra[0]=='C')
	{
		(*palabra)->aski=C;
	}
	if((*palabra)->palabra[0]=='D')
	{
		(*palabra)->aski=D;
	}
	if((*palabra)->palabra[0]=='E')
	{
		(*palabra)->aski=E;
	}
	if((*palabra)->palabra[0]=='F')
	{
		(*palabra)->aski=F;
	}
	if((*palabra)->palabra[0]=='G')
	{
		(*palabra)->aski=G;
	}
	if((*palabra)->palabra[0]=='H')
	{
		(*palabra)->aski=H;
	}
	if((*palabra)->palabra[0]=='I')
	{
		(*palabra)->aski=I;
	}
	if((*palabra)->palabra[0]=='J')
	{
		(*palabra)->aski=J;
	}
	if((*palabra)->palabra[0]=='K')
	{
		(*palabra)->aski=K;
	}
	if((*palabra)->palabra[0]=='L')
	{
		(*palabra)->aski=L;
	}
	if((*palabra)->palabra[0]=='M')
	{
		(*palabra)->aski=M;
	}
	if((*palabra)->palabra[0]=='N')
	{
		(*palabra)->aski=N;
	}
	if((*palabra)->palabra[0]=='O')
	{
		(*palabra)->aski=O;
	}
	if((*palabra)->palabra[0]=='P')
	{
		(*palabra)->aski=P;
	}
	if((*palabra)->palabra[0]=='Q')
	{
		(*palabra)->aski=Q;
	}
	if((*palabra)->palabra[0]=='R')
	{
		(*palabra)->aski=R;
	}
	if((*palabra)->palabra[0]=='S')
	{
		(*palabra)->aski=S;
	}
	if((*palabra)->palabra[0]=='T')
	{
		(*palabra)->aski=T;
	}
	if((*palabra)->palabra[0]=='U')
	{
		(*palabra)->aski=U;
	}
	if((*palabra)->palabra[0]=='V')
	{
		(*palabra)->aski=V;
	}
	if((*palabra)->palabra[0]=='W')
	{
		(*palabra)->aski=W;
	}
	if((*palabra)->palabra[0]=='X')
	{
		(*palabra)->aski=X;
	}
	if((*palabra)->palabra[0]=='Y')
	{
		(*palabra)->aski=Y;
	}
	if((*palabra)->palabra[0]=='Z')
	{
		(*palabra)->aski=Z;
	}
}
   
//************************************************************************
void delay(int tiempo)
{
  int i,j;
  for(i=0;i<tiempo*100;i++)
     {
	   for(j=0;j<tiempo*100;j++);
	 }
}
