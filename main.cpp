using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#define DATA_SET "dataset_2.csv"
#include "music.h"
#include <fstream>

void menu(){
    cout << "-----Funciones de ordenamiento------" << endl;
    cout << "1. Ordenar alafabeticamente los artistas" << endl;
    cout << "2. Ordenar alfabeticamente las canciones" << endl;
    cout << "3. Ordenar alfabeticamente los albumes" << endl;
    cout << "4. Salida" << endl;
}

int main(){   
    //Variables
    int usuario;
    bool consultante = true;
    Music<string> ordered_music;
    vector<string> artistas; //vector
    vector<string> artistas_para_ordenar; //vector
    vector<string> canciones;
    vector<string> canciones_para_ordenar;
    vector<string> album;
    vector<string> album_para_ordenar;
    //dataset upload
    ifstream music_dataset(DATA_SET);
    string linea;
    char delimitador = ',';
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
        //We save artists in the vector "artistas"
        artistas.push_back(artists);
        artistas_para_ordenar.push_back(artists);
        album.push_back(album_name);
        album_para_ordenar.push_back(album_name);
        canciones.push_back(track_name);
        canciones_para_ordenar.push_back(track_name);
    }
    cout << "-----Bienvenido al sistema de musica-----" << endl;
    while(consultante == true){
        menu();
        cout << "Selecciona la opcion que deseas usar: "<< endl;
        cin >> usuario;
        if(usuario == 1){
            cout << "------Ordenar artistas por orden alfabetico-----" << endl;
            for(int i = 0; i < artistas.size(); i++){
                artistas_para_ordenar[i] = artistas[i] + "\ncancion: " + canciones[i] + "\nalbum: " + album[i];
            }
            ordered_music.quickSort(artistas_para_ordenar, 0, artistas_para_ordenar.size() - 1);
            for (int i = 0; i < artistas_para_ordenar.size(); i++){
                cout << "Artista: " << artistas_para_ordenar[i] <<endl;
                cout << "----------------------------------" << endl;}
            }
        if(usuario == 2){
            cout << "------Ordenar canciones por orden alfabetico-----" << endl;
            for(int i = 0; i < canciones.size(); i++){
                canciones_para_ordenar[i] = canciones[i] + "\nartista: " + artistas[i] + "\nalbum: " + album[i];
            }
            ordered_music.quickSort(canciones_para_ordenar, 0, canciones_para_ordenar.size() - 1);
            for (int i = 0; i < canciones_para_ordenar.size(); i++){
                cout << "Cancion: " << canciones_para_ordenar[i] <<endl;
                cout << "----------------------------------" << endl;}
            }
        if(usuario == 3){
            cout << "------Ordenar album por orden alfabetico-----" << endl;
            for(int i = 0; i < artistas.size(); i++){
                album_para_ordenar[i] = album[i] + "\ncancion: " + canciones[i] + "\nartista: " + artistas[i];
            }
            ordered_music.quickSort(album_para_ordenar, 0, album_para_ordenar.size() - 1);
            for (int i = 0; i < album_para_ordenar.size(); i++){
                cout << "Album: " << album_para_ordenar[i] <<endl;
                cout << "----------------------------------" << endl;
            }
        }
        if(usuario == 4){
            cout << "Saliendo del programa" << endl;
            consultante = false;
        }
    }
}