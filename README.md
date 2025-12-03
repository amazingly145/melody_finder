# Melody_Finder
## Resumen
Melody Finder es una aplicacio para poder administrar la base de datos en base a los artistas, albumes y canciones que la discográfica tiene. La discográfica contiene nombre de los artistas sus canciones y albumes. Se podran ordenar alfabeticamente en base a lo que el usuario escoga, es decir, 
## SICT0302B: Toma decisiones 
### Selecciona y usa una estructura lineal adecuada al problema.
Para poder separar nuestras columnas del data set en formato .csv, se utilizan vectores separados. También se implementa el uso de una matriz para poder hacer el ordenamiento que se pide. Se usa una lista doblemente ligada para poder hacer el añadido de artistas y la busqueda de los mismos, debido a que su complejidad es de O(n), es decir tambien se mantiene linel, pero debido a que son pocas las columnas que se implementaron funciona de una manera rápida y eficiente.
### Selecciona un algoritmo de ordenamiento adecuado al problema.
Se utiliza como algoritmo de ordenamiento, el quick sort. El cual tiene complejida Onlog(n), en la tabla de algoritmos de complejidad. Se describe como muy bueno incluso se utilizan menos recuros para su implementación. De esta manera, se procesa más rápido el código y obtenemos una respuesta más rápida del sistema. Se usa el quick sort para ordenar los artistas, canciones y albumes de manera alfabetica.

La listas doblemente ligada tienen una complejidad lineal baja O(n), el cual es una estructura lineal. Debido a que la base de datos es pequeña y con pocas columnas o rubros no es necesario utilizar un algoritmo de complejidad alta, esto hace que el funcionamiento del mismo se eficiente y las busquedas puedan ser rapidas. Aunque si se desea amplear la base de datos pudiera causar un problema en la area de la velocidad de recopilacion de datos.
## Forma de utilizarlo
Se deben de descargar todos los archivos para su funcionamiento correcto, de la misma manera es necesario tener el data set empleado en la misma carpeta donde se encuentra el archivo main y header. Se debe de desargar el archivo .csv para que se puedan agregar los datos al programa, de la misma manera es necesario seguir todas las especificaciones e intrucciones que se pide a la hora de usar las funciones.

## Algoritmos usados
Algoritmo de ordenamiento: se utilizo un Quick Sort, el cual tiene complejidad de O(nlog(n)). Para hacer el ordenamento se usa una matriz de vectores, en base a su indice principal que va cambiando dependiendo del tipo de ordenamiento que se quiere hacer.
estructura de busqueda: se usa una lista doblemente ligada, la cual tiene una complejidad lineal de O(n). 
Algoritmo de inserción: lista doblemente ligada.

## Complejidad
Para el uso de la matriz tiene una complejidad lineal O(N), siendo una complejidad lineal y esta se implementa en el Quick Sort, el cual tiene una complejidad de O(nlogn). Para que se pueda hacer la busqueda de manera mas eficiente y se pueda tener un resultado mas rapido. 

## Controles de uso
Primera entrega 22 de septiembre del 2025: se entrego, el avance utilizando el metodo de quick sort, tambien se incluyo el main y el header del mismo.
Segunda entrega: se implementaron funciones de busqueda y de añadir nuevos artistas. Se usaron listas doblemente ligadas y despues se vincularon a la mariz de vectores para logrr hacer el quick sort de los elementos.

Segunda entrega 22 de octubre del 2025: implementacion de listas doblemente ligadas, taambien se implementaron funciones para agregar nuevos artistas, canciones y albumes. Se implemento una funcion de busqueda de artistas, albumes y canciones.

Tercera entrega 19 de noviembre del 2025: se implemento una funccion pr poder guardar los cambios en el CSV, es decir para que el mismo se vaya actualizando. Y se puedan ver los cambios reflejados con respecto a los artiistas, canciones y albumes. 
