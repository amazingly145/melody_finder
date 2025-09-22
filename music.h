using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>

template <class T>
class Music{
    private:
        void swap(std::vector<T>&, int, int);
        int division(std::vector<T>&, int, int);
    public:
        std::vector<T> quickSort(std::vector<T>&, int, int);
};

template <class T>
void Music<T>::swap(std::vector<T> &source, int i, int j){
    T aux = source[i];
    source[i] = source[j];
    source[j] = aux;
}

template <class T>
int Music<T>::division(std::vector<T> &source, int low, int high){
    T pivot = source[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (source[j] < pivot) {
            i++;
            swap(source, i, j);
        }
    }
    swap(source, i+1, high);
    return i + 1;
}

template <class T>
std::vector<T> Music<T>::quickSort(std::vector<T> &source, int low, int high){
    if(low < high){
        int div = division(source, low, high);
        quickSort(source, low, div - 1);
        quickSort(source, div + 1, high);
    }
    return source;
}