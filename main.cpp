using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define DATA_SET "dataset_2.csv"
#include "music.h"
#include <fstream>

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
    //Creamos la matriz de musica con todos los datos
    vector<vector<string>> matriz_musica;
    //dataset upload
    ifstream music_dataset(DATA_SET);
    string linea;
    string valores;
    char delimitador = ',';
    //QUICK SORT
    Sort<string>ordered_music;
    //DOUBLE LINKED LIST
    DList<string> double_list_music;
    vector<string> vector_temporal;
    //we read the first line
    getline(music_dataset, linea);
    //We read all the lines
    while (getline(music_dataset, linea)){
        stringstream stream(linea);
        string id, track_id, artists, album_name, track_name, popularity, duration_ms,
            explicit_1, danceability, energy, key, loudness, mode, speechiness,
            acousticness, instrumentalness, liveness, valence, tempo,
            time_signature, track_genre;
        getline(stream, id, delimitador);
        getline(stream, track_id, delimitador);
        getline(stream, artists, delimitador);
        getline(stream, album_name, delimitador);
        getline(stream, track_name, delimitador);
        //matriz
        matriz_musica.push_back({artists, album_name, track_name});
        //Listas doblemente ligadas
        double_list_music.add(artists, album_name, track_name);
    }
    cout << "-----Bienvenido al sistema de musica-----" << endl;
    while(consultante == true){
        menu();
        cout << "Selecciona la opcion que deseas usar: "<< endl;
        cin >> usuario;
        if(usuario == 1){
            cout << "------ Agregar nuevos elementos ------" << endl;
            cout << "Escribir el nombre del albumm, artista y canncion la primer letra en mayuscula" << endl;
            cout << "Nombre de artista nuevo: " << endl;
            cin >> artistas;
            cout << "Nombre de album de " << artistas << endl;
            cin >> album;
            cout << "Nombre de cancion en album " << album << " Con artista " << artistas << endl;
            cin >> cancion;
            double_list_music.add(artistas, album, cancion);
            matriz_musica = double_list_music.to_vector();

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