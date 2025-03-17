#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
using namespace std;

struct Node{
    
        int value;
        shared_ptr<Node> next;
};

struct List{
        size_t  size;
        shared_ptr<Node> head;
        shared_ptr<Node> tail;
};


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
        list->tail->next = new_node;
    } else {
    
        list->head = new_node;
    }
    list->tail = new_node;
    return true;
}


bool insert(List* list, int value, int n) {
    if (!list) return false; 

    shared_ptr<Node> new_node = create_node(value);
    if (new_node == NULL) return false; 

    if (n == 0) {
        new_node->next = list->head;
        list->head = new_node;
        return true;
    }
    
    if (n > list-> size){
        cout << "Index inserted is larger than the list´s size -> proceeding to insert at the back of the list";
        push_back(list,value);
        return true;
    }

    shared_ptr<Node> current = list->head;
    int i = 0;
    while (i < n - 1 && current != NULL) {
        current = current->next;
        i++;
    }
    if (current == NULL) return false;

    new_node->next = current->next;
    current->next = new_node;

    return true;
}

bool erase(List* list , int n){
     if (!list)return false; 

     shared_ptr<Node> curr = list->head;
     int i = 0;
    
     if(n == 0){
        list ->head = curr ->next;
        curr = nullptr;
        return true;
     }

     if(n >= list->size){        
        cout << "The inserted index is larger than the list's size -> proceeding to delete the last item";
        while (i < list->size-2){
            curr = curr -> next;
            i++;
        }
        curr ->next = nullptr;
        list ->tail = curr;

        return true;

     }
     while (i < n-1){
        curr = curr ->next;

        i++;
     }
     shared_ptr<Node> aux = curr ->next ->next;
     curr -> next = nullptr;
     curr ->next = aux;
     return true;
}


void print_list (List* list){
    shared_ptr<Node> curr = list -> head;
    while (curr ->next != NULL){
        
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
    push_back(&myList, 20);
    print_list(&myList);
    push_back(&myList, 30);
    print_list(&myList);

    // cout << "List after inserting 10, 20, 30:" << endl;
    // print_list(&myList);
    // cout << endl;

    // erase(&myList, 1);
    // cout << "List after erasing index 1:" << endl;
    // print_list(&myList);
    // cout << endl;

    // push_front(&myList, 5);
    // cout << "List after pushing 5 to the front:" << endl;
    // print_list(&myList);
    // cout << endl;

    // erase(&myList, 0);
    // cout << "List after erasing index 0:" << endl;
    // print_list(&myList);
    // cout << endl;
}

