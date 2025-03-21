#include <iostream>
#include <memory>
using namespace std;

struct Node {
    int value;
    shared_ptr<Node> next;
};

struct List {
    size_t size;
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
};

shared_ptr<Node> create_node(int n);
bool push_front(List* list, int value);
bool push_back(List* list, int value);
bool insert(List* list, int value, int n);
bool erase(List* list, int n);
void print_list(List* list);

