/* 
 * Autor: Andrea Iliana Cantu Mayorga 
 * Matricula: A01753419
 * Fecha: 3 de diciembre del 2025
 * Materia: programacion de estructura de datos y algoritmos*/
using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define DATA_SET "dataset_2.csv"
#include "music.h"
#include <fstream>

/*guardar CSV
Funcion para que despues de agregar nuevos artistas
se puedan guardar en el CSV*/
void guardarCSV(vector<vector<string>> matriz) {
    //Abrimos el archivo .csv
    ofstream archivo(DATA_SET);
    //Nombres de los encabezados que vamos a guardar los artistas
    archivo << "artists,album_name,track_name\n";
    //Obtenemos las filas de la matriz
    for (int i = 0; i < matriz.size(); i++) {
        archivo << matriz[i][0] << "," 
        << matriz[i][1] << "," 
        << matriz[i][2] << "\n";
    }
}

/*Funcion de menu
 * El menu de opciones que el usuaario tiene 
 * para hacerle modificaciones al archivo*/
void menu(){
    cout << "-----Menu------" << endl;
    //Funciones con double list
    cout << "1. Agregar nuevos artistas" << endl;
    cout << "2. Buscar artista" << endl; //Poner cuantas veces se repite
    //Funciones de ordenamiento
    cout << "3. Ordenar alafabeticamente los artistas" << endl;
    cout << "4. Ordenar alfabeticamente las canciones" << endl;
    cout << "5. Ordenar alfabeticamente los albumes" << endl;
    cout << "6. Visualizar base de datos" << endl;
    cout << "7. Salida" << endl;
}

int main(){   
    //Variables
    int usuario;
    bool consultante = true;
    string artistas;
    string cancion;
    string album;
    int agregar;
    //Creamos la matriz de musica con todos los datos
    vector<vector<string>> matriz_musica;
    //Variables para subir el .csv al programa
    ifstream music_dataset(DATA_SET);
    string linea;
    string valores;
    char delimitador = ',';
    //Funcion para hacer el Quick Sort
    Sort<string>ordered_music;
    //Para la lista doblemente ligada
    DList<string> double_list_music;
    //leemos la primer linea
    getline(music_dataset, linea);
    //leemos todas las columnas de nuestro archivo
    while (getline(music_dataset, linea)){
        stringstream stream(linea);
        string artists, album_name, track_name;
        getline(stream, artists, delimitador);
        getline(stream, album_name, delimitador);
        getline(stream, track_name, delimitador);
        //matriz principal que se a utilizrar principalmente para el sorteo
        matriz_musica.push_back({artists, album_name, track_name});
        //agregamos los valores a la lista doblemente ligada 
        double_list_music.add(artists, album_name, track_name);
    }
    cout << "-----Bienvenido a Melody Finder-----" << endl;
    while(consultante == true){
        menu();
        cout << "Selecciona la opcion que deseas usar: "<< endl;
        cin >> usuario;
        if(usuario == 1){
            cout << "------ Agregar nuevos elementos ------" << endl;
            cout << "Numero de artistas a agregar: " << endl;
            cin >> agregar;
            while (agregar > 0){
                cin.ignore();
                cout << "Escribir el nombre del albumm, artista y cancion la primer letra en mayuscula" << endl;
                cout << "Si tiene dos nombres escribir sin espacios" << endl;
                cout << "Nombre de artista nuevo: " << endl;
                getline(cin, artistas);
                cout << "Nombre de album de " << artistas << endl;
                getline(cin, album);
                cout << "Nombre de cancion en album " << album << " Con artista " << artistas << endl;
                getline(cin, cancion);
                double_list_music.add(artistas, album, cancion);
                matriz_musica = double_list_music.to_vector();
                guardarCSV(matriz_musica);
                agregar--;
                cout << "Artista agregado correctamente..." << endl;
            }
        }
        if(usuario == 2){
            cout << "------Funcion de busqueda------" << endl;
            cout << "Nombre de artista a buscar: " << endl;
            cin.ignore();
            getline(cin,artistas);
            cout << double_list_music.search(artistas) << endl;
            cout << "------------------------------" << endl;
        }
        if(usuario == 3){
            cout << "------Ordenar artistas por orden alfabetico-----" << endl;
            ordered_music.quickSort(matriz_musica, 0, matriz_musica.size() - 1, 0);
            for (int i = 0; i < matriz_musica.size(); i++){
                cout << "Artista: " << matriz_musica[i][0] << endl;
                cout << "Cancion: " << matriz_musica[i][1] << endl;
                cout << "Album: " << matriz_musica[i][2] << endl;
                cout << "---------------------------------------------" << endl;
            }
        }
        if(usuario == 4){
            cout << "------Ordenar por orden alfabetico las canciones------"<< endl;
            ordered_music.quickSort(matriz_musica, 0, matriz_musica.size() - 1, 2);
            for (int i = 0; i < matriz_musica.size(); i++){
                cout << "Cancion: " << matriz_musica[i][2] << endl;
                cout << "Artista: " << matriz_musica[i][0] << endl;
                cout << "Album: " << matriz_musica[i][1] << endl;
                cout << "---------------------------------------------" << endl;
            }
        }
        if (usuario == 5){
            cout << "------Ordenar por orden alfabetico los albumes------"<< endl;
            ordered_music.quickSort(matriz_musica, 0, matriz_musica.size()-1, 1);
            for (int i = 0; i < matriz_musica.size(); i++){
                cout << "Album: " << matriz_musica[i][1] << endl;
                cout << "Artista: " << matriz_musica[i][0] << endl;
                cout << "Cancion: " << matriz_musica[i][2] << endl;
                cout << "---------------------------------------------" << endl;
            }
        }
        if(usuario == 6){
            cout << "-----Visualizar la base de datos desordenada-----" << endl;
            for(int i = 0; i < matriz_musica.size(); i++){
                cout << "Album: " << matriz_musica[i][1] << endl;
                cout << "Artista: " << matriz_musica[i][0] << endl;
                cout << "Cancion: " << matriz_musica[i][2] << endl;
                cout << "---------------------------------------------" << endl;
            }
        }
        if(usuario == 7){
            cout << "Saliendo del programa..." << endl;
            consultante = false;
        }
    }
}