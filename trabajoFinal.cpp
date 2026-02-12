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
}
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
	cout<<" ";
}

int main(int argc, char *argv[]) {
	
	return 0;
}

