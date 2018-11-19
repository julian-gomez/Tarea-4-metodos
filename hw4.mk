resultados_hw4.pdf:PlotsAngulos.pdf Plots45.pdf CondicionesIniciales.pdf FijoFinal.pdf FijoIntermedio1.pdf FijoIntermedio2.pdf PromedioFijo.pdf LibreFinal.pdf LibreIntermedio1.pdf LibreIntermedio2.pdf LibrePromedio.pdf PeriodicaFinal.pdf PeriodicaIntermedia1.pdf PeriodicaIntermedia2.pdf PeriodicaPromedio.pdf resultados_hw4.tex
	pdflatex resultados_hw4.tex
Plots45.pdf:datos45.txt Plots_hw4.py
	python Plots_hw4.py
PlotsAngulos.pdf:datos10.txt datos20.txt datos30.txt datos40.txt datos50.txt datos60.txt datos70.txt Plots_hw4.py
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
datos45.txt:ODE.cpp
	g++ ODE.cpp
	./a.out
datos10.txt:ODE.cpp
	g++ ODE.cpp
	./a.out
datos20.txt:ODE.cpp
	g++ ODE.cpp
	./a.out
datos30.txt:ODE.cpp
	g++ ODE.cpp
	./a.out
datos40.txt:ODE.cpp
	g++ ODE.cpp
	./a.out
datos50.txt:ODE.cpp
	g++ ODE.cpp
	./a.out
datos60.txt:ODE.cpp
	g++ ODE.cpp
	./a.out
datos70.txt:ODE.cpp
	g++ ODE.cpp
	./a.out
	rm a.out
datosFronteraFija.dat:PDE.cpp
	g++ PDE.cpp
	./a.out
datosExtremosLibres.dat:PDE.cpp
	g++ PDE.cpp
	./a.out
datosPeriodicas.dat:PDE.cpp
	g++ PDE.cpp
	./a.out	
