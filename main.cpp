#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#define COLORNORMAL 7
#define TAM 500
#define M 24
#define N 80
using namespace std;

void gotoxy(short x, short y)
{
   COORD pos = { x, y };
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color(WORD col)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),col);
}


typedef struct
{

    int posicionx,posiciony,dimension,color;
    char caracterDibujo, codigo;

}tipoFigura;

typedef struct
{

    tipoFigura listaFiguras[TAM];
    int cantFiguras;

}tipoDisenio;



void dibujaLineaHorizontal(int n,int posx,int posy,char paint,char pen)
//dibuja una linea con el car de un tamanio del color pintura, a partir de la posx,posy
{
    color(11);
    for (int i=0;i<n;i++)
    {
        gotoxy(posx+i,posy);
        cout<<pen;
    }
    color(COLORNORMAL);

}

void dibujaLineaVertical(int n,int posx,int posy,char paint,char pen)
{
        color(11);
        for (int j=0;j<n;j++){
        cout<<pen<<endl;

            }
             color(COLORNORMAL);
}

 void mostrarCuadrado(tipoFigura &figura){


     for(int i = 0;i<figura.dimension;i++){
        dibujaLineaHorizontal(figura.dimension,figura.posicionx,figura.posiciony,figura.color,figura.caracterDibujo);
        figura.posiciony++;

    }
 }



 void mostrarTriangulo(tipoFigura figura){
    for (int i=0;i<figura.dimension+1;i++)
    {
        dibujaLineaHorizontal(i,figura.posicionx,figura.posiciony,figura.color,figura.caracterDibujo);
        figura.posiciony++;
    }

 }

 void mostrarRectangulo(tipoFigura figura){
     for(int i = 0;i<figura.dimension+(figura.dimension/2);i++){
         dibujaLineaHorizontal(figura.dimension,figura.posicionx,figura.posiciony,figura.color,figura.caracterDibujo);
       figura.posiciony++;
    }
 }
 void mostrarRombo(tipoFigura figura){
 int i,j,k;
 color(11);
for (i = 1; i <= figura.dimension; i++)

    {

          for (j = 0; j < (figura.dimension - i); j++)
            cout << " ";
          for (j = 1; j <= i; j++)
            cout << figura.caracterDibujo;
          for (k = 1; k < i; k++)
               cout << figura.caracterDibujo;
          cout << "\n";

    }



    for (i = figura.dimension - 1; i >= 1; i--)

    {

          for (j = 0; j < (figura.dimension - i); j++)
                cout << " ";
          for (j = 1; j <= i; j++)
                cout << figura.caracterDibujo;
          for (k = 1; k < i; k++)
                cout << figura.caracterDibujo;
          cout << "\n";
    }
    cout << "\n";
color(COLORNORMAL);
 }

 void mostrarFigura(tipoFigura figura)
{

if(figura.codigo=='c'){
mostrarCuadrado(figura);
}

if(figura.codigo=='t'){

mostrarTriangulo(figura);
}
if(figura.codigo=='r'){

mostrarRectangulo(figura);

}
if(figura.codigo=='o'){
mostrarRombo(figura);
}
}


 bool comprobar(char respuesta){

 if(respuesta=='s' or respuesta=='S'){
    return true;

 }
 else if(respuesta=='n' or respuesta=='N'){

        return false;

 }
 else{
    cout<<"respuesta no valida "<<endl;
 }
 return false;
 }


  void guardarDibujo(char dibujo[TAM],char filename[TAM])
 {
ofstream file;
char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/primer prototipo dibujos/dibujos/";
strcat(direccion,filename);
strcat(direccion,".txt");
file.open(direccion);
file<<dibujo;
file.close();
}

void cargarDibujo(char matrizPantalla[M][N], char filename[TAM]){
ifstream archEntrada;
char x;
char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/PRACTICA ARCHIVOS/EJERCICIOS11Y12/archivos/";
strcat(direccion,filename);
strcat(direccion,".txt");
archEntrada.open(direccion);

if (!archEntrada.is_open()){
cout<<"No se pudo abrir el archivo...";
return;
}
cout<<"EL CONTENIDO DEL ARCHIVO ES:"<<endl;
for(int i=0;i<M;i++)
{
    for (int j=0;j<N;j++)
    {
        archEntrada>>x;
        matrizPantalla[i][j]=x;
    }
}
archEntrada.close();
}


void mostrarMatriz(char mat[M][N],int x, int y)
{
int f,c;
for (f=0;f<M;f++)
for (c=0;c<N;c++)
{
gotoxy(x+(c*4),y+f);
cout<<mat[f][c];
}
}


typedef struct
{

    char dibujoPantalla[M][N];
    char name[TAM];

}tipoDibujo;

void matriz2Archivo(tipoDibujo dibujo,char filename[TAM])
{
int i=0,j=0;
fstream file;
char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/primer prototipo dibujos/dibujos/";
strcat(direccion,filename);
strcat(direccion,".txt");
file.open(direccion);
if(file.is_open()){
        while(!file.eof() and file.get(dibujo.dibujoPantalla[i][j]))
        {
        if(i>=M)
            {

            i=0;
            j++;
            }
            i++;
        }
}
else
    cout<<"no se cargo el dibujo"<<endl;
file.close();

}

void borrarMatriz(char matriz[M][N])
{
    for(int i=0;i<M;i++)
    {
            for(int j=0;j<N;j++)
            {

                matriz[i][j]=' ';
            }


    }
}


 void guardarDisenio(tipoDisenio disenio, char filename[TAM])
 {
ofstream file;
char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/primer prototipo dibujos/dibujos/";
strcat(direccion,filename);
strcat(direccion,".dat");
file.open(direccion,ios::binary);
file.write((char *)&disenio,sizeof(disenio));

file.close();
 }


 void cargarDisenio(char filename[TAM], tipoDisenio &a)
{

ifstream arch;

char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/primer prototipo dibujos/dibujos/";
strcat(direccion,filename);
strcat(direccion,".dat");
arch.open(direccion,ios::binary);

arch.read((char *)&a, sizeof(a));
//mostrarDisenio(a);

arch.close();
}


void mostrarDisenio(tipoDisenio disenio)
{
    for(int i=0;i<disenio.cantFiguras;i++)
    {

        mostrarFigura(disenio.listaFiguras[i]);
    }


}


void leerDatosFigura(int color, char caracter)
{



}

typedef struct
{
    int posx,posy,cantOpciones;
    int opciones[TAM], numerosOpciones[TAM];


}TipoLienzo;

void guardarLienzoComoBinario()
{



}

/////////// M  E  N  U //////////
typedef struct
{
    int posx,posy,cantOpciones;
    int opciones[TAM], numerosOpciones[TAM];


}TipoMenu;
void limparMenu(TipoMenu menu)
{

    for(int pos=0;pos<menu.cantOpciones;pos++)
    {
        gotoxy(menu.posx,menu.posy+pos);
        cout<<"                       ";
        cout<<endl;
    }
}
void menu(TipoMenu menu)
{

      for(int pos=0;pos<menu.cantOpciones;pos++)
      {

          gotoxy(menu.posx,menu.posy + lugar);
          cout<<menu.numerosOpciones[pos]<<" "<<menu.opciones[pos]<<endl;

      }


}

int main(){

char dibujo[TAM];
int opcion;
bool continuar=true;
char file_name[TAM];
tipoDisenio disenio2;
char matrizPantalla[M][N];

int c_disenios=0;

char figura,Rsalida,siono;
    tipoFigura cuadrado={0,20,4,0,'*','c'};
    tipoFigura triangulo={20,20,4,0,'*','t'};
    tipoFigura rectangulo={40,20,4,0,'*','r'};
    tipoFigura rombo={60,20,4,0,'*','o'};

    tipoDisenio miDibujo;

    /*
    miDibujo.cantFiguras=4;
    miDibujo.listaFiguras[0]=cuadrado;
    miDibujo.listaFiguras[1]=triangulo;
    miDibujo.listaFiguras[2]=rectangulo;
    miDibujo.listaFiguras[3]=rombo;
    */




    while(continuar){
cout<<" hola, ingresa el modo de uso "<<endl;

cout<<"1. dibujo libre"<<endl;
cout<<"2. elegir figuras predefinidas "<<endl;
cout<<"3. cargar un dibujo "<<endl;
cout<<"4 cargar un diseño "<<endl;
cout<<"5. salir"<<endl;
cin>>opcion;



switch(opcion){

case 1:
    cout<<" dibujo libre "<<endl;
    cout<<"ingrese su dibujo "<<endl;
    cin>>dibujo;

    cout<<"desea guardar su diseño S/N: "<<dibujo<<endl;
     cout<<dibujo<<endl;
    cin>>siono;
    if(comprobar(siono)){
        cout<<"INGRESE EL NOMBRE DEL DIBUJO "<<endl;
        cin>>file_name;
        guardarDibujo(dibujo,file_name);
        cout<<"se guardo su dibujo "<<endl;
    }

    break;
case 2:
      cout<<" elija una figura "<<endl;
        cout<<" [c] cuadrado "<<endl;
        cout<<" [r] rectangulo "<<endl;
        cout<<" [t] triangulo "<<endl;
        cout<<" [o] rombo "<<endl;
      cin>>figura;
      if(figura=='c'){
mostrarFigura(cuadrado);
miDibujo.listaFiguras[c_disenios]=cuadrado;
c_disenios++;

}

if(figura=='t'){

mostrarFigura(triangulo);
miDibujo.listaFiguras[c_disenios]=triangulo;
c_disenios++;

}
if(figura=='r'){

mostrarFigura(rectangulo);
miDibujo.listaFiguras[c_disenios]=rectangulo;
c_disenios++;

}
if(figura=='o'){
mostrarFigura(rombo);
miDibujo.listaFiguras[c_disenios]=cuadrado;
c_disenios++;
}
cout<<"desea guardar su disenio S/N"<<endl;
cin>>siono;
if(comprobar(siono))
guardarDisenio(miDibujo,"figura");
    break;
case 3:
      cout<<" cargar un dibujo "<<endl;
      cargarDibujo(matrizPantalla,file_name);
      mostrarMatriz(matrizPantalla,10,10);

    break;
case 4:
      cout<<" cargar un diseño "<<endl;
cargarDisenio("figura",disenio2);
system("cls");
cout<<"se cargo el diseño: "<<endl;
mostrarDisenio(disenio2);
    break;

case 5:
  cout<<" gracias por usar la aplicacion "<<endl;
    break;

}

cout<<"desea seguir  usando la app ?(s/n) "<<endl;
cin>>Rsalida;
continuar=comprobar(Rsalida);
}

    return 0;
}

