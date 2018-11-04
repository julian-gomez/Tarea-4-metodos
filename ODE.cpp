#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

//Se resolvera usando el metodo de Runge Kutta 4 orden
double h = 0.001;
//Definimos las constantes:
double c = 0.2;
double g = 10.0;
double m = 0.2;
//Condiciones primera parte:
double theta = 45.0;
double x0 = 0.0;
double y_0 = 0.0;
double t0 = 0.0;
double v0 = 300.0;
double func_prime1X(double t, double x_1, double x_2);
double func_prime2X(double t, double x_1, double x_2);
double func_prime1Y(double t, double y_1, double y_2);
double func_prime2Y(double t, double y_1, double y_2);

int main()
{
	ofstream archivo_salida("datos.txt");
	//Resolviendo para x
	int i,j,k,l;
	double t = t0;
	double posY = y_0;
	double posX = x0;
	double velY = v0*sin(theta*M_PI/180.0);
	double velX = v0*cos(theta*M_PI/180.0);
	int req = 1;
	int numPuntos = 0;
	double kx1_1,kx2_1,kx3_1,kx4_1,kx1_2,kx2_2,kx3_2,kx4_2,promediox1,promediox2;
	double ky1_1,ky2_1,ky3_1,ky4_1,ky1_2,ky2_2,ky3_2,ky4_2,promedioy1,promedioy2;
	while(req == 1)
	{
		numPuntos += 1;
		ky1_1 = func_prime1Y(t,posY,velY);
		ky1_2 = func_prime2Y(t,posY,velY);
		
		ky2_1 = func_prime1Y(t + h/2.0, posY + h/2.0*ky1_1, velY + h/2.0*ky1_2);
		ky2_2 = func_prime2Y(t + h/2.0, posY + h/2.0*ky1_1, velY + h/2.0*ky1_2);

		ky3_1 = func_prime1Y(t + h/2.0, posY + h/2.0*ky2_1, velY + h/2.0*ky2_2);
		ky3_2 = func_prime2Y(t + h/2.0, posY + h/2.0*ky2_1, velY + h/2.0*ky2_2);

		ky4_1 = func_prime1Y(t + h, posY + h*ky3_1, velY + h*ky3_2);
		ky4_2 = func_prime2Y(t + h, posY + h*ky3_1, velY + h*ky3_2);

		promedioy1 = (ky1_1 + 2.0*ky2_1 + 2.0*ky3_1 + ky4_1)/6.0;
		promedioy2 = (ky1_2 + 2.0*ky2_2 + 2.0*ky3_2 + ky4_2)/6.0;
		
		t = t + h;
		posY = posY + h*promedioy1;
		velY = velY + h*promedioy2;
		if(posY <= 0.0)
		{
			req = 0;
		}
	}
	//Ya contamos con el numero de puntos que hay hasta que el proyectil alcanza el suelo de nuevo. Ahora, haremos el mismo proceso, pero imprimiendo los 5 datos: tiempo, posicionX, posicionY, velocidadX, velocidadY
	t = t0;
	posY = y_0;
	velY = v0*sin(theta*M_PI/180.0);
	archivo_salida << t << " " << posX << " " << posY << " " << velX << " " << velY << endl;
	for(i = 0; i < numPuntos - 1; i++)
	{
		ky1_1 = func_prime1Y(t,posY,velY);
		ky1_2 = func_prime2Y(t,posY,velY);
		
		ky2_1 = func_prime1Y(t + h/2.0, posY + h/2.0*ky1_1, velY + h/2.0*ky1_2);
		ky2_2 = func_prime2Y(t + h/2.0, posY + h/2.0*ky1_1, velY + h/2.0*ky1_2);

		ky3_1 = func_prime1Y(t + h/2.0, posY + h/2.0*ky2_1, velY + h/2.0*ky2_2);
		ky3_2 = func_prime2Y(t + h/2.0, posY + h/2.0*ky2_1, velY + h/2.0*ky2_2);

		ky4_1 = func_prime1Y(t + h, posY + h*ky3_1, velY + h*ky3_2);
		ky4_2 = func_prime2Y(t + h, posY + h*ky3_1, velY + h*ky3_2);

		promedioy1 = (ky1_1 + 2.0*ky2_1 + 2.0*ky3_1 + ky4_1)/6.0;
		promedioy2 = (ky1_2 + 2.0*ky2_2 + 2.0*ky3_2 + ky4_2)/6.0;

		kx1_1 = func_prime1X(t,posX,velX);
		kx1_2 = func_prime2X(t,posX,velX);
		
		kx2_1 = func_prime1X(t + h/2.0, posX + h/2.0*kx1_1, velX + h/2.0*kx1_2);
		kx2_2 = func_prime2X(t + h/2.0, posX + h/2.0*kx1_1, velX + h/2.0*kx1_2);

		kx3_1 = func_prime1X(t + h/2.0, posX + h/2.0*kx2_1, velX + h/2.0*kx2_2);
		kx3_2 = func_prime2X(t + h/2.0, posX + h/2.0*kx2_1, velX + h/2.0*kx2_2);

		kx4_1 = func_prime1X(t + h, posX + h*kx3_1, velX + h*kx3_2);
		kx4_2 = func_prime2X(t + h, posX + h*kx3_1, velX + h*kx3_2);

		promediox1 = (kx1_1 + 2.0*kx2_1 + 2.0*kx3_1 + kx4_1)/6.0;
		promediox2 = (kx1_2 + 2.0*kx2_2 + 2.0*kx3_2 + kx4_2)/6.0;
		
		t = t + h;
		posY = posY + h*promedioy1;
		velY = velY + h*promedioy2;
		posX = posX + h*promediox1;
		velX = velX + h*promediox2;
		archivo_salida << t << " " << posX << " " << posY << " " << velX << " " << velY << endl;
		if (i == numPuntos - 2)
		{
			cout << "La distancia recorrida por el proyectil es del " << posX << endl;		
		}
	}
	
	return 0;
}

double func_prime1X(double t, double x_1, double x_2)
{
	return x_2;
}

double func_prime2X(double t, double x_1, double x_2)
{
	return -c/(m*cos(theta*M_PI/180.0))*abs(x_2)*x_2;
}

double func_prime1Y(double t, double y_1, double y_2)
{
	return y_2;
}
double func_prime2Y(double t, double y_1, double y_2)
{
	return -g-c/(m*sin(theta*M_PI/180.0))*abs(y_2)*y_2;
}


























