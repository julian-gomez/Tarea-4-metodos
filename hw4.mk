resultados_hw4.pdf:PlotsAngulos.pdf Plots45.pdf CondicionesIniciales.pdf FijoFinal.pdf FijoIntermedio1.pdf FijoIntermedio2.pdf PromedioFijo.pdf LibreFinal.pdf LibreIntermedio1.pdf LibreIntermedio2.pdf LibrePromedio.pdf PeriodicaFinal.pdf PeriodicaIntermedia1.pdf PeriodicaIntermedia2.pdf PeriodicaPromedio.pdf Resultados_hw4.tex
	pdflatex Resultados_hw4.tex
Plots45.pdf:datosProyectil.txt Plots_hw4.py
	python Plots_hw4.py
PlotsAngulos.pdf:datosProyectil.txt Plots_hw4.py
	python Plots_hw4.py
CondicionesIniciales.pdf:datosFronteraFija.dat Plots_hw4.py
	python Plots_hw4.py
FijoFinal.pdf:datosFronteraFija.dat Plots_hw4.py
	python Plots_hw4.py
FijoIntermedio1.pdf:datosFronteraFija.dat Plots_hw4.py
	python Plots_hw4.py
FijoIntermedio2.pdf:datosFronteraFija.dat Plots_hw4.py
	python Plots_hw4.py
PromedioFijo.pdf:datosFronteraFija.dat Plots_hw4.py
	python Plots_hw4.py
LibreFinal.pdf:datosExtremosLibres.dat Plots_hw4.py
	python Plots_hw4.py
LibreIntermedio1.pdf:datosExtremosLibres.dat Plots_hw4.py
	python Plots_hw4.py
LibreIntermedio2.pdf:datosExtremosLibres.dat Plots_hw4.py
	python Plots_hw4.py
LibrePromedio.pdf:datosExtremosLibres.dat Plots_hw4.py
	python Plots_hw4.py
PeriodicaFinal.pdf:datosPeriodicas.dat Plots_hw4.py
	python Plots_hw4.py
PeriodicaIntermedia1.pdf:datosPeriodicas.dat Plots_hw4.py
	python Plots_hw4.py
PeriodicaIntermedia2.pdf:datosPeriodicas.dat Plots_hw4.py
	python Plots_hw4.py
PeriodicaPromedio.pdf:datosPeriodicas.dat Plots_hw4.py
	python Plots_hw4.py
datosProyectil.txt:ODE.cpp
	g++ ODE.cpp -o EjecutarODE
	./EjecutarODE
datosFronteraFija.dat:PDE.cpp
	g++ PDE.cpp -o EjecutarPDE
	./EjecutarPDE
datosExtremosLibres.dat:PDE.cpp
	g++ PDE.cpp -o EjecutarPDE
	./EjecutarPDE
datosPeriodicas.dat:PDE.cpp
	g++ PDE.cpp -o EjecutarPDE
	./EjecutarPDE
