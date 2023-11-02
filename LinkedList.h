//
// Created by rashadalsharpini on 02/11/23.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data) : data(data){};
};
class LinkedList {
private:
    Node* head{};
    Node* tail{};
    int length = 0;
public:
    void print1();
    void insert_end(int value);
    Node* get_nth(int n);
    int Search(int value);
    int improvedSearchV1(int value);
    int improvedSearchV2(int value); // the same as v1 the difference is the writing
};


#endif //LINKEDLIST_LINKEDLIST_H
