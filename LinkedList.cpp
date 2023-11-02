//
// Created by rashadalsharpini on 02/11/23.
//

#include "LinkedList.h"
void LinkedList::print1() {
    for(Node*cur=head;cur;cur = cur->next){
        cout<<cur->data<<" ";
    }
    cout<<endl;
}
void LinkedList::insert_end(int value) {
    Node* item = new Node(value);
    if(!head)
        head = tail = item;
    else{
        tail->next = item;
        tail = item;
    }
}
Node* LinkedList::get_nth(int n) {
    int cnt = 0;
    for(Node*cur = head;cur;cur = cur->next)
        if(++cnt == n)
            return cur;

    return nullptr;
}
int LinkedList::Search(int value) {
    int index = 0;
    for(Node* cur =head;cur;cur=cur->next,index++)
        if(cur->data==value)
            return index;
    return -1;
}
int LinkedList::improvedSearchV1(int value) {
    int index = 0;
    Node* previous = nullptr;
    for(Node* cur =head;cur;cur=cur->next,index++) {
        if (cur->data == value) {
            if(!previous)
                return index;
            swap(previous->data,cur->data);
            return index-1;
        }
        previous = cur;
    }
    return -1;
}
int LinkedList::improvedSearchV2(int value) {
    int index = 0;
    for(Node*cur = head,*prv=nullptr;cur;prv=cur,cur = cur->next){
        if(cur->data==value){
            if(!prv)
                return index;
            swap(prv->data,cur->data);
            return index-1;
        }
        ++index;
    }
    return -1;
}
