#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

//Se definen las constantes. Todas se encuentran en sistema internacional
double radio = 0.05;
double dif = 1.62/(820.0*2.71*1000);
double lado = 0.5;
double tempVarilla = 373.0;
double tempFrontera = 283.0;
//Los deltas en el espacio son iguales. Se tiene entonces
double h = 0.01;
int N = int(lado/h);

int main()
{
	int i,j,k,l,m,n,contador;
	double deltaT = 0.5*pow(h,2)/dif;
	double ecuacion;
	double r = deltaT*dif/pow(h,2);
	double arregloFuturoX[N];
	double arregloPresenteX[N];
	double arregloFuturoY[N];
	double arregloPresenteY[N];
	//Condiciones iniciales: Suponiendo la placa a 10 grados y la barra a 100 grados

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			ecuacion = pow(i*h - lado/2.0,2) + pow(j*h -lado/2.0,2)
			if(ecuacion <= pow(lado/2.0,2))
			{
				arregloPresenteX[i] = tempVarilla;
				arregloPresenteY[j] = tempVarilla;
			}	
			else
			{
				arregloPresenteX[i] = tempFrontera;
				arregloPresenteY[j] = tempFrontera;
			}
		}	
	}

	
	
	return 0;
}

