import numpy as np
import matplotlib.pyplot as plt

plt.figure()
for i in range(6):
	datos = np.genfromtxt("datos" + str((i+2)*10) + ".txt", delimiter = " ", usecols = (1,2))
	plt.plot(datos[:,0], datos[:,1])


plt.show()
