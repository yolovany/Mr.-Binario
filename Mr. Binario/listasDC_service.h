
typedef struct tdatoD{
        int index;
        int mouse_x;
        int mouse_y;
        struct tdatoD *sig;
        struct tdatoD *ant;
        }TdatoD;

typedef TdatoD *TnodoD;

//Prototipos de Listas dobles//
TnodoD AgregarLD(TnodoD *listaD, TnodoD *nuevo, TnodoD *fin);

///Agregar Lista Doble///
TnodoD AgregarLD(TnodoD *listaD, TnodoD *nuevo, TnodoD *fin)
  {
       TnodoD temp=NULL,nodo=NULL;
       temp=(*listaD);
       if(!(temp))
          {
                  (*listaD)=(*nuevo);
                  (*fin)=(*nuevo);
                  return nodo;

          }
          if((*nuevo)->index< temp->index)
          {
                              (*nuevo)->sig=(*listaD);
                              (*listaD)->ant=(*nuevo);
                              (*listaD)=(*nuevo);

          }
          else
           {
            if((*nuevo)->index>(*fin)->index)
              {
                                             (*fin)->sig=(*nuevo);
                                             (*nuevo)->ant=(*fin);
                                             (*fin)=(*nuevo);

              }
              else
               {
                   while((temp->sig)->index<(*nuevo)->index)
                        {
                          temp=(temp->sig);
                        }
                        if((temp->sig)->index==(*nuevo)->index)
                          {
                            return *nuevo;

                          }
                         else
                          {

                                 (*nuevo)->ant=temp;
                                 (*nuevo)->sig=(temp->sig);
                                 (temp->sig)->ant=(*nuevo);
                                 (temp->sig)=(*nuevo);
                          }
               }
           }
       return nodo;
  }




