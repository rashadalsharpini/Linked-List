//
// Created by rashadalsharpini on 02/11/23.
//
// ninja: no work to do.

#include "LinkedList.h"
LinkedList::~LinkedList() {
    while(head){
        Node*current = head->next;
        delete head;
        head=current;
    }
}

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
    length++;
}
void LinkedList::insert_front(int value) {
    Node* item = new Node(value);
//    add_node(item);
    if(!head)
        head = tail = item;
    else{
        item->next = head;
        head = item;
    }
//    debug_verify_data_integrity();
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
void LinkedList::debug_verify_data_integrity() {
    if(length == 0){
        assert(head == nullptr);
        assert(tail == nullptr);
    }else{
        assert(head != nullptr);
        assert(tail != nullptr);
        if(length==1)
            assert(head == tail);
        else
            assert(head!=tail);
        assert(!tail->next);
    }
    int len = 0;
    for(Node* cur=head;cur;cur=cur->next)
        assert(len<10000);
    assert(length==len);
    assert(length==(int)debug_data.size());

}

string LinkedList::debug_to_string() {
        if(length==0)
            return "";
        ostringstream oss;
        for(Node*cur=head;cur;cur=cur->next){
            oss<<cur->data;
            if(cur->next)
                oss<<"";
        }
        return oss.str();
}

void LinkedList::debug_add_node(Node *node) {
    debug_data.push_back(node);
}

void LinkedList::debug_remove_node(Node *node) {
    auto it = std::find(debug_data.begin(),debug_data.end(),node);
    if(it==debug_data.end())
        cout<<"Node does not exist"<<endl;
    else
        debug_data.erase(it);
}
void LinkedList::debug_print_node(Node *node, bool is_seperate) {
    if(is_seperate)
        cout<<"sep:";
    if(node== nullptr){
        cout<<"nullptr"<<endl;
        return;
    }
    cout<<node->data<<" ";
    if(node->next == nullptr)
        cout<<"X";
    else
        cout<<node->next->data<<" ";
    if(node == head)
        cout<<"head"<<endl;
    else if(node == tail)
        cout<<"tail"<<endl;
    else
        cout<<endl;
}
void LinkedList::debug_print_list(string msg) {
    if(msg !="")
        cout<<msg<<endl;
     for(int i=0;i<(int)debug_data.size();i++)
        debug_print_node(debug_data[i]);
    cout<<"************************\n"<<flush;
}

void LinkedList::delete_front() {
    assert(length);
    Node*cur=head->next;
//    delete_node(head);
    head=cur;
    debug_verify_data_integrity();
}
Node* LinkedList::get_nth_back(int n) {
    if(length<n)
        return nullptr;
    return get_nth(length - n + 1);
}
bool LinkedList::is_same1(const LinkedList &other) {
    Node*h1=head,*h2=other.head;
    while(h1&&h2){
        if(h1->data!=h2->data)
            return false;
        h1=h1->next,h2=h2->next;
    }
    return !h1 && !h2;
}
bool LinkedList::is_same(const LinkedList &other) {
    if(length != other.length)
        return false;
    Node*other_h=other.head;
    for(Node*cur_h=head;cur_h;cur_h=cur_h->next){
        if(cur_h->data!=other_h->data)
            return false;
        other_h=other_h->next;
    }
    return true;
}
void LinkedList::add_element(int value) {
    Node*item = new Node(value);
    item->next=head;
    head=item;
}

