#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX 7

struct lista{   //Declarar nodos punteros
   char valor[30];
   struct lista *liga;
};
struct lista *inicio,*temp,*temp2;

struct compacto {     //Declarar la estructura
   char codproducto[30];
   int posicion;
}cd[8];

void ordenar(); //Funciones
void mostrar();
void tablahash();
int validarentero(char cod[30]);
void setcolor(int ForgC);
int menu();

void main(){
     setcolor(15);
     int opcmenu;
     char comp[30];
     int i,c,w=0,flag=0,flag1,cont=0,cn=0,t; //Banderas y contadores
     for(i=0;i<MAX;i++)   {    //Se igualan las posicione a -1 para solo imprimir las
        cd[i].posicion=-1;     //que sean mayores o iguales a 0, es decir,
                        }    //que ya estan registradas

  do{   //Sirve para repetir hasta que se eliga la opcion salir
        opcmenu=menu(); //Funcion que llama al menu
   switch(opcmenu)
   {
    case 1:
        do{ //Sirve para repetir hasta que la cadena sea aceptada (solo numeros)
              printf("Ingrese el Codigo del producto\n");
              gets(comp);
              t=validarentero(comp);
             }while(t==1);

    c=atoi(comp)%MAX; //Toma el residuo de la division del dato dado sobre el maximo numero de datos
    if(cont<MAX){ //Sirve para saber si la tabla esta llena
    flag=0,flag1=0;
    for(i=0;i<MAX;i++){  //Revisa si la posision esta ocupada
        if(c==cd[i].posicion)
        {
        flag=1;
        }
                      }
    if(flag==1)
        {  //Si la posicion esta ocupada busca posiciones disponibles en los valores de posicion menores
          int g=c; //Guarda la posicion inicial (antes de buscar otra posicion)
          while(c>=0){
            if(!atoi(cd[c].codproducto)>0){
                flag1=1;
                strcpy(cd[c].codproducto,comp);
                cont++;
                setcolor(10);
                printf("El codigo se guardo en la posicion %d\n\n",c);
                    if(cont>=MAX){setcolor(12);
            printf("TABLA LLENA\n\n");
            setcolor(15);
            printf("En el siguiente registro se producira una colision\n\n");}
             setcolor(15);
                system("pause");
                cd[c].posicion=c;
                break;
                                            } c--;
                    }
    c=g; //Regresa al valor inicial para no empezar desde abajo
    if(flag1==0){ //Si no encontro una posicion en los menores, busca en los mayores
        while(c<MAX){
            if(!atoi(cd[c].codproducto)>0)
                {
                flag1=1;
                strcpy(cd[c].codproducto,comp);
                cont++;
                setcolor(10);
                printf("El codigo se guardo en la posicion %d\n\n",c);
                    if(cont>=MAX){setcolor(12);
            printf("TABLA LLENA\n\n"); setcolor(15);
            printf("En el siguiente registro se producira una colision\n\n");}
                setcolor(15);
                system("pause");
                cd[c].posicion=c;
                break;
                }
                c++;
                    }
               }
         }
    if(flag==0)  //Entra cuando la posicion esta desocupada
    {
    strcpy(cd[c].codproducto,comp);
    cont++;
    cd[c].posicion=c;
    setcolor(10);
    printf("El codigo se guardo en la posicion %d\n\n",c);
    if(cont>=MAX){setcolor(12);
            printf("TABLA LLENA\n\n"); setcolor(15);
            printf("En el siguiente registro se producira una colision\n\n");}
    setcolor(15);
    system("pause");
    }
            }
    else{ //Entra si la tabla esta llena, cuando hay overflow
        setcolor(12);
        printf("COLISION\n\n");
        setcolor(10);
        printf("Creando lista enlazada en la posicion %d\n\n",c);
        setcolor(15);
           if(inicio==NULL){ //Inicia el nodo
              inicio=(struct lista*)malloc(sizeof(struct lista));
              strcpy(inicio->valor,comp);
              inicio->liga=NULL;
                           }
           else{
                temp=inicio;  //Recorre el nodo y se coloca en la posicion para escribir
                    while(temp->liga!=NULL)
                    {temp=temp->liga;}
                temp2=(struct lista*)malloc(sizeof(struct lista));//malloc reserva el espacio de memoria
                strcpy(temp2->valor,comp); //Coloca el valor dado en una variable temporal
                temp2->liga=NULL; //la variable temporal apunta al siguiente nodo
                temp->liga=temp2; //Cambia el valor de NULL por valor dado
               }
                 if(cn==0){    //Escribe el primer valor del nodo
                 temp=inicio;
                   while(temp->liga!=NULL)
                   {temp=temp->liga;}
                   temp2=(struct lista*)malloc(sizeof(struct lista));
                   strcpy(temp2->valor,"66667");
                   temp2->liga=NULL;
                   temp->liga=temp2;}
                   cn=cn+1;
        system("pause");
    } w=1; //verifica que ya se haya hecho un registro
    break;

case 2:
        if(w==0){
        setcolor(12); //verifica que ya se haya hecho un registro
        printf("Aun no se ha hecho ningun registro\n");
        setcolor(15);
        system("pause");
                }
        else //Entra si ya hay algun registro
        {
        if(cn==0)   { //Comprueba si aun no hay nodos escritos
        tablahash();}
            else{ //En caso de haber nodos se ordenan y se mustran
                ordenar();
                mostrar();
                }
        }
break;
case 3:
    system("cls");
    printf("Hasta pronto\n");
    system("pause");

    break;

     }//llave de switch del menu
}while(opcmenu!=3); //Se repite hasta que se escoja la opcion de salir
}



int menu(){
    int opcmenu;
    system("cls");
printf("          Seleccione una opcion\n\n");
printf("  1) Registrar producto\n");
printf("  2) Mostrar\n");
printf("  3) Salir\n");
scanf("%d",&opcmenu);
fflush(stdin);
return(opcmenu);
}

void ordenar()
{  //algoritmo de ordenamiento de nodos
 temp = inicio;
 char t[30];
     while(temp->liga != NULL) //ciclo hasta que el nodo apunte a NULL
     {
          temp2 = temp->liga;

          while(temp2!=NULL)
          {
                    if(atoi(temp->valor) > atoi(temp2->valor)) //Ordena los valores
               {
                    strcpy(t,temp2->valor);
                    strcpy(temp2->valor,temp->valor);
                    strcpy(temp->valor,t);
               }

               if(atoi(temp->valor)%7 > atoi(temp2->valor)%7)  //Ordena las posiciones
               {
                    strcpy(t,temp2->valor);
                    strcpy(temp2->valor,temp->valor);
                    strcpy(temp->valor,t);
               }
               temp2 = temp2->liga;
          }
          temp = temp->liga;
          temp2 = temp->liga;
     }
}

void mostrar() //Muestra tanto la tabla hash como los nodos
{    system("cls");  printf("\n");
     int i;
     for(i=0;i<MAX;i++) //Sirve para imprimir solo hasta el valor maximo en la tabla
    {
          if(cd[i].posicion>=0)  //comprueba si ya hay un registro en la posicion
           {
             printf("%d)    ",cd[i].posicion);  //imprime la posicion
             setcolor(10);
             if(atoi(temp->valor)%MAX>=i){
                printf("%d    ",atoi(cd[i].codproducto)); //imprime el valor en la tabla hash
                                         }
                  else {printf("%d\n",atoi(cd[i].codproducto));}
      temp=inicio;
      setcolor(11);
         while(temp->liga!=NULL)  { //busca todos los datos en los nodos
        if(atoi(temp->valor)%MAX==i)
            {
    printf("%d   ",atoi(temp->valor)); //Imprime si el residuo coincide con la posicion
            }
                temp=temp->liga;
                                  }
         if(atoi(temp->valor)%MAX>i){printf("\n");}
         setcolor(15);
            }
    }
         printf("\n");
      system("pause");

}

void tablahash(){ //imprime solo la tabla hash
     system("cls");
     printf("\n");
     int i;
    for(i=0;i<MAX;i++)
        {
           if(cd[i].posicion>=0)   //verifica la posicion haya sido ocupada
             {
                 printf("%d)  ",cd[i].posicion); //imprime las posiciones
                 setcolor(10);
                 printf("%d\n",atoi(cd[i].codproducto));  //imprime el valor
                 setcolor(15);
             }
        }
     printf("\n");
     system("pause");
}

int validarentero(char cod[30]){ //verifica que los caracteres introducidos solo sean numeros
     int i=0, q=0,j,ent;
     j=strlen(cod);
     ent=atoi(cod);
         while(i<j && q==0)
            {
            if(isdigit(cod[i])!=0&&ent>=0)
                {
                  i++;
                }
             else{ q=1; }
            }
if(q == 0){setcolor(10);
        printf("Cadena Valida\n\n"); setcolor(15);
}
else {setcolor(12);
    printf(" Cadena no valida\n\n");setcolor(15);
    }
return q;
}


void setcolor(int ForgC){ //Sirve para cambiar el color del texto
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi)){
        wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut,wColor);
    }
    return;
}
