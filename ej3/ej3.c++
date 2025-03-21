#include "ej3.h"

shared_ptr<Node> create_node(int n){
    shared_ptr<Node> new_node = make_shared<Node>();
    if (!new_node) return NULL;
    new_node->value = n;
    return new_node;
}

bool push_front(List* list, int value){
    if (!list) return false;
        shared_ptr<Node> new_node = create_node(value);
        if (new_node == NULL) return false;

        new_node ->next = list-> head;
        list ->head = new_node;
        if (!list ->head){
            list -> tail = new_node;

        }    
    list ->size ++;
    return true;
}

bool push_back(List* list, int value){
    if (!list) return false;

    shared_ptr<Node> new_node = create_node(value);
    if (new_node == NULL) return false;

    if (list->tail) {
        list->tail->next = new_node; // Inserto el nodo luego del tail
    } else {
    
        list->head = new_node;         // en el caso de que la lista este vacia le le doy el rol de head al nodo al insertarlo
    }
    list->tail = new_node;          // reasigno el rol de tail 
    list ->size++;
    return true;
}


bool insert(List* list, int value, int n) {
    if (!list) return false; 

    if (n == 0) {                // si las posicion es 0 llamo a push_front para insertar el elemento en el head
        push_front(list, value);
        return true;
    }
    
    if (n > list-> size){        // Si el numero de posicion es mas grande que la lista inserto el elemento al final 
        cout << "Index inserted is larger than the list´s size -> proceeding to insert at the back of the list \n";
        push_back(list,value);  // uso push back para insertarlo al final
        return true;
    }
    shared_ptr<Node> new_node = create_node(value);  // creo el nodo
    if (new_node == NULL) return false; 

    shared_ptr<Node> curr = list->head;           // creo un auxiliar
    int i = 0;
    while (i < n - 1 && curr != NULL) {           // recorro la lista hasta llegar a la posicion anterior a la deseada
        curr = curr->next;
        i++;
    }
    if (curr == NULL) return false;

    new_node->next = curr->next;         // inserto el nodo en la posicion y acomodo sus punteros
    curr->next = new_node;
    list ->size++;
    return true;
}

bool erase(List* list , int n){
     if (!list)return false; 

     shared_ptr<Node> curr = list->head;    // creo un auxiliar
     int i = 0;
    
     if(n == 0){
        list ->head = curr ->next;
        curr = nullptr;
        return true;
     }

     if(n >= list->size){                   // si el indice insertado es mas grande que la lista borro el ultimo elemento
        cout << "The inserted index is larger than the list's size -> proceeding to delete the last item \n";
        while (i < list->size-2){
            curr = curr -> next;
            i++;
        }
        curr ->next = nullptr;
        list ->tail = curr;

        return true;

     }
     while (i < n-1){                        // recorro la lista 
        curr = curr ->next;

        i++;
     }
     shared_ptr<Node> aux = curr ->next ->next;     // borro el elemento y reacomodo los punteros
     curr -> next = nullptr;
     curr ->next = aux;
     return true;
}


void print_list (List* list){
    shared_ptr<Node> curr = list -> head;
    while (curr ->next != NULL){               // recorro los elementos de la lista e imprimo sus valores
        
        cout << " [" << curr ->value << "] ->" ;
        curr = curr ->next;
    }
    cout << " [" << list -> tail ->value << "] ->";
    cout<< " Null \n";
    
}



int main(){
    List myList;
    myList.size = 0;
    myList.head = nullptr;
    myList.tail = nullptr;

    push_back(&myList, 10);
    print_list(&myList);
    push_front(&myList, 20);
    print_list(&myList);
    push_back(&myList, 30);
    print_list(&myList);

    cout << "List after inserting 10, 20, 30:" << endl;
    print_list(&myList);
    cout << endl;

    erase(&myList, 3);
    cout << "List after erasing index 3:" << endl;
    print_list(&myList);
    cout << endl;

    push_front(&myList, 5);
    cout << "List after pushing 5 to the front:" << endl;
    print_list(&myList);
    cout << endl;

    erase(&myList, 0);
    cout << "List after erasing index 0:" << endl;
    print_list(&myList);
    cout << endl;
    return 0;
}

