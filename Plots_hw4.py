import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.axes3d import Axes3D, get_test_data
from matplotlib import cm
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

#Para el caso de la ecuacion parcial

datosParcial = np.genfromtxt("datosFronteraFija.dat", delimiter = " ", usecols = (0,1,2))
valoresX = datosParcial[:,0]
valoresY = datosParcial[:,1]
temperatura = datosParcial[:,2]

longitud = len(temperatura)

#Realizando 3 cortes sobre los datos: el primero sera para las condiciones iniciales, el segundo para un valor intermedio y el ultimo para la configuracion final

corte1X = valoresX[0:2500]
corte1Y = valoresY[0:2500]
corte1T = temperatura[0:2500]
matriz1T = np.zeros((50,50))
for i in range(50):
	matriz1T[i,:] = corte1T[i*50:(i+1)*50]

from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import sys
fig = plt.figure()
ax = fig.gca(projection='3d')
X = corte1X
Y = corte1Y
X, Y = np.meshgrid(X, Y)
Z = matriz1T
surf = ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.coolwarm,
linewidth=0, antialiased=False)
ax.set_zlim(-1.01, 1.01)

ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))

fig.colorbar(surf, shrink=0.5, aspect=5)

plt.show()



