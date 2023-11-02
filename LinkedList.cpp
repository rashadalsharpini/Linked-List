//
// Created by rashadalsharpini on 02/11/23.
//

#include "LinkedList.h"
void LinkedList::print1() {
    Node* temp_head = head;
    while(temp_head != nullptr){
        cout<<temp_head->data<<" ";
        temp_head = temp_head->next;
    }
    cout<<endl;
//    for(Node*cur=head;cur!=nullptr;cur->next){
//        cout<<cur->data<<" ";
//    }
//    cout<<endl;
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
