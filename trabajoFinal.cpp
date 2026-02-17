#include <iostream>
#include <ctime>
#include <conio2.h>

using namespace std;
class Disparo
{
private:	
	int x;
	int y;
	clock_t tempo;
	clock_t paso;
	int velocidad;
	int contador;
	bool activo;
public:
	Disparo();
	void incioDisparo(int dx, int dy);
	bool actualizar();
	void dibujar();
	
};
Disparo::Disparo()
{
	x = 0;
	y = 0;
	velocidad = 5;
	paso = CLOCKS_PER_SEC / velocidad;
	tempo = clock();
	contador = 50;
	activo = false;
	
}
void Disparo::incioDisparo(int dx, int dy)
{
	if(!activo)
	{
		x = dx;
		y = dy-1;
		activo = true;
		tempo = clock();
	}
}
bool Disparo::actualizar()
{   if(!activo)
    {
	 return false;
	}
	if(tempo + paso < clock()){
	    gotoxy(x,y);
		cout<<" ";
		y--;
		gotoxy(x,y);
	    cout<<"I";
		tempo = clock();
	}
	if(y<=2)
	{
		gotoxy(x,y);
		cout<<" ";
		activo = false;
	}
	
	
	return activo;
}
void Disparo::dibujar()
{
	gotoxy(x,y);
	cout<<"I";
}
class Nave
{
private:
	int dx;
	int dy;
public:
	Nave();
	void moverIzquierda();
	void moverDerecha();
	void dibujar();
	void borrar();
	void disparar();
	void actualizarDisparo();
	Disparo disparo;
};
Nave::Nave()
{
	dx = 25;
	dy = 25;
}
void Nave::moverIzquierda()
{   if(dx>=3){
	dx -= 1;
}
}
void Nave::moverDerecha()
{
	if(dx<=73){
		dx += 1;
	}
}
void Nave::dibujar()
{
	gotoxy(dx,dy);
	cout<<"A";
}
void Nave::borrar()
{
	gotoxy(dx,dy);
	cout<<" ";
}
void Nave::disparar()
{
	disparo.incioDisparo(dx,dy);
	
}
void Nave::actualizarDisparo()
{
	disparo.actualizar();
}
class Juego
{
private:
	Nave nave1;
	//bool soloDibujarUnaVez;
	int bordeX;
	int bordeX2;
	int bordeY;
	int bordeY2;
public:
	Juego();
	void leerTeclas();
	void gameLoop();
	void dibujarMarco();
	
};
Juego::Juego()
{
	//soloDibujarUnaVez = true;
	bordeX = 1;
	bordeY = 1;
	bordeX2 = 1;
	bordeY2 = 1;
	
}
void Juego::dibujarMarco()
{
	if(bordeX<75)
	{
		gotoxy(bordeX,1);
		cout<<".";
		bordeX++;
	}
	
	if(bordeX2<75)
	{
		gotoxy(bordeX2,30);
		cout<<".";
		bordeX2++;
	}
	if(bordeY<30)
	{
		gotoxy(1,bordeY);
		cout<<".";
		bordeY++;
	}
	if(bordeY2<30)
	{
		gotoxy(75,bordeY2);
		cout<<".";
		bordeY2++;
	}
	
}
void Juego::leerTeclas()
{
	
	if(kbhit())
	{
		nave1.borrar();
		char tecla = getch();
		switch(tecla)
		{
		case 'a':
			nave1.moverIzquierda();
			break;
		case 'd':
			nave1.moverDerecha();
			break;
		case 'b':
			nave1.disparar();
		}
		nave1.dibujar();
	}
}
void Juego::gameLoop()
{
	
	leerTeclas();
	nave1.actualizarDisparo();
	dibujarMarco();
}




int main(int argc, char *argv[]) {
	Juego juego1;
	Nave n1;
	n1.dibujar();
	while(true)
	{
		juego1.gameLoop();
	}
	return 0;
}
