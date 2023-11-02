//
// Created by rashadalsharpini on 02/11/23.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include <iostream>
#include <cassert>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data) : data(data){};
    ~Node(){
        cout << "Destroy value: "<<data<<" at address "<<this<<endl;
    }
};
class LinkedList {
private:
    Node* head{};
    Node* tail{};
    int length = 0;
public:
    LinkedList(){};
    LinkedList(const LinkedList&) = delete;
    LinkedList&operator=(const LinkedList &another) = delete;
    void print1();
    void insert_end(int value);
    Node* get_nth(int n);
    int Search(int value);
    int improvedSearchV1(int value);
    int improvedSearchV2(int value); // the same as v1 the difference is the writing
    void debug_verify_data_integrity();
    string debug_to_string();
    vector<Node*> debug_data;
    void debug_add_node(Node*node);
    void debug_remove_node(Node*node);
    void debug_print_node(Node* node,bool is_seperate = false);
    void debug_print_list(string msg = "");
};


#endif //LINKEDLIST_LINKEDLIST_H
