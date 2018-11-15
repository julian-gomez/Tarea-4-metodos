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
	double deltaT = 0.0005*pow(h,2)/dif;
	double ecuacion;
	double r = deltaT*dif/pow(h,2);
	double matrizFuturo[N][N];
	double matrizPresente[N][N];
	ofstream archivo_salida("datosFronteraFija.dat");
	ofstream archivo_salida2("datosExtremosLibres.dat");
	ofstream archivo_salida3("datosPeriodicas.dat");
	//Condiciones iniciales: Suponiendo la placa a 10 grados y la barra a 100 grados
	//Condicion de extremos fijos
	for(i = 0; i < N; i++)
	{
		matrizFuturo[N-1][i] = tempFrontera;
		matrizFuturo[i][N-1] = tempFrontera;
		matrizFuturo[0][i] = tempFrontera;
		matrizFuturo[i][0] = tempFrontera;
	}
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			ecuacion = pow(i*h - lado/2.0,2) + pow(j*h -lado/2.0,2);
			if(ecuacion <= pow(radio,2) )
			{
				matrizPresente[i][j] = tempVarilla;
			}	
			else
			{
				matrizPresente[i][j] = tempFrontera;
			}
			archivo_salida << i*h << " " << j*h << " " << matrizPresente[i][j] << endl;
		}	
	}
	//Haremos la siguiente condicion futuro
	double suma = 0.0;
	contador = 0;
	bool condicion = false;
	while(condicion == false)
	{
		suma = 0.0;
		for(m = 1; m < N-1; m++)
		{
			for(n = 1; n < N-1; n++)
			{
				matrizFuturo[m][n] = matrizPresente[m][n] + r*(matrizPresente[m+1][n] + matrizPresente[m][n+1] - 4.0*matrizPresente[m][n] + matrizPresente[m-1][n] + matrizPresente[m][n-1]);
				ecuacion = pow(m*h - lado/2.0,2) + pow(n*h -lado/2.0,2);
			if(ecuacion <= pow(radio,2) )
			{
				matrizFuturo[m][n] = tempVarilla;
			}	
			}
		}
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)
			{
				if(abs(matrizFuturo[i][j] - matrizPresente[i][j]) <= 0.00001)
				{
					suma += 1.0;
				}		
			}		
		}
		contador += 1;
		if(contador == 10000)
		{
			for(k = 0; k < N; k ++)
			{
				for(l = 0; l < N; l++)
				{
					archivo_salida << k*h << " " << l*h << " " << matrizPresente[k][l] << endl;
				}
			}
			contador = 0;
		}
		for(m = 0; m < N; m++)
		{
			for(n = 0; n < N; n++)
			{
				matrizPresente[m][n] = matrizFuturo[m][n];			
			}		
		}
		if(suma == N*N)
		{
			condicion = true;
		}
		
	}
	//Imprimimos el resultado final
	for(m = 0; m < N; m++)
	{
		for(n = 0; n < N; n++)
		{
			archivo_salida << m*h << " " << n*h << " " << matrizPresente[m][n] << endl;			
		}		
	}
	//Ahora consideramos extremos libres
	//Condicion Inicial
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			ecuacion = pow(i*h - lado/2.0,2) + pow(j*h -lado/2.0,2);
			if(ecuacion <= pow(radio,2) )
			{
				matrizPresente[i][j] = tempVarilla;
			}	
			else
			{
				matrizPresente[i][j] = tempFrontera;
			}
			archivo_salida2 << i*h << " " << j*h << " " << matrizPresente[i][j] << endl;
		}	
	}
	suma = 0.0;
	contador = 0;
	condicion = false;
	while(condicion == false)
	{
		suma = 0.0;
		for(m = 1; m < N-1; m++)
		{
			for(n = 1; n < N-1; n++)
			{
				matrizFuturo[m][n] = matrizPresente[m][n] + r*(matrizPresente[m+1][n] + matrizPresente[m][n+1] - 4.0*matrizPresente[m][n] + matrizPresente[m-1][n] + matrizPresente[m][n-1]);
				ecuacion = pow(m*h - lado/2.0,2) + pow(n*h -lado/2.0,2);
			if(ecuacion <= pow(radio,2) )
			{
				matrizFuturo[m][n] = tempVarilla;
			}	
			}
		}
		for(k = 0; k < N; k++)
		{
			matrizFuturo[0][k] = matrizFuturo[1][k];
			matrizFuturo[k][0] = matrizFuturo[k][1];
			matrizFuturo[N-1][k] = matrizFuturo[N-2][k];
			matrizFuturo[k][N-1] = matrizFuturo[k][N-2];
		}
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)
			{
				if(abs(matrizFuturo[i][j] - matrizPresente[i][j]) <= 0.00001)
				{
					suma += 1.0;
				}		
			}		
		}
		contador += 1;
		if(contador == 10000)
		{
			for(k = 0; k < N; k ++)
			{
				for(l = 0; l < N; l++)
				{
					archivo_salida2 << k*h << " " << l*h << " " << matrizPresente[k][l] << endl;
				}
			}
			contador = 0;
		}
		for(m = 0; m < N; m++)
		{
			for(n = 0; n < N; n++)
			{
				matrizPresente[m][n] = matrizFuturo[m][n];			
			}		
		}
		if(suma == N*N)
		{
			condicion = true;
		}
		
	}
	//Imprimimos el resultado final
	for(m = 0; m < N; m++)
	{
		for(n = 0; n < N; n++)
		{
			archivo_salida2 << m*h << " " << n*h << " " << matrizPresente[m][n] << endl;			
		}		
	}

	//Finalmente consideremos condiciones periodicas
	//Condicion Inicial
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			ecuacion = pow(i*h - lado/2.0,2) + pow(j*h -lado/2.0,2);
			if(ecuacion <= pow(radio,2) )
			{
				matrizPresente[i][j] = tempVarilla;
			}	
			else
			{
				matrizPresente[i][j] = tempFrontera;
			}
			archivo_salida3 << i*h << " " << j*h << " " << matrizPresente[i][j] << endl;
		}	
	}
	suma = 0.0;
	contador = 0;
	condicion = false;
	while(condicion == false)
	{
		suma = 0.0;
		for(m = 1; m < N-1; m++)
		{
			for(n = 1; n < N-1; n++)
			{
				matrizFuturo[m][n] = matrizPresente[m][n] + r*(matrizPresente[m+1][n] + matrizPresente[m][n+1] - 4.0*matrizPresente[m][n] + matrizPresente[m-1][n] + matrizPresente[m][n-1]);
				ecuacion = pow(m*h - lado/2.0,2) + pow(n*h -lado/2.0,2);
			if(ecuacion <= pow(radio,2) )
			{
				matrizFuturo[m][n] = tempVarilla;
			}	
			}
		}
		for(k = 0; k < N; k++)
		{
			matrizFuturo[0][k] = matrizFuturo[N-2][k];
			matrizFuturo[k][0] = matrizFuturo[k][N-2];
			matrizFuturo[N-1][k] = matrizFuturo[1][k];
			matrizFuturo[k][N-1] = matrizFuturo[k][1];
		}
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)
			{
				if(abs(matrizFuturo[i][j] - matrizPresente[i][j]) <= 0.00001)
				{
					suma += 1.0;
				}		
			}		
		}
		contador += 1;
		if(contador == 10000)
		{
			for(k = 0; k < N; k ++)
			{
				for(l = 0; l < N; l++)
				{
					archivo_salida3 << k*h << " " << l*h << " " << matrizPresente[k][l] << endl;
				}
			}
			contador = 0;
		}
		for(m = 0; m < N; m++)
		{
			for(n = 0; n < N; n++)
			{
				matrizPresente[m][n] = matrizFuturo[m][n];			
			}		
		}
		if(suma == N*N)
		{
			condicion = true;
		}
		
	}
	//Imprimimos el resultado final
	for(m = 0; m < N; m++)
	{
		for(n = 0; n < N; n++)
		{
			archivo_salida3 << m*h << " " << n*h << " " << matrizPresente[m][n] << endl;			
		}		
	}

	
		
	return 0;
}

