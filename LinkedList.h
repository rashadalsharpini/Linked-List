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
#include <climits>
using namespace std;
struct Node{
    int data{};
    Node* next{};
    Node* prev{};
    Node(int data) : data(data){};
    ~Node(){
        cout << "Destroy value: "<<data<<" at address "<<this<<endl;
    }
    void set(Node*next,Node*prev){
        this->next=next;
        this->prev=prev;
    }
};
class LinkedList {
private:
    Node* head{};
    Node* tail{};
    int length = 0;
public:
    vector<Node*> debug_data;
    LinkedList(){};
    LinkedList(const LinkedList&) = delete;
    LinkedList&operator=(const LinkedList &another) = delete;
    ~LinkedList();
    void printlength(){
        cout<<length<<endl;
    }
    void link(Node*first,Node*second);
    void print1();
    void print_reverse();
    void insert_end(int value);
    void insert_front(int value);
    Node* get_nth(int n);
    int Search(int value);
    int improvedSearchV1(int value);
    int improvedSearchV2(int value); // the same as v1 the difference is the writing
    Node* get_nth_back(int n);
    void debug_verify_data_integrity();
    string debug_to_string();
    void debug_add_node(Node*node);
    void debug_remove_node(Node*node);
    void debug_print_node(Node* node,bool is_seperate = false);
    void debug_print_list(string msg = "");
    bool is_same1(const LinkedList&other);
    bool is_same(const LinkedList&other);
    void add_element(int value);
    void delete_front();
    void delete_first();
    void delete_end();
    void delete_nth(int index);
    void delete_value(int value);
    void delete_node(Node*node);
    void swap_pair();
    void reverse_nodes();
    void insert_sorted(int value);
    void embed_after(Node*node,int value);
    void swap_head_tail();
    void left_rotate(int k);
    void remove_duplicates_from_not_sorted();
    void delete_last_occurence(int target);
    void delete_next_node(Node* node);
    void move_key_occurance_to_end(int key);
    Node* move_to_end(Node* cur, Node* prv);
    int max(Node*head= nullptr,bool is_first_call=true);
    void odd_pos_even_pos();
    void insert_alternate(LinkedList&another);
    void insert_after(Node*src,Node*target);
    Node* delete_and_link(Node*cur);
    void delete_node_with_key(int value);
};


#endif //LINKEDLIST_LINKEDLIST_H
