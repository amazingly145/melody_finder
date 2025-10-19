using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <sstream>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <locale>

//QUICK SORT

template <class T>
class Sort{
    private:
        int division(std::vector<vector<T>>&, int, int, int);
        void swap(std::vector<vector<T>>&, int, int, int);
    public:
        std::vector<vector<T>> quickSort(std::vector<vector<T>>&, int, int, int);
};

template <class T>
void Sort<T>::swap(std::vector<vector<T>> &source, int i, int j, int indice_a_sortear){
    auto aux = source[i];
    source[i] = source[j];
    source[j] = aux;
}

template <class T>
int Sort<T>::division(std::vector<vector<T>> &source, int low, int high, int indice_a_sortear){
    T pivot = source[high][indice_a_sortear];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (source[j][indice_a_sortear] < pivot) {
            i++;
            swap(source, i, j, indice_a_sortear);
        }
    }
    swap(source, i+1, high, indice_a_sortear);
    return i + 1;
}

template <class T>
vector<vector<T>> Sort<T>::quickSort(std::vector<std::vector<T>> &source, int low, int high, int indice_a_sortear){
    if(low < high){
        int div = division(source, low, high, indice_a_sortear);
        //empezar desde el mas pequeño
        quickSort(source, low, div - 1, indice_a_sortear);
        //empezar desde el mas grande
        quickSort(source, div + 1, high, indice_a_sortear);
    }
    return source;
}

//DOUBLE LINKED LIST

template <class T> class DList;
template <class T> class DListIterator;

template <class T>
class DLink{
    private:
        DLink(T, T, T);
        DLink(T, T, T, DLink<T>*, DLink<T>*);
        DLink(const DLink<T>&);

        T artistas;
        T albumes;
        T canciones;
        DLink<T> *previous; //previous value on the list
        DLink<T> *next; //next pointer value in the list

        friend class DList<T>;
};

//constructor
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
        DList();
        DList(const DList<T>&);
        
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

    if (!encontrado)
        return "Artista no encontrado.";
    else
        return resultado;
}


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
