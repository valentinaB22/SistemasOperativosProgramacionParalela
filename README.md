# SistemasOperativosProgramacionParalela
Entrega de trabajo final de las materias sistemas operativos y Computación paralela y distribuida
En este repositorio se puede encontrar la implementación de dos algoritmos de ordenamiento, Quicksort y Mergesort, en sus versiones secuencial y paralela. Los códigos secuenciales pueden ser ejecutados sin necesidad de instalar alguna aplicación extra, mientras que para compilar y ejecutar los códigos paralelos es necesario instalar la API OpenMP:

Windows:

http://ferestrepoca.github.io/paradigmas-de-programacion/paralela/tutoriales/openmp/instalacion_01.html

Ubuntu: 

http://ferestrepoca.github.io/paradigmas-de-programacion/paralela/tutoriales/openmp/instalacion_02.html http://ferestrepoca.github.io/paradigmas-de-programacion/paralela/tutoriales/openmp/instalacion_03.html

MAC: Correr los siguientes comandos en la consola

	brew install llvm

	brew install libomp

En los códigos paralelos se puede modificar la cantidad de threads a utilizar. Para ello es necesario modificar el valor x de la función omp_set_num_threads(x) que se encuentra en el main para ambos algoritmos.
 
Para ejecutar los códigos se puede hacer desde la consola o con un IDE. 

IDE:
Nosotras usamos Visual Code y CodeBlocks. Es necesario abrir el archivo .c que se quiera ejecutar y luego compilarlo y ejecutarlo.

Consola:

Windows:

	gcc -fopenmp archivo.c -o nombre.exe
	
	nombre.exe
	
Ubuntu:

	gcc -fopenmp archivo.c -o nombre.exe
	
	./nombre.exe
	
Mac: 

	gcc-11 -fopenmp archivo.c -o nombre
	
	./nombre

