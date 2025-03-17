#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
using namespace std;

typedef struct Node{
    
        int value;
        shared_ptr<Node> next;
};

typedef struct List{
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
    if (value == NULL || !list) return false;
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
    if (value == NULL || !list) return false;

    shared_ptr<Node> new_node = create_node(value);
    if (new_node == NULL) return false;

    list -> tail -> next = new_node;
    new_node -> next = NULL;

    if (!list ->tail){
        list ->head = new_node;
    }
    list ->size++;
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


int main(){
    
}

