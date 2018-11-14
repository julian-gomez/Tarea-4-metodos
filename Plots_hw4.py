import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
plt.figure()
for i in range(6):
	datos = np.genfromtxt("datos" + str((i+2)*10) + ".txt", delimiter = " ", usecols = (1,2))
	plt.plot(datos[:,0], datos[:,1], label = "Angulo " + str((i + 1)*10))

plt.legend()
plt.show()

datos45 = np.genfromtxt("datos45.txt", delimiter = " ", usecols = (1,2))
plt.plot(datos45[:,0], datos45[:,1], label = "Angulo 45")
plt.legend()
plt.show()

#Para el caso de la ecuacion parcial con fronteras fijas

datosParcial = np.genfromtxt("datosFronteraFija.dat", delimiter = " ", usecols = (0,1,2))
valoresX = datosParcial[:,0]
valoresY = datosParcial[:,1]
temperatura = datosParcial[:,2]

longitud = len(temperatura)

#Realizando 3 cortes sobre los datos: el primero sera para las condiciones iniciales, el segundo para un valor intermedio y el ultimo para la configuracion final

corte1T = temperatura[0:2500]
corteFT = temperatura[(longitud-2500):longitud]
corteM1T = temperatura[5*2500:6*2500]
corteM2T = temperatura[8*2500:9*2500]

matriz1T = np.zeros((50,50))
for i in range(50):
	matriz1T[i,:] = corte1T[i*50:(i+1)*50]
print matriz1T
#Grafica 3D. Tomado de https://matplotlib.org/mpl_toolkits/mplot3d/tutorial.html

#Grafica condicion inicial
fig = plt.figure()
ax = fig.gca(projection='3d')
X = np.linspace(0.0, 0.5, 50)
Y = np.linspace(0.0, 0.5, 50)
X, Y = np.meshgrid(X, Y)
Z = matriz1T
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.show()
plt.close()

#Grafica resultado final placa
matrizFT = np.zeros((50,50))
for i in range(50):
	matrizFT[i,:] = corteFT[i*50:(i+1)*50]

fig = plt.figure()
ax = fig.gca(projection='3d')
Z = matrizFT
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.show()
plt.close()


#Graficas estados intermedios
matrizM1T = np.zeros((50,50))
for i in range(50):
	matrizM1T[i,:] = corteM1T[i*50:(i+1)*50]

fig = plt.figure()
ax = fig.gca(projection='3d')
Z = matrizM1T
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.show()
plt.close()


matrizM2T = np.zeros((50,50))
for i in range(50):
	matrizM2T[i,:] = corteM2T[i*50:(i+1)*50]

fig = plt.figure()
ax = fig.gca(projection='3d')
Z = matrizM2T
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.show()
plt.close()


#Ahora se consideran condiciones de frontera abiertas












