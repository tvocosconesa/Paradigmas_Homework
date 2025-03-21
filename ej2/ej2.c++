#include "ej2.h"


void create_message(string message, string tag) {
    ofstream file("log_system.txt", ios::app);  
    if (!file) { 
        cerr << "The file could not be opened" << endl;
        return; 
    }

    file << tag << '<' << message << '>' << endl;         // ingreso el mensaje con su respectiva prioridad en el txt
    file.close(); 

    return;
}



void logMessage(string message, int n){ // selecciono un tag correspondiente a una prioridad para mandar a create message
    string tag;
    switch (n){
        case 1: tag = "[DEBUG]"; break;
        case 2: tag = "[INFO]"; break;
        case 3: tag = "[WARNING]"; break;
        case 4: tag = "[ERROR]"; break;
        case 5: tag = "[CRITICAL]"; break;
        default: tag = "[UNKNOWN]"; break;
    }
    create_message(message, tag);
}

void logMessage( string Mensage_de_Error, string Archivo, int Línea_de_Código){
    ofstream file("log_system.txt", ios::app);
    if (!file) { 
        cerr << "The file could not be opened" << endl;
        return; 
    }
    file  << "[ERROR] -> file: " << Archivo << " / Line: " << Línea_de_Código << " <" << Mensage_de_Error << '>' << endl;   // reporto el error
    file.close(); 

}

void logMessage(string Mensaje_De_Acceso, string Nombre_de_Usuario){
    ofstream file("log_system.txt", ios::app);
    if (!file) { 
        cerr << "The file could not be opened" << endl;
        return; 
    }

    file  << "[SECURITY] " << Nombre_de_Usuario << ": " << Mensaje_De_Acceso << endl;   // Pongo en el el archivo si el acceso fue otorgado o no
    file.close();
}



int main(){
    int action; 
    cout <<  "Insert your desired aciton:  \n 1) Send a message / report information \n 2) log-In in the system \n --> ";
    cin >> action;      // se elije una accion 
    cin.ignore();
    if (action == 1){   
        try {
            string message;
            int priority;
            
            cout << "Priority number Menu: \n 1) [DEBUG] \n 2) [INFO] \n 3) [WARNING] \n 4) [ERROR] \n 5) [CRITICAL] \n 6) [UNKNOWN] \n Insert your priority number ------> ";
    
            cin >> priority;
            cin.ignore();

            if (priority < 1 || priority > 5) { // si l aprioridad enviada no corresponde con las del menu se tira un runtime error
                throw runtime_error("Invalid priority number");
                return 1 ;
            }

            if (priority == 4){ // si la prioridad es cuatro se reporta el error a la funcion logmessage de errores
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
        } catch (const exception& e) { // si la prioridad insertada no figura se tira un runtime error 
            logMessage(e.what(), 4);  
            cerr << "Runtime error: " << e.what() << endl;
            return 1;  
        }
    }
    else{       // si se elije la opcion 2 (login) se le pide al usuario que meta su username 
        string user;
        string message;
        cout << "insert Your username: ";
        getline(cin,user);

        if (user == "Bjarne Stroustrup"){
            message = "Access Granted";
        }
        else{
            message = "Access Denied";
        }

        logMessage(message,user);
    }
}
