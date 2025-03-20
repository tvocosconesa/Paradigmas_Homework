#include <iostream>
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



void logMessage(string message, int n){
    string tag;
    switch (n){
        case 1: tag = "[DEBUG]"; break;
        case 2: tag = "[INFO]"; break;
        case 3: tag = "[WARNING]"; break;
        case 4: tag = "[ERROR]"; break;
        case 5: tag = "[CRITICAL]"; break;
        default: tag = "[UNKNOWN]"; break;
    }
    create_file(message, tag);
}

void logMessage( string Mensage_de_Error, string Archivo, int Línea_de_Código){
    ofstream file("log_system.txt", ios::app);
    if (!file) { 
        cerr << "The file could not be opened" << endl;
        return; 
    }
    file  << "[ERROR] -> file: " << Archivo << " / Line: " << Línea_de_Código << " <" << Mensage_de_Error << '>' << endl;
    file.close(); 

}

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario){
    ofstream file("log_system.txt", ios::app);
    if (!file) { 
        cerr << "The file could not be opened" << endl;
        return; 
    }

    file  << Nombre_de_Usuario << ": " << Mensaje_De_Acceso << endl;
    file.close();
}



int main(){
    int action; 
    cout <<  "Insert your desired aciton:  \n 1) Send a message / report information \n 2) log-In in the system \n --> ";
    cin >> action;
    cin.ignore();
    if (action == 1){    
        try {
            string message;
            int priority;
            
            cout << "Insert your priority number: ";
    
            cin >> priority;
            cin.ignore();

            if (priority < 1 || priority > 5) {
                throw runtime_error("Invalid priority number");
            }

            if (priority == 4){
                cin.ignore();
                string file_name;
                int line;

                cout << "Insert ERROR description: ";
                getline(cin,message);
                

                cout << "Insert file name: ";
                getline(cin, file_name);
            
                cout << "Insert line were the error is present: ";
                cin >> line;
                cin.ignore();

                logMessage(message, file_name, line);
            }
            else{
            cout << "Insert your message: ";
            getline(cin, message);

            logMessage(message, priority);
            }
        } catch (const exception& e) {
            logMessage(e.what(), 4);  // Se guarda en el log como ERROR
            cerr << "Runtime error: " << e.what() << endl;
            return 1;  // Se detiene el programa con código de error
        }
    }
    else{
        string user;
        string message;
        cout << "insert Your username: ";
        getline(cin,user);
        // cout << "Message: ";
        // getline(cin, message);

        if (user == "Bjarne Stroustrup"){
            message = "Access Granted";
        }

        logMessage(message,user);
    }
}

