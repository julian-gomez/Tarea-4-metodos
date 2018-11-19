import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
#Ecuacion primera parte
plt.figure()
for i in range(6):
	datos = np.genfromtxt("datos" + str((i+2)*10) + ".txt", delimiter = " ", usecols = (1,2))
	plt.plot(datos[:,0], datos[:,1], label = "Angulo " + str((i + 1)*10))
#Plot de los angulos distintos a 45
plt.legend()
plt.title("Sol ODE diversos angulos")
plt.savefig("PlotsAngulos.pdf")
plt.close()

plt.figure()
datos45 = np.genfromtxt("datos45.txt", delimiter = " ", usecols = (1,2))
plt.plot(datos45[:,0], datos45[:,1], label = "Angulo 45")
plt.legend()
plt.title("Sol ODE angulo 45")
plt.savefig("Plots45.pdf")
plt.close()


#Para el caso de la ecuacion parcial con fronteras fijas
datosParcial = np.genfromtxt("datosFronteraFija.dat", delimiter = " ", usecols = (0,1,2))
valoresX = datosParcial[:,0]
valoresY = datosParcial[:,1]
temperatura = datosParcial[:,2]
longitud = len(temperatura)
#Realizando 3 cortes sobre los datos: el primero sera para las condiciones iniciales, el segundo para un valor intermedio y el ultimo para la configuracion final

corte1T = temperatura[0:2500]
corteFT = temperatura[(longitud-2500):longitud]
corteM1T = temperatura[15*2500:16*2500]
corteM2T = temperatura[29*2500:30*2500]
#Realizamos un promedio de las temperaturas
temperaturaPromedioFijo = np.zeros((2500))
for i in range(2500):
	temperaturaPromedioFijo[i] = temperatura[i:longitud:2500].mean()
matriz1T = np.zeros((50,50))
for i in range(50):
	matriz1T[i,:] = corte1T[i*50:(i+1)*50]
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
plt.title("Condiciones iniciales")
plt.savefig("CondicionesIniciales.pdf")
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
plt.title("Equilibrio frontera fijas")
plt.savefig("FijoFinal.pdf")
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
plt.title("Estado Intermedio 1 Fronteras Fijas")
plt.savefig("FijoIntermedio1.pdf")
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
plt.title("Estado Intermedio 2 Fronteras Fijas")
plt.savefig("FijoIntermedio2.pdf")
plt.close()

#Grafica Promedio Fijos
matrizPT = np.zeros((50,50))
for i in range(50):
	matrizPT[i,:] = temperaturaPromedioFijo[i*50:(i+1)*50]
fig = plt.figure()
ax = fig.gca(projection='3d')
Z = matrizPT
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.title("Promedio Fronteras Fijas")
plt.savefig("PromedioFijo.pdf")
plt.close()



#Ahora se consideran condiciones de frontera abiertas
datosParcialLibres = np.genfromtxt("datosExtremosLibres.dat", delimiter = " ", usecols = (0,1,2))
temperaturaLibre = datosParcialLibres[:,2]
longitudLibre = len(temperaturaLibre)
corteFTL = temperaturaLibre[(longitudLibre-2500):longitudLibre]
corteM1TL = temperaturaLibre[50*2500:51*2500]
corteM2TL = temperaturaLibre[180*2500:181*2500]
temperaturaPromedioLibres = np.zeros((2500))
for i in range(2500):
	temperaturaPromedioLibres[i] = temperaturaLibre[i:longitudLibre:2500].mean()
matrizFTL = np.zeros((50,50))
matrizM1TL = np.zeros((50,50))
matrizM2TL = np.zeros((50,50))
matrizPTL = np.zeros((50,50))
for i in range(50):
	matrizFTL[i,:] = corteFTL[i*50:(i+1)*50]
fig = plt.figure()
ax = fig.gca(projection='3d')
Z = matrizFTL
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.title("Equilibrio Fronteras Libres")
plt.savefig("LibreFinal.pdf")
plt.close()

for i in range(50):
	matrizM1TL[i,:] = corteM1TL[i*50:(i+1)*50]
fig = plt.figure()
ax = fig.gca(projection='3d')
Z = matrizM1TL
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.title("Estado Intermedio 1 Fronteras Libres")
plt.savefig("LibreIntermedio1.pdf")
plt.close()

for i in range(50):
	matrizM2TL[i,:] = corteFTL[i*50:(i+1)*50]
fig = plt.figure()
ax = fig.gca(projection='3d')
Z = matrizM2TL
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.title("Estado Intermedio 2 Fronteras Libres")
plt.savefig("LibreIntermedio2.pdf")
plt.close()

for i in range(50):
	matrizPTL[i,:] = temperaturaPromedioLibres[i*50:(i+1)*50]
fig = plt.figure()
ax = fig.gca(projection='3d')
Z = matrizPTL
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.title("Promedio Fronteras Libres")
plt.savefig("LibrePromedio.pdf")
plt.close()

#Ahora se consideran condiciones de frontera periodicas
datosParcialPeriodica = np.genfromtxt("datosPeriodicas.dat", delimiter = " ", usecols = (0,1,2))
temperaturaPeriodica = datosParcialPeriodica[:,2]
longitudPeriodica = len(temperaturaPeriodica)
corteFTP = temperaturaPeriodica[(longitudPeriodica-2500):longitudPeriodica]
corteM1TP = temperaturaPeriodica[50*2500:51*2500]
corteM2TP = temperaturaPeriodica[180*2500:181*2500]
temperaturaPromedioPer = np.zeros((2500))
for i in range(2500):
	temperaturaPromedioPer[i] = temperaturaPeriodica[i:longitudPeriodica:2500].mean()
matrizFTP = np.zeros((50,50))
matrizM1TP = np.zeros((50,50))
matrizM2TP = np.zeros((50,50))
matrizPTP = np.zeros((50,50))
for i in range(50):
	matrizFTP[i,:] = corteFTP[i*50:(i+1)*50]
fig = plt.figure()
ax = fig.gca(projection='3d')
Z = matrizFTP
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.title("Equilibrio Periodicas")
plt.savefig("PeriodicaFinal.pdf")
plt.close()

for i in range(50):
	matrizM1TP[i,:] = corteFTP[i*50:(i+1)*50]
fig = plt.figure()
ax = fig.gca(projection='3d')
Z = matrizM1TP
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.title("Estado Intermedio 1 Fronteras Periodicas")
plt.savefig("PeriodicaIntermedia1.pdf")
plt.close()

for i in range(50):
	matrizM2TP[i,:] = corteFTP[i*50:(i+1)*50]
fig = plt.figure()
ax = fig.gca(projection='3d')
Z = matrizM2TP
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.title("Estado Intermedio 2 Fronteras Periodicas")
plt.savefig("PeriodicaIntermedia2.pdf")
plt.close()

for i in range(50):
	matrizPTP[i,:] = temperaturaPromedioPer[i*50:(i+1)*50]
fig = plt.figure()
ax = fig.gca(projection='3d')
Z = matrizPTP
surf = ax.plot_surface(X, Y, Z, cmap=cm.coolwarm, linewidth=0, antialiased=False)
ax.zaxis.set_major_locator(LinearLocator(10))
ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_zlabel('Temperatura [K]')
plt.title("Promedio Fronteras Periodicas")
plt.savefig("PeriodicaPromedio.pdf")
plt.close()






