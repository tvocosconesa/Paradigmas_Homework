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
    
        shared_ptr<Node> head;
        shared_ptr<Node> tail;
};


shared_ptr<Node> create_node(int value){
    shared_ptr<Node> new_node = make_shared<Node>();
    new_node->value = value;
    return new_node;
}

void  push_front(List* list, int value){
    if (value != NULL)
    shared_ptr<Node> new_node = create_node(value);
    list -> head;
}


int main(){
    
}