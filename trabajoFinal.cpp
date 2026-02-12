#include <iostream>
#include <conio2.h>
using namespace std;

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
};
Nave::Nave()
{
	dx = 25;
	dy = 25;
}
void Nave::moverIzquierda()
{
	dx -= 1;
}
void Nave::moverDerecha()
{
	dx += 1;
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

class Juego
{
private:
	Nave nave1;
	//bool soloDibujarUnaVez;
public:
	Juego();
	void leerTeclas();
	void gameLoop();
	
};
Juego::Juego()
{
	//soloDibujarUnaVez = true;
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
		}
		nave1.dibujar();
	}
}
void Juego::gameLoop()
{
	
     leerTeclas();
	
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

