import numpy as np
import matplotlib.pyplot as plt

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
