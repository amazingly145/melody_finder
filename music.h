using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <sstream>
#include <list>
#include <cctype>


/*Clase Sort
 * Como base principal tenemos el quick sort
 * Tenemos los metodos para aplicar el metodo
 * Y la base se pueda ordenar de manera alfabetica*/
template <class T>
class Sort{
    private:
        //Metodo de division del vector
        int division(std::vector<vector<T>>&, int, int, int);
        //Metodo para hacer el cambio
        void swap(std::vector<vector<T>>&, int, int, int);
    public:
        //Metodo para hacer el sort
        std::vector<vector<T>> quickSort(std::vector<vector<T>>&, int, int, int);
};

/*Funcion para hacer el swap
 * Cambiamos de lugar los valores
 * En base a los indices*/
template <class T>
void Sort<T>::swap(std::vector<vector<T>> &source, int i, int j, int indice_a_sortear){
    //Creamos la variable auxiliar para hacer el cambio de variables
    auto aux = source[i];
    source[i] = source[j];
    source[j] = aux;
}

/*Funcion division
Divide la lista en dos; en los de menor valor
y lo de mayor valor*/
template <class T>
int Sort<T>::division(std::vector<vector<T>> &source, int low, int high, int indice_a_sortear){
    //Creamos un pivote, en base al valor que esta en medio
    //para poder dividir la lista en dos
    T pivot = source[high][indice_a_sortear];
    //i es el valor mas bajo - 1
    int i = low - 1;
    //Creamos un ciclo for para recorrer
    for (int j = low; j <= high - 1; j++) {
        //Si es menor que el pivote
        if (source[j][indice_a_sortear] < pivot) {
            //aumentamos la i
            i++;
            //hacemos el swap
            swap(source, i, j, indice_a_sortear);
        }
    }
    //Si es mayor hacemos un swap
    swap(source, i+1, high, indice_a_sortear);
    //Regresa el valor que sigue de la i
    return i + 1;
}

template <class T>
vector<vector<T>> Sort<T>::quickSort(std::vector<std::vector<T>> &source, int low, int high, int indice_a_sortear){
    if(low < high){
        //dividimos los vectores, en base al mas pequeño y el mas grande
        int div = division(source, low, high, indice_a_sortear);
        //empezar desde el mas pequeño
        quickSort(source, low, div - 1, indice_a_sortear);
        //empezar desde el mas grande
        quickSort(source, div + 1, high, indice_a_sortear);
    }
    return source;
}

//Listas doblemente ligadas
template <class T> class DList;
template <class T> class DListIterator;

//Clase con los links
template <class T>
class DLink{
    private:
        DLink(T, T, T);
        DLink(T, T, T, DLink<T>*, DLink<T>*);
        DLink(const DLink<T>&);

        //Variables de los artistas
        T artistas;
        T albumes;
        T canciones;
        //Apuntadores del valor anterior y el que sigue
        DLink<T> *previous;
        DLink<T> *next;

        friend class DList<T>;
};

//constructor base
//igualamos las variables
template <class T>
DLink<T> :: DLink(T artist, T album, T song){
    artistas = artist;
    albumes = album;
    canciones = song;
    previous = nullptr;
    next = nullptr;
}

//We create pointers and we match 
template <class T>
DLink <T> :: DLink (T artist, T album, T song, DLink<T> *prev, DLink<T> *nxt){
    artistas = artist;
    albumes = album;
    canciones = song;
    previous = prev;
    next = nxt;
}

//Constructor by copy
//We make a copy of each value
template <class T>
DLink <T> :: DLink (const DLink<T> &source){
    artistas = source.artistas;
    albumes = source.albumes;
    canciones = source.canciones;
    previous = source.previous;
    next = source.next;
}

template <class T>
class DList{
    public:
        //Constructores
        DList();
        DList(const DList<T>&);
        
        //metodos
        bool empty() const;
        void add(T, T, T);
        std::string search(const std::string &artist);

        std::vector<std::vector<T>> to_vector() const;
    private: 
        DLink<T> *head;
        DLink<T> *tail;
        int size;
};

//Constructor
template <class T>
DList<T>::DList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
    return;
}

template <class T>
DList<T>::DList(const DList<T> &source){
    //We declare the pointers
    DLink<T> *p, *q;
    //p is the new value
    //q is the previous value
    //We work with a copy of the vector
    //if it is empty we match everything with zero
    if(source.empty()){
        size = 0;
        head = nullptr;
        tail = nullptr;
        return;
    }else{
        //we match p wth the head of the list
        p = source.head;
        //the head is equal to the new value
        head = new DLink<T>(p->artistas, p->albumes, p->canciones);
        q = head;

        p = p-> next;
        while (p != nullptr){
            q -> next = new DLink<T>(p->artistas, p->albumes, p->canciones, q, nullptr);
            p = p -> next;
            q = q -> next;
        }
        tail = q;
        size = source.size;
    }
}

template <class T>
bool DList<T>::empty() const {
	return (head == nullptr && tail == nullptr);
}

template <class T>
void DList<T>::add(T artist, T album, T song){
    DLink<T> *newLink;

    newLink = new DLink<T>(artist, album, song);
    if(head == nullptr){
        head = newLink;
        tail = newLink;
    }else{
        //We create a newLink for the tale
        tail -> next = newLink;
        //The value is equal to tail now
        newLink -> previous = tail;
        //tail is equal to the new link
        tail = newLink;
    }
    size ++;
}

template <class T>
std::string DList<T>::search(const std::string &artista) {
    if (empty()) {
        return "La lista está vacía.";
    }

    DLink<T>* ptr = head;
    bool encontrado = false;
    std::string resultado;

    while (ptr != nullptr) {
        if (ptr->artistas == artista) {
            encontrado = true;
            resultado += "Artista: " + ptr->artistas + "\n";
            resultado += "Álbum: " + ptr->albumes + "\n";
            resultado += "Canción: " + ptr->canciones + "\n";
            resultado += "-----------------------------------\n";
        }
        ptr = ptr->next;
    }
    if (!encontrado){
        return "Artista no encontrado.";
    }else{
        return resultado;
    }
}

//clase para convertir a vector nuestra lista doblemente ligada
//despues la igualamos a una matriz en el main
template <class T>
std::vector<std::vector<T>> DList<T> :: to_vector() const{
    std::vector<std::vector<T>> result;
    DLink<T>* current = head;
    while (current != nullptr) {
        result.push_back({current->artistas, current->albumes, current->canciones});
        current = current->next;
    }
    return result;
}
