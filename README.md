# Melody_Finder
Una aplicación para poder ordenar, administrar los componentes musicales que se encuentran en una plataforma de streaming de música, las variables que se pueden ordenar son las siguientes, como: nombre de artista, reproducciones, album, canciones, entre otros. El usuario podrá agregar nuevos artistas, ordenarlos en base a diferentes filtros, entre otras funccionalidades. 
## SICT0302B: Toma decisiones 
### Selecciona y usa una estructura lineal adecuada al problema.
Para poder separar nuestras columnas del data set en formato .csv, se utilizan vectores separados. También se implementa el uso de una matriz para poder hacer el ordenamiento que se pide. Se usa una lista doblemente ligada para poder hacer el añadido de artistas y la busqueda de los mismos.
### Selecciona un algoritmo de ordenamiento adecuado al problema.
Se utiliza como algoritmo de ordenamiento, el quick sort. El cual tiene complejida Onlog(n), en la tabla de algoritmos de complejidad. Se describe como muy bueno incluso se utilizan menos recuros para su implementación. De esta manera, se procesa más rápido el código y obtenemos una respuesta más rápida del sistema. Se usa el quick sort para ordenar los artistas, canciones y albumes de manera alfabetica.

La listas doblemente ligada tienen una complejidad lineal baja O(n), el cual es una estructura lineal. Debido a que la base de datos es pequeña no es necesario utilizar un algoritmo de complejidad alta.
## Forma de utilizarlo
Se deben de descargar todos los archivos para su funcionamiento correcto, de la misma manera es necesario tener el data set empleado en la misma carpeta donde se encuentra el archivo main y header.
## Controles de uso
Primera entrega: se entrego, el avance utilizando el metodo de quick sort, tambien se incluyo el main y el header del mismo.
Segunda entrega: se implementaron funciones de busqueda y de añadir nuevos artistas. Se usaron listas doblemente ligadas y despues se vincularon a la mariz de vectores para logrr hacer el quick sort de los elementos.

## Complejidad
Para el uso de la matriz tiene una complejidad lineal O(N), la cua
