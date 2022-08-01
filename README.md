# SistemasOperativosProgramacionParalela
Entrega de trabajo final de las materias sistemas operativos y Computacion paralela y distribuida

En este repositorio se puede encontrar la implementación de dos algoritmos de ordenamiento, Quicksort y Mergesort, en sus versiones secuencial y paralela.
Los códigos secuenciales pueden ser ejecutados sin necesidad de instalar alguna aplicaccion extra, mientras que para compilar y ejecutar los códigos paralelos es necesario instalar la API OpenMP:

Windows: http://ferestrepoca.github.io/paradigmas-de-programacion/paralela/tutoriales/openmp/instalacion_01.html

Ubuntu: http://ferestrepoca.github.io/paradigmas-de-programacion/paralela/tutoriales/openmp/instalacion_02.html 
http://ferestrepoca.github.io/paradigmas-de-programacion/paralela/tutoriales/openmp/instalacion_03.html 

MAC: correr los siguientes comandos en la consola

brew install llvm  

brew install libomp
	
  En los códigos paralelos se puede modificar la cantidad de threads a utilizar. Para ello es necesario modificar el valor x de la función omp_set_num_threads(x) que se encuentra en el main para ambos algoritmos.
