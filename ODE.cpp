#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

//Se resolvera usando el metodo de Runge Kutta 4 orden
double h = 0.0001;
//Definimos las constantes:
double c = 0.2;
double g = 10.0;
double m = 0.2;
//Condiciones primera parte:
double angulo [] = {10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 45.0};
double x0 = 0.0;
double y_0 = 0.0;
double t0 = 0.0;
double v0 = 300.0;
double func_prime1X(double t, double x_1, double x_2,double y_2);
double func_prime2X(double t, double x_1, double x_2,double y_2);
double func_prime1Y(double t, double y_1, double y_2,double x_2);
double func_prime2Y(double t, double y_1, double y_2,double x_2);
string nombres [] = {"datos10.txt", "datos20.txt", "datos30.txt", "datos40.txt", "datos50.txt", "datos60.txt", "datos70.txt", "datos45.txt"};

int main()
{
	
	//Resolviendo
	int i,j,k,l;
	double valoresX[8];
	double t = t0;
	double posY;
	double posX;
	double velY;
	double velX;
	int req;
	int numPuntos;
	double kx1_1,kx2_1,kx3_1,kx4_1,kx1_2,kx2_2,kx3_2,kx4_2,promediox1,promediox2;
	double ky1_1,ky2_1,ky3_1,ky4_1,ky1_2,ky2_2,ky3_2,ky4_2,promedioy1,promedioy2;
	for(k = 0; k < 8; k++)
	{
		ofstream archivo_salida(nombres[k]);
		req = 1;
		numPuntos = 0;
		t = t0;
	 	posY = y_0;
		posX = x0;
		velY = v0*sin(angulo[k]*M_PI/180.0);
		velX = v0*cos(angulo[k]*M_PI/180.0);
		archivo_salida << t << " " << posX << " " << posY << " " << velX << " " << velY << endl;
		while(req == 1)
		{
			numPuntos += 1;
			ky1_1 = func_prime1Y(t,posY,velY,velX);
			ky1_2 = func_prime2Y(t,posY,velY,velX);
		
			ky2_1 = func_prime1Y(t + h/2.0, posY + h/2.0*ky1_1, velY + h/2.0*ky1_2,velX);
			ky2_2 = func_prime2Y(t + h/2.0, posY + h/2.0*ky1_1, velY + h/2.0*ky1_2,velX);

			ky3_1 = func_prime1Y(t + h/2.0, posY + h/2.0*ky2_1, velY + h/2.0*ky2_2,velX);
			ky3_2 = func_prime2Y(t + h/2.0, posY + h/2.0*ky2_1, velY + h/2.0*ky2_2,velX);

			ky4_1 = func_prime1Y(t + h, posY + h*ky3_1, velY + h*ky3_2,velX);
			ky4_2 = func_prime2Y(t + h, posY + h*ky3_1, velY + h*ky3_2,velX);

			kx1_1 = func_prime1X(t,posX,velX,velY);
			kx1_2 = func_prime2X(t,posX,velX,velY);
			
			kx2_1 = func_prime1X(t + h/2.0,posX + h/2.0*kx1_1, velX + h/2.0*kx1_2,velY);
			kx2_2 = func_prime2X(t + h/2.0,posX + h/2.0*kx1_1, velX + h/2.0*kx1_2,velY);

			kx3_1 = func_prime1X(t + h/2.0,posX + h/2.0*kx2_1, velX + h/2.0*kx2_2,velY);
			kx3_2 = func_prime2X(t + h/2.0,posX + h/2.0*kx2_1, velX + h/2.0*kx2_2,velY);

			kx4_1 = func_prime1X(t + h,posX + h*kx3_1, velX + h*kx3_2,velY);
			kx4_2 = func_prime2X(t + h,posX + h*kx3_1, velX + h*kx3_2,velY);			

			promedioy1 = (ky1_1 + 2.0*ky2_1 + 2.0*ky3_1 + ky4_1)/6.0;
			promedioy2 = (ky1_2 + 2.0*ky2_2 + 2.0*ky3_2 + ky4_2)/6.0;

			promediox1 = (kx1_1 + 2.0*kx2_1 + 2.0*kx3_1 + kx4_1)/6.0;
			promediox2 = (kx1_2 + 2.0*kx2_2 + 2.0*kx3_2 + kx4_2)/6.0;
		
			t = t + h;
			posY = posY + h*promedioy1;
			velY = velY + h*promedioy2;
			posX = posX + h*promediox1;
			velY = velY + h*promediox2;
			if(posY <= 0.0)
			{
				req = 0;
			}
		}
	
		//Ya contamos con el numero de puntos que hay hasta que el proyectil alcanza el suelo de nuevo. Ahora, haremos el mismo proceso, pero imprimiendo los 5 datos: tiempo, posicionX, posicionY, velocidadX, velocidadY
		t = t0;
	 	posY = y_0;
		posX = x0;
		velY = v0*sin(angulo[k]*M_PI/180.0);
		velX = v0*cos(angulo[k]*M_PI/180.0);
		for(i = 0; i < numPuntos - 1; i++)
		{
			ky1_1 = func_prime1Y(t,posY,velY,velX);
			ky1_2 = func_prime2Y(t,posY,velY,velX);
		
			ky2_1 = func_prime1Y(t + h/2.0, posY + h/2.0*ky1_1, velY + h/2.0*ky1_2,velX);
			ky2_2 = func_prime2Y(t + h/2.0, posY + h/2.0*ky1_1, velY + h/2.0*ky1_2,velX);

			ky3_1 = func_prime1Y(t + h/2.0, posY + h/2.0*ky2_1, velY + h/2.0*ky2_2,velX);
			ky3_2 = func_prime2Y(t + h/2.0, posY + h/2.0*ky2_1, velY + h/2.0*ky2_2,velX);

			ky4_1 = func_prime1Y(t + h, posY + h*ky3_1, velY + h*ky3_2,velX);
			ky4_2 = func_prime2Y(t + h, posY + h*ky3_1, velY + h*ky3_2,velX);

			kx1_1 = func_prime1X(t,posX,velX,velY);
			kx1_2 = func_prime2X(t,posX,velX,velY);
			
			kx2_1 = func_prime1X(t + h/2.0,posX + h/2.0*kx1_1, velX + h/2.0*kx1_2,velY);
			kx2_2 = func_prime2X(t + h/2.0,posX + h/2.0*kx1_1, velX + h/2.0*kx1_2,velY);

			kx3_1 = func_prime1X(t + h/2.0,posX + h/2.0*kx2_1, velX + h/2.0*kx2_2,velY);
			kx3_2 = func_prime2X(t + h/2.0,posX + h/2.0*kx2_1, velX + h/2.0*kx2_2,velY);

			kx4_1 = func_prime1X(t + h,posX + h*kx3_1, velX + h*kx3_2,velY);
			kx4_2 = func_prime2X(t + h,posX + h*kx3_1, velX + h*kx3_2,velY);			

			promedioy1 = (ky1_1 + 2.0*ky2_1 + 2.0*ky3_1 + ky4_1)/6.0;
			promedioy2 = (ky1_2 + 2.0*ky2_2 + 2.0*ky3_2 + ky4_2)/6.0;

			promediox1 = (kx1_1 + 2.0*kx2_1 + 2.0*kx3_1 + kx4_1)/6.0;
			promediox2 = (kx1_2 + 2.0*kx2_2 + 2.0*kx3_2 + kx4_2)/6.0;
		
			t = t + h;
			posY = posY + h*promedioy1;
			velY = velY + h*promedioy2;
			posX = posX + h*promediox1;
			velY = velY + h*promediox2;
			archivo_salida << t << " " << posX << " " << posY << " " << velX << " " << velY << endl;
			if ((i == numPuntos - 2))
			{
				valoresX[k] = posX;
				if(k == 7)
				{
					cout << "La distancia recorrida por el proyectil para un angulo de 45 es de " << posX << endl;
				}	
			}
			
		}
	}
	//Ahora, hallaremos el valor maximo en X
	double mayor = 0.0;
	l = 0;
	for(j = 0; j < 8; j++)
	{
		if(valoresX[j] >= mayor)
		{
			mayor = valoresX[j];
			l = j;	
		}
	}
	cout << "El angulo que corresponde a la mayor distancia alcanzada es: " << angulo[l] << ". La distancia es de: " << valoresX[l] << endl;
	return 0;
}

double func_prime1X(double t, double x_1, double x_2, double y_2)
{
	return x_2;
}

double func_prime2X(double t, double x_1, double x_2, double y_2)
{
	return -c/m*pow((pow(x_2,2) + pow(y_2,2)),1.0/2.0)*x_2;
}

double func_prime1Y(double t, double y_1, double y_2, double x_2)
{
	return y_2;
}
double func_prime2Y(double t, double y_1, double y_2, double x_2)
{
	return -g-c/m*pow((pow(x_2,2) + pow(y_2,2)),1.0/2.0)*y_2;
}


























