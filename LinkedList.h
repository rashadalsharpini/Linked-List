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
template <typename T>
struct Node{
    T data{};
    Node* next{};
    Node* prev{};
    Node(T data) : data(data){};
    ~Node(){
        cout << "Destroy value: "<<data<<" at address "<<this<<endl;
    }
    void set(Node*next,Node*prev){
        this->next=next;
        this->prev=prev;
    }
};
template <typename T>
class LinkedList {
private:
    Node<T>* head{};
    Node<T>* tail{};
    int length = 0;
public:
    vector<Node<T>*> debug_data;
    LinkedList(){};
    LinkedList(const LinkedList&) = delete;
    LinkedList&operator=(const LinkedList &another) = delete;
    ~LinkedList();
    void printlength(){
        cout<<length<<endl;
    }
    void link(Node<T>*first,Node<T>*second);
    void print();
    void print_reverse();
    void insert_end(T value);
    void insert_front(T value);
    Node<T>* get_nth(int n);
    int Search(T value);
    int improvedSearchV1(T value);
    int improvedSearchV2(T value); // the same as v1 the difference is the writing
    Node<T>* get_nth_back(int n);
    void debug_verify_data_integrity();
    string debug_to_string();
    void debug_add_node(Node<T>*node);
    void debug_remove_node(Node<T>*node);
    void debug_print_node(Node<T>* node,bool is_seperate = false);
    void debug_print_list(string msg = "");
    bool is_same1(const LinkedList&other);
    bool is_same(const LinkedList&other);
    void add_element(T value);
    void delete_front();
    void delete_first();
    void delete_end();
    void delete_nth(int index);
    void delete_value(T value);
    void delete_node(Node<T>*node);
    void swap_pair();
    void reverse_nodes();
    void insert_sorted(T value);
    void embed_after(Node<T>*node,T value);
    void swap_head_tail();
    void left_rotate(int k);
    void remove_duplicates_from_not_sorted();
    void delete_last_occurence(int target);
    void delete_next_node(Node<T>* node);
    void move_key_occurance_to_end(int key);
    Node<T>* move_to_end(Node<T>* cur, Node<T>* prv);
    int max(Node<T>*head= nullptr,bool is_first_call=true);
    void odd_pos_even_pos();
    void insert_alternate(LinkedList&another);
    void insert_after(Node<T>*src,Node<T>*target);
    Node<T>* delete_and_link(Node<T>*cur);
    void delete_node_with_key(T value);
};


#endif //LINKEDLIST_LINKEDLIST_H
