#include <iostream>
using namespace std;
#include"LinkedList.h"
int main() {
    Node* node1 = new Node(6);
    Node* node2 = new Node(10);
    Node* node3 = new Node(8);
    Node* node4 = new Node(15);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;

    return 0;
}
