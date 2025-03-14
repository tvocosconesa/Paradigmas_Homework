#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


void create_file(string message, string tag) {
    ofstream file("log_system.txt", ios::app);
    if (!file) { 
        cerr << "The file could not be opened" << endl;
        return; 
    }

    file << tag << '<' << message << '>' << endl;
    file.close(); 

    return;
}



void logMessage( string message, int n){
    string tag;
    switch (n){
    case 1:
        tag = "[DEBUG]";
        create_file(message, tag);

        break;
    case 2:
        tag = "[INFO]";
        create_file(message ,tag );
        break;
    case 3:
        tag = "[WARNING]";
        create_file(message, tag);
        break;

    case 4:
        tag = "[ERROR]";
        create_file(message, tag);
        break;

    case 5:
        tag = "[CRITICAL]";
        create_file(message, tag);
        break;
    
    default:
        break;
    }
}

void logMessage( string Mensage_de_Error, string Archivo, int Línea_de_Código){
    ofstream file(Archivo, ios::app);
    if (!file) { 
        cerr << "The file could not be opened" << endl;
        return; 
    }
    file  << "[ERROR] -> Line: " << Línea_de_Código << ' <' << Mensage_de_Error << '>' << endl;
    file.close(); 
}

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario){
    ofstream file("log_system.txt", ios::app);
    if (!file) { 
        cerr << "The file could not be opened" << endl;
        return; 
    }
    file  << Nombre_de_Usuario << ':' << Mensaje_De_Acceso << endl;
    file.close();
}



int main(){
    string message;
    int priority;
    cout << "Insert your message: ";
    getline(cin, message);
    cin.ignore();
    cout << "Insert your priority number: ";
    cin >> priority;
    int n = int(priority);
    
    logMessage(message, n);
    return 0;
}

