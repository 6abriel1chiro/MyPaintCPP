#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#define COLORNORMAL 7
#define TAM 500
#define M 80
#define N 30
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

/////////////////////////////T I P O S  ///////////////////
typedef struct
{

    int posicionx,posiciony,dimension,color;
    char caracterDibujo, codigo;
    int colorSecundario;

}tipoFigura;

typedef struct
{
    tipoFigura listaFiguras[TAM];
    int cantFiguras;
}tipoDisenio;

typedef struct
{
    char dibujoPantalla[M][N];
}tipoDibujo;


typedef struct
{
tipoDibujo dibujo;
tipoDisenio disenio;


}TipoLienzo;



typedef struct
{
    int posx,posy,cantOpciones;
    char indiceOpciones[TAM];
    string opciones[TAM];


}TipoMenu;

////////----------////////////////////////


////////////////    MOSTRAR FIGURAS PREDEFINIDAS ////////////////////
void dibujaLineaHorizontal(int n,int posx,int posy,int paint,char pen)
//dibuja una linea con el car de un tamanio del color pintura, a partir de la posx,posy
{
    color(paint);
    for (int i=0;i<n;i++)
    {
        gotoxy(posx+i,posy);
        cout<<pen;
    }
    color(COLORNORMAL);

}
void dibujaLineaHorizontalEspecial(int n,int posx,int posy,int paint,char pen,int paint2,int h)
//dibuja una linea con el car de un tamanio del color pintura, a partir de la posx,posy
{
    color(paint);
    for (int i=0;i<n;i++)
    {
        gotoxy(posx+i,posy);
        cout<<pen;
            if(i==n/2 and i==h){
             color(paint2);
             gotoxy(posx+i,posy);
            cout <<pen;
            color(paint);
            }
    }
    color(COLORNORMAL);

}

void dibujaLineaCars(tipoFigura figura,int &space,string car,int &i){
            for (int j = 0;j < space; j++){
            //gotoxy(figura.posicionx,figura.posiciony);
            cout <<car;
            }
}
void dibujaLineaCarsSup(tipoFigura figura,int &space,string car,int &i){
            for (int j = 0;j <= space; j++){
                if(i==figura.dimension/2){
             color(figura.colorSecundario);
            cout <<car;
            color(figura.color);
            }
            //gotoxy(figura.posicionx,figura.posiciony);
            cout <<car;
            }
}
void dibujaLineaEspacios(tipoFigura figura,int &space,string car,int &i){
       for (int j = 0; j <= i; j++){
           // gotoxy(figura.posicionx+1,figura.posiciony);
            cout <<car;
       }

}

 void mostrarCuadrado(tipoFigura &figura){


     for(int i = 0;i<figura.dimension;i++){
        dibujaLineaHorizontal(figura.dimension,figura.posicionx,figura.posiciony,figura.color,figura.caracterDibujo);
        figura.posiciony++;

    }
 }
  void mostrarCuadradoEspecial(tipoFigura &figura){


     for(int i = 0;i<figura.dimension;i++){
        dibujaLineaHorizontalEspecial(figura.dimension,figura.posicionx,figura.posiciony,figura.color,figura.caracterDibujo,figura.colorSecundario,i);
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
int space;
color(figura.color);

        space = 0;
    for (int i = figura.dimension; i > 0; i--)
    {
    gotoxy(figura.posicionx,figura.posiciony);
    dibujaLineaEspacios(figura,space," ",i);
        gotoxy(figura.posicionx+i,figura.posiciony);
    dibujaLineaCars(figura,space,"* ",i);
    figura.posiciony++;
        space++;
    }
     space = figura.dimension - 1;
    for (int i = 0; i < figura.dimension; i++)
    {
    gotoxy(figura.posicionx,figura.posiciony);
    dibujaLineaEspacios(figura,space," ",i);
        gotoxy(figura.posicionx+i,figura.posiciony);
    dibujaLineaCarsSup(figura,space,"* ",i);
    figura.posiciony++;
        space--;
    }

color(COLORNORMAL);
 }

  void mostrarRomboEspecial(tipoFigura figura){
 int space;
color(figura.color);

        space = 0;
    for (int i = figura.dimension; i > 0; i--)
    {
    gotoxy(figura.posicionx,figura.posiciony);
    dibujaLineaEspacios(figura,space," ",i);
        gotoxy(figura.posicionx+i,figura.posiciony);
    dibujaLineaCars(figura,space,"* ",i);
    figura.posiciony++;
        space++;
    }
     space = figura.dimension - 1;
    for (int i = 0; i < figura.dimension; i++)
    {
    gotoxy(figura.posicionx,figura.posiciony);
    dibujaLineaEspacios(figura,space," ",i);
        gotoxy(figura.posicionx+i,figura.posiciony);
    dibujaLineaCarsSup(figura,space,"* ",i);
    figura.posiciony++;
        space--;
    }

color(COLORNORMAL);
 }
//////////////////BORRAR


 void borrarCuadrado(tipoFigura &figura){


     for(int i = 0;i<figura.dimension;i++){
        dibujaLineaHorizontal(figura.dimension,figura.posicionx,figura.posiciony,figura.color,' ');
        figura.posiciony++;

    }
 }

  void borrarCuadradoEspecial(tipoFigura &figura){


     for(int i = 0;i<figura.dimension;i++){
        dibujaLineaHorizontal(figura.dimension,figura.posicionx,figura.posiciony,figura.color,' ');
        figura.posiciony++;

    }
 }



 void borrarTriangulo(tipoFigura figura){
    for (int i=0;i<figura.dimension+1;i++)
    {
        dibujaLineaHorizontal(i,figura.posicionx,figura.posiciony,figura.color,' ');
        figura.posiciony++;
    }

 }

 void borrarRectangulo(tipoFigura figura){
     for(int i = 0;i<figura.dimension+(figura.dimension/2);i++){
         dibujaLineaHorizontal(figura.dimension,figura.posicionx,figura.posiciony,figura.color,' ');
       figura.posiciony++;
    }
 }
 void borrarRombo(tipoFigura figura){
int space;
color(figura.color);

        space = 0;
    for (int i = figura.dimension; i > 0; i--)
    {
    gotoxy(figura.posicionx,figura.posiciony);
    dibujaLineaEspacios(figura,space," ",i);
        gotoxy(figura.posicionx+i,figura.posiciony);
    dibujaLineaCars(figura,space,"  ",i);
    figura.posiciony++;
        space++;
    }
     space = figura.dimension - 1;
    for (int i = 0; i < figura.dimension; i++)
    {
    gotoxy(figura.posicionx,figura.posiciony);
    dibujaLineaEspacios(figura,space," ",i);
        gotoxy(figura.posicionx+i,figura.posiciony);
    dibujaLineaCarsSup(figura,space,"  ",i);
    figura.posiciony++;
        space--;
    }

color(COLORNORMAL);
 }
  void borrarRomboEspecial(tipoFigura figura){
int space;
color(figura.color);

        space = 0;
    for (int i = figura.dimension; i > 0; i--)
    {
    gotoxy(figura.posicionx,figura.posiciony);
    dibujaLineaEspacios(figura,space," ",i);
        gotoxy(figura.posicionx+i,figura.posiciony);
    dibujaLineaCars(figura,space,"  ",i);
    figura.posiciony++;
        space++;
    }
     space = figura.dimension - 1;
    for (int i = 0; i < figura.dimension; i++)
    {
    gotoxy(figura.posicionx,figura.posiciony);
    dibujaLineaEspacios(figura,space," ",i);
        gotoxy(figura.posicionx+i,figura.posiciony);
    dibujaLineaCarsSup(figura,space,"  ",i);
    figura.posiciony++;
        space--;
    }

color(COLORNORMAL);
 }

//////////////////////////////////////////////////
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

if(figura.codigo=='O'){
mostrarRomboEspecial(figura);
}
if(figura.codigo=='C'){
mostrarCuadradoEspecial(figura);
}
}

 void borrarFigura(tipoFigura figura)
{

if(figura.codigo=='c'){
borrarCuadrado(figura);
}

if(figura.codigo=='t'){

borrarTriangulo(figura);
}
if(figura.codigo=='r'){

borrarRectangulo(figura);

}
if(figura.codigo=='o'){
borrarRombo(figura);
}
if(figura.codigo=='O'){
borrarRomboEspecial(figura);
}
if(figura.codigo=='C'){
borrarCuadradoEspecial(figura);
}
}

void leerDatosFigura(tipoFigura &figura)
{
 cout<<"indique que figura sera "<<endl;
 cin>>figura.codigo;

cout<<"pos x   /   pos y:   ";
 cin>>figura.posicionx>>figura.posiciony;
 cout<<"ingrese el tamanio de la figura "<<endl;
 cin>>figura.dimension;
cout<<"ingrese el color de la figura "<<endl;
 cin>>figura.color;
cout<<"ingrese el caracter de la figura "<<endl;
 cin>>figura.caracterDibujo;

 cout<<"En caso de tenerlo, ingrese un color 2, caso contrario ingrese 0 "<<endl;
 cin>>figura.colorSecundario;


}


///////////////-----------/////////////////




/////////////////////// D I B U J O ///////////////

  void guardarDibujo(tipoDibujo &dibujo,char filename[TAM])     ///////////////ccomo TXT
 {

ofstream file;
char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/PROYECTO FINAL/dibujos/";
strcat(direccion,filename);
strcat(direccion,".txt");

file.open(direccion);
if(file.is_open())
{

for(int i=0;i<M;i++)
    {
for (int j=0;j<N;j++)
{
file<<dibujo.dibujoPantalla[i][j];


}
file<<endl;
}
cout<<"se guardo el dibujo "<<endl;
file.close();
}
else
    cout<<"no se guardo el dibujo"<<endl;
}

void cargarDibujo(tipoDibujo &matrizPantalla, char filename[TAM]){      ////////cargar TXT
ifstream archEntrada;
char x;
char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/PROYECTO FINAL/dibujos/";
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
        matrizPantalla.dibujoPantalla[i][j]=x;
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

/////////////////////////////////////DISENIO////////////////////////////



///////////////////////MUESTRARIO///////////////////////////

 void cargarMuestrario(char filename[TAM], tipoDisenio &a) ////////////CARGAR DISENIO COMO BINARIO
{

ifstream arch;

char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/PROYECTO FINAL/dibujos/";
strcat(direccion,filename);
strcat(direccion,".dat");
arch.open(direccion,ios::binary);
if(arch.is_open()){
arch.read((char *)&a, sizeof(a));
}
else{
    cout<<"no se pudo cargar "<<endl;
    }

arch.close();
}
///////////////////////////////////////////////////////////////////////////////////////

 void guardarDisenio(tipoDisenio disenio, char filename[TAM])    /////////como  BINARIO
 {
ofstream file;
char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/PROYECTO FINAL/dibujos/";
strcat(direccion,filename);
strcat(direccion,".dat");
file.open(direccion,ios::binary);
if(file.is_open()){
file.write((char *)&disenio,sizeof(disenio));
 cout<<"guardado:  "<<endl;
}
else{
    cout<<"no se guardo el diseño "<<endl;
}
file.close();
 }

 void cargarDisenio(char filename[TAM], tipoDisenio &a) ////////////CARGAR DISENIO COMO BINARIO
{

ifstream arch;

char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/PROYECTO FINAL/dibujos/";
strcat(direccion,filename);
strcat(direccion,".dat");
arch.open(direccion,ios::binary);
if(arch.is_open()){
arch.read((char *)&a, sizeof(a));
cout<<"cargado: "<<endl;
}
else{
    cout<<"no se pudo cargar "<<endl;
    }

arch.close();
}

void mostrarDisenio(tipoDisenio disenio)
{
    for(int i=0;i<disenio.cantFiguras;i++)
    {

        mostrarFigura(disenio.listaFiguras[i]);
    }


}
void borrarDisenio(tipoDisenio disenio)
{
    for(int i=0;i<disenio.cantFiguras;i++)
    {

        borrarFigura(disenio.listaFiguras[i]);
    }


}

////////////////////////////DIBUJAR

void leerDatos(char &c,int &posx,int &posy,int &color)
{

cout<<"color de su pincel "; cin>>color;
cout<<endl;
cout<<"punta de su pincel "; cin>>c;
cout<<endl;
cout<<"pos x "; cin>>posx;
cout<<endl;
cout<<"pos y "; cin>>posy;

}



void dibujar(char symbol, int &X, int &Y,int colour,tipoDibujo &dibujo)
{


  bool seguir = true;
     char ch;
     gotoxy(70,20);
     cout<<"presione x para dejar de dibujar | Use WASD para mover el pincel "<<endl;
     color(colour);
     gotoxy(X,Y);
     cout<<symbol;
while(seguir)
    {
      if(kbhit())
      {
          ch = getch();
           switch(ch)
           {
           case 'w':
               Y=Y-1;
               gotoxy(X,Y);
               cout<<symbol;
               dibujo.dibujoPantalla[X][Y]=symbol;

               break;
           case 's':
               Y=Y+1;
               gotoxy(X,Y);
                  cout<<symbol;
               dibujo.dibujoPantalla[X][Y]=symbol;

               break;
           case 'a':
               X=X-1;
               gotoxy(X,Y);
                  cout<<symbol;
                dibujo.dibujoPantalla[X][Y]=symbol;

               break;
           case 'd':
               X=X+1;
               gotoxy(X,Y);
               cout<<symbol;
              dibujo.dibujoPantalla[X][Y]=symbol;
               break;

           case 'x':                          //exit when escpressed
          seguir=false;
            break;
                }
        }
            Sleep(30);

    }
        color(COLORNORMAL);
cout<<"ha terminado el dibujo"<<endl;

}


//////////////////////LIENZO  //////////////////////////////////////////
void guardarLienzoComoBinario(TipoLienzo &lienzo,tipoDibujo dibujo, tipoDisenio disenio,char filename[TAM]) /////////////DIBUJO COMO BINARIO
{
ofstream file;
lienzo.dibujo=dibujo;
lienzo.disenio=disenio;
char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/PROYECTO FINAL/dibujos/";
strcat(direccion,filename);
strcat(direccion,".dat");
file.open(direccion,ios::binary);
if(file.is_open()){
file.write((char *)&lienzo,sizeof(lienzo));
 cout<<"guardado  "<<endl;
}
else{
    cout<<"no se guardo el lienzo "<<endl;
}
file.close();

}
void guardarLienzoComoTxt(TipoLienzo lienzo) /////////////DIBUJO COMO BINARIO
{
    ofstream file;


}

void cargarLienzoBinario(char filename[TAM],TipoLienzo &lienzo)
{
    ifstream arch;

char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/PROYECTO FINAL/dibujos/";
strcat(direccion,filename);
strcat(direccion,".dat");
arch.open(direccion,ios::binary);
if(arch.is_open()){
arch.read((char *)&lienzo, sizeof(lienzo));
cout<<"cargado: "<<endl;
}
else{
    cout<<"no se pudo cargar "<<endl;
    }

arch.close();
}

void mostrarLienzo(TipoLienzo lienzo)
{
    mostrarMatriz(lienzo.dibujo.dibujoPantalla,1,1);
    mostrarDisenio(lienzo.disenio);


}
/////////////---------///////////

/////////// M  E  N  U //////////
void limparMenu(TipoMenu menu)
{

    for(int pos=0;pos<menu.cantOpciones;pos++)
    {
        gotoxy(menu.posx,menu.posy+pos);
        cout<<"                       ";
        cout<<endl;
    }
}
void GenerarMenu(TipoMenu menu)
{

      for(int pos=0;pos<menu.cantOpciones;pos++)
      {

          gotoxy(menu.posx,menu.posy + pos);
          cout<<menu.indiceOpciones[pos]<<" "<<menu.opciones[pos]<<endl;

      }


}
/////////////////////////////MARGEN
void mostrarMargen()
{

    color(8);
    for(int i=0;i<M;i++)
    {
        gotoxy(i,0);
    cout<<char(205);
    gotoxy(i,N);
    cout<<char(205);
    }
        for(int j=0;j<N;j++)
    {
        gotoxy(0,j);
    cout<<char(186);
    gotoxy(M,j);
    cout<<char(186);
    }

        gotoxy(0,0);
    cout<<char(201);

        gotoxy(M,0);
    cout<<char(187);

        gotoxy(0,N);
    cout<<char(200);

        gotoxy(M,N);
    cout<<char(188);


}

///////////------////////////////

/////MATRIZ RANDOM /////////////


void matriz2arch(int matrizPantalla[M][N], char filename[TAM]){

ofstream file;
char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/PROYECTO FINAL/dibujos/";
strcat(direccion,filename);
strcat(direccion,".txt");
//cout<<direccion<<endl;
file.open(direccion);
cout<<"se abrio el archivo "<<endl;
for(int i=0;i<M;i++)
    {
for (int j=0;j<N;j++)
{
file<<matrizPantalla[i][j];


}
file<<endl;
}

file.close();
}


void arch2matriz(int matrizPantalla[M][N], char filename[TAM]){
ifstream archEntrada;
char x;
char direccion[TAM]="E:/clases +/SEM II/PROGRA1/Trabajos/TRABAJO ESTRUCTURAS/proyecto PROGRA/PROYECTO FINAL/dibujos/";
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


void llenarMatrizRandom(int Mat[M][N])
{
    int num;
     srand(time(NULL));

    for(int i = 0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            num = 1 + rand() % (10 - 1);
           Mat[i][j]=num;


        }

    }

}

void mostrarMatrizRandom(int mat[M][N],int x, int y)
{
int f,c;
for (f=0;f<M;f++)
for (c=0;c<N;c++)
{
gotoxy(x+(c*4),y+f);
cout<<mat[f][c];
}
}
/////////////////////////////////////////

/////////////MOSAICO ////////////////////////////
  void leerDatosMosaico(tipoFigura &figura,int &filas, int &columnas){
 figura.posicionx=2;
 figura.posiciony=2;
cout<<"ingrese codigo (O/C) "<<endl;
cin>>figura.codigo;
 cout<<"ingrese el tamanio de la figura "<<endl;
 cin>>figura.dimension;
cout<<"ingrese el color de la figura "<<endl;
 cin>>figura.color;
  cout<<" ingrese un color secundario"<<endl;
 cin>>figura.colorSecundario;
cout<<"ingrese el caracter de la figura "<<endl;
 cin>>figura.caracterDibujo;
 cout<<"ingrese filas y columnas: ";
 cin>>filas>>columnas;
  }
 void generarMosaico(tipoFigura figura,int filas,int columnas)
{
int aux;

for(int i = 0;i<filas;i++)
{
figura.posicionx=2 ;
for(int j = 0;j<columnas;j++)
{
        mostrarFigura(figura);
        figura.posicionx=figura.posicionx+figura.dimension+1;
            aux=figura.color;
figura.color=figura.colorSecundario;
figura.colorSecundario=aux;

}
    figura.posiciony=figura.posiciony+figura.dimension+1;
}
}

 void BorrarMosaico(tipoFigura figura,int filas,int columnas)
{


for(int i = 0;i<filas;i++)
{
figura.posicionx=2 ;
for(int j = 0;j<columnas;j++)
{
        borrarFigura(figura);
        figura.posicionx=figura.posicionx+figura.dimension+1;

}
    figura.posiciony=figura.posiciony+figura.dimension+1;
}
}


void animarMosaico(tipoFigura figura,int filas,int columnas)
{

    int aux;
    while(!kbhit()){
generarMosaico(figura,filas,columnas);
Sleep(500);
////borrado
BorrarMosaico(figura,filas,columnas);
Sleep(250);
//////segundo color
            aux=figura.color;
figura.color=figura.colorSecundario;
figura.colorSecundario=aux;
/////////////////
generarMosaico(figura,filas,columnas);
Sleep(500);
BorrarMosaico(figura,filas,columnas);
Sleep(250);

    }
}
////////////////////////////////////////////
/////////////preguntar fin
 bool comprobar(char respuesta)
 {

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
//////////-/////////////////

int main(){


char opcion;
bool continuar=true;
char Rsalida,siono;

int posx,posy,color;
char c;

char file_name[TAM], file_name_design[TAM], file_name_lienzo[TAM];
char savedFile_name[TAM];




///// muestrario
    tipoFigura cuadrado={2,10,4,11,'*','c',0};
    tipoFigura triangulo={20,10,4,11,'*','t',0};
    tipoFigura rectangulo={40,10,4,11,'*','r',0};
    tipoFigura rombo={60,10,4,11,'*','o',0};
    tipoFigura romboEspecial={2,25,4,11,'*','O',3};
    tipoFigura cuadradoEspecial={10,25,5,11,'*','C',3};

tipoDisenio disenioDePrueba;
tipoDisenio disenioDePrueba2;

disenioDePrueba.cantFiguras=6;
disenioDePrueba.listaFiguras[0]=cuadrado;
disenioDePrueba.listaFiguras[1]=triangulo;
disenioDePrueba.listaFiguras[2]=rectangulo;
disenioDePrueba.listaFiguras[3]=rombo;
disenioDePrueba.listaFiguras[4]=romboEspecial;
disenioDePrueba.listaFiguras[5]=cuadradoEspecial;

//guardarDisenio(disenioDePrueba,"prueba");
char nombreMuestrario[TAM]="prueba";
cargarMuestrario(nombreMuestrario,disenioDePrueba2);
//mostrarDisenio(disenioDePrueba2);



////// datos por usuario

tipoFigura figura;

tipoDibujo matrizPantalla,matrizPantallaOUT;

tipoDisenio miDibujo, disenio2;
    int c_disenios=0;

TipoLienzo lienzo, lienzoOUT;

/////
///////////MOSAICO


tipoFigura mosaico;
int filas ,columnas;

//////////

/////menu

TipoMenu menu;
menu.posx=82;
menu.posy=5;
menu.cantOpciones=10;
menu.indiceOpciones[0]='1';
menu.indiceOpciones[1]='2';
menu.indiceOpciones[2]='3';
menu.indiceOpciones[3]='4';
menu.indiceOpciones[4]='5';
menu.indiceOpciones[5]='6';
menu.indiceOpciones[6]='7';
menu.indiceOpciones[7]='8';
menu.indiceOpciones[8]='9';
menu.indiceOpciones[9]='X';
menu.opciones[0]="dibujo libre";
menu.opciones[1]="pintar figuras predefinidas" ;
menu.opciones[2]="cargar un dibujo";
menu.opciones[3]="cargar un diseño";
menu.opciones[4]="generar dibujo aleatorio";
menu.opciones[5]="guardar el lienzo actual";
menu.opciones[6]="cargar un lienzo entero ";
menu.opciones[7]="generar mosaico ";
menu.opciones[8]="animar mosaico";
menu.opciones[9]="salir";


TipoMenu menuFiguras;

menuFiguras.posx=82;
menuFiguras.posy=15;
menuFiguras.cantOpciones=6;
menuFiguras.indiceOpciones[0]='c';
menuFiguras.indiceOpciones[1]='r';
menuFiguras.indiceOpciones[2]='t';
menuFiguras.indiceOpciones[3]='o';
menuFiguras.indiceOpciones[4]='O';
menuFiguras.indiceOpciones[5]='C';
menuFiguras.opciones[0]=") cuadrado ";
menuFiguras.opciones[1]=") rectangulo " ;
menuFiguras.opciones[2]=") triangulo ";
menuFiguras.opciones[3]=") rombo ";
menuFiguras.opciones[4]=") rombo Especial (2 colores)";
menuFiguras.opciones[5]=") cuadrado Especial (2 colores)";

/////////////




    while(continuar){
gotoxy(82,3);
cout<<"PINTURILLO"<<endl;
GenerarMenu(menu);
mostrarMargen();
cin>>opcion;


switch(opcion){

case '1':
    cout<<" dibujo libre "<<endl;
    leerDatos(c,posx,posy,color);
    cout<<"ingrese su dibujo "<<endl;
    dibujar(c,posx,posy,color,matrizPantalla);

    cout<<"desea guardar su dibujo S/N: "<<endl;
    cin>>siono;
    if(comprobar(siono)){
        cout<<"INGRESE EL NOMBRE DEL DIBUJO "<<endl;
        cin>>file_name;

        guardarDibujo(matrizPantalla,file_name);
        system("pause");
    }
    break;
case '2':

    cout<<" elija una figura "<<endl;
    mostrarDisenio(disenioDePrueba2);
    Sleep(2000);
    borrarDisenio(disenioDePrueba2);
    //system("cls");
    GenerarMenu(menuFiguras);
    leerDatosFigura(figura);

if((figura.codigo=='t')  or (figura.codigo=='r') or (figura.codigo=='o') or (figura.codigo=='c') or (figura.codigo=='O') or (figura.codigo=='C'))
{

mostrarFigura(figura);
miDibujo.listaFiguras[c_disenios]=figura;
c_disenios++;


cout<<"desea guardar su disenio S/N"<<endl;
cin>>siono;
if(comprobar(siono))
    {
        cout<<"ingrese un nombre para su disenio: ";
        cin>>file_name_design;
        guardarDisenio(miDibujo,file_name_design);

    }

}
else
{
    cout<<"no selecciono un codigo de figura valido "<<endl;
}



system("pause");
limparMenu(menuFiguras);
    break;

case '3':
system("cls");
mostrarMargen();
      cout<<" cargar un dibujo "<<endl;
      cout<<"cual es el nombre de su dibujo? :  "; cin>>savedFile_name;
      cargarDibujo(matrizPantallaOUT,savedFile_name);
      mostrarMatriz(matrizPantallaOUT.dibujoPantalla,1,1);
    break;

    case '4':
      system("cls");
      mostrarMargen();
    cout<<"cargar un diseño  "<<endl;
    cout<<"cual es el nombre de su diseño? :  "; cin>>savedFile_name;
    cargarDisenio(savedFile_name,disenio2);
    mostrarDisenio(disenio2);
        system("pause");
    break;

case '5':
    system("cls");
    mostrarMargen();
      cout<<" DIBUJO ALEATORIO "<<endl;
int matrizRNDM[M][N];
int matrizRNDM2[M][N];
char nameRNDM[TAM];
cout<<"ingrese el nombre del archivo "<<endl;
cin>>nameRNDM;
llenarMatrizRandom(matrizRNDM);
matriz2arch(matrizRNDM,nameRNDM);
arch2matriz(matrizRNDM2,nameRNDM);
mostrarMatrizRandom(matrizRNDM2,5,5);
system("pause");
    break;

case '6':
   ////////// cout<<"guardar el lienzo "<<endl;
   cout<<"ingrese un nombre para su lienzo "; cin>>file_name_lienzo;
   guardarLienzoComoBinario(lienzo,matrizPantalla,miDibujo,file_name_lienzo);
system("pause");
break;

case '7':
system("cls");
mostrarMargen();
cout<<"cargar un lienzo "<<endl;
cout<<"ingrese el nombre de un lienzo "; cin>>savedFile_name;
cargarLienzoBinario(savedFile_name,lienzoOUT);
mostrarLienzo(lienzoOUT);
system("pause");

    break;
    case '8':
      system("cls");
      mostrarMargen();
  cout<<" Generar Mosaico "<<endl;
      leerDatosMosaico(mosaico,filas,columnas);
generarMosaico(mosaico,filas,columnas);
   system("pause");
    break;

    case '9':
      system("cls");
      mostrarMargen();
      animarMosaico(mosaico,filas,columnas);
    break;
        case 'X':
      system("cls");
  cout<<" gracias por usar la aplicacion "<<endl;
    break;
}

cout<<"desea seguir  usando la app ?(s/n) "<<endl;
cin>>Rsalida;
continuar=comprobar(Rsalida);
}


    return 0;
}

