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
void LinkedList::print_reverse() {
    for(Node*cur=tail;cur;cur=cur->prev)
        cout<<cur->data<<" ";
    cout<<endl;
}
void LinkedList::link(Node *first, Node *second) {
    if(first)
        first->next=second;
    if(second)
        second->prev=first;
}
void LinkedList::insert_end(int value) {
    Node* item = new Node(value);
    debug_add_node(item);
    if(!head)
        head = tail = item;
    else{
        link(tail,item);
//        tail->next = item;
        tail = item;
    }
    length++;
}
void LinkedList::insert_front(int value) {
    Node* item = new Node(value);

    if(!head)
        head = tail = item;
    else{
        link(item,head);
//        item->next = head;
        head = item;
    }
    debug_add_node(item);
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
    // calling it after doing any operation
    // to make sure that our list isn't corrupted
    if (length == 0)
        assert(head == nullptr && tail == nullptr);

    if (length) {
        assert(head != nullptr && tail != nullptr);
        assert(!tail->next);
    }

    if (length == 1)
        assert(head == tail);


    int cur_length = 0;
    for (Node* cur = head; cur; cur = cur->next, cur_length++)
        assert(cur_length < 10000); // handling infinite cycle

    assert(cur_length == length);
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
void LinkedList::delete_node(Node *node) {
    debug_remove_node(node);
    --length;
    delete node;
}
void LinkedList::delete_front() {
    if(!head)
        return;
    Node*cur=head->next;
    delete_node(head);
    head=cur;
    if(head)
        head->prev= nullptr;
    else if(!length)
        tail= nullptr;
    debug_verify_data_integrity();
}
void LinkedList::delete_first() {
    if(head){
        Node* cur=head;
        head=head->next;
        delete_node(cur);
        if(!head)
            tail= nullptr;
        debug_verify_data_integrity();
    }
}

void LinkedList::delete_end() {
    if(!head)
        return;
    Node*cur = tail->prev;
    delete_node(tail);
    tail=cur;
    if(tail)
        tail->next = nullptr;
    else if(!length)
        head = nullptr;
    debug_verify_data_integrity();
}
void LinkedList::delete_nth(int index) {
    if(index<1||index>length)
        cout<<"Error. No such nth node\n";
    else if(index==1)
        delete_first();
    else{
        Node*before= get_nth(index-1);
        Node*nth=before->next;
        bool is_tail=nth==tail;
        if(nth!= nullptr){
            before->next=nth->next;
            if(nth->next!= nullptr)
                nth->next->prev=before;
            if(is_tail)
                tail=before;
        }
//        before->next=nth->next;
//        if(is_tail)
//            tail=before;
        delete_node(nth);
        debug_verify_data_integrity();
    }
}
void LinkedList::delete_value(int value) {
    int cnt = 0;
    for(Node*cur=head;cur;cur=cur->next){
        cnt++;
        if(cur->data==value)
            break;

    }
    delete_nth(cnt);
}
void LinkedList::swap_pair() {
    for(Node*cur=head;cur;cur=cur->next){
        if(cur->next) {
            swap(cur->data, cur->next->data);
            // I forgot about the two steps move because I supposed to swap each pair
            cur=cur->next;
        }
    }
}
void LinkedList::reverse_nodes() {
    if(length<=1)
        return;
    tail=head;
    Node*prv=head;
    head=head->next;
    while(head){
        Node*next=head->next;
        head->next=prv;
        prv=head;
        head=next;
    }
    head=prv;
    tail->next=nullptr;
    debug_verify_data_integrity();
}
void LinkedList::embed_after(Node *node_before, int value) {
    Node*middle=new Node(value);
    ++length;
    debug_add_node(middle);
    Node*node_after=node_before->next;
    link(node_before,middle);
    link(middle,node_after);
//    item->next=node->next;
//    node->next=item;
}
void LinkedList::insert_sorted(int value) {
    if(!length||value<=head->data)
        insert_front(value);
    else if(tail->data<=value)
        insert_end(value);
    else{
        for(Node*cur=head;cur;cur=cur->next){
            if(value<=cur->data){
                embed_after(cur->prev,value);
                break;
            }
        }
    }
    debug_verify_data_integrity();
}
void LinkedList::swap_head_tail() {
    if(!head||!head->next)
        return;
    Node*prv= get_nth(length-1);
    tail->next=head->next;
    prv->next=head;
    head->next= nullptr;
    swap(tail,head);
    debug_verify_data_integrity();
}
void LinkedList::left_rotate(int k) {
     if(length<=1||k%length==0)
         return;
     k%=length;
     Node*nth= get_nth(k);
     tail->next=head;
     tail=nth;
     head=nth->next;
     tail->next= nullptr;
     debug_verify_data_integrity();
}

void LinkedList::remove_duplicates_from_not_sorted() {
    if(length<=1)
        return;
    for(Node*cur1=head;cur1;cur1=cur1->next){
        for(Node*cur2=cur1->next,*prv=cur1;cur2;){
            if(cur1->data==cur2->data){
                delete_next_node(prv);
                cur2=prv->next;
            }else
                prv=cur2,cur2=cur2->next;
        }
    }
    debug_verify_data_integrity();
}
void LinkedList::delete_last_occurence(int target) {
    if(!length)
        return;
    Node*delete_my_next_node = nullptr;
    bool is_found = false;
    for(Node *cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next)
        if(cur->data==target)
            is_found=true,delete_my_next_node=prv;
    if(is_found){
        if(delete_my_next_node)
            delete_next_node(delete_my_next_node);
        else
            delete_front();
    }
    debug_verify_data_integrity();
}

void LinkedList::delete_next_node(Node *node) {
    Node* to_delete = node->next;
    bool is_tail = to_delete == tail;
    node->next = node->next->next;
    delete_node(to_delete);
    if(tail)
        tail = node;
}
void LinkedList::move_key_occurance_to_end(int key) {
    if(length<=1)
        return;
    int len=length;
    for(Node*cur=head,*prv= nullptr;len--;){
        if(cur->data==key)
            cur=move_to_end(cur,prv);
        else
            prv=cur,cur=cur->next;
    }
    debug_verify_data_integrity();
}

Node *LinkedList::move_to_end(Node *cur, Node *prv){
    Node* next = cur->next;
    tail-> next = cur;
    if (prv)
        prv->next = next;
    else
        head = next;
    tail = cur;
    tail->next = nullptr;
    return next;
}

int LinkedList::max(Node *head, bool is_first_call) {
    if(is_first_call)
        return this->max(this->head,false);
    if(head== nullptr)
        return INT_MIN;
    return std::max(head->data,this->max(head->next,false));
}
void LinkedList::odd_pos_even_pos() {
    if(length<=2)
        return;
    Node*first_even=head->next;
    Node*cur_odd=head;
    while(cur_odd->next&&cur_odd->next->next){
        Node*next_even=cur_odd->next;
        cur_odd->next=cur_odd->next->next;
        next_even->next=next_even->next->next;
        cur_odd=cur_odd->next;
        if(length%2==1)
            tail=next_even;
    }
    debug_verify_data_integrity();
}
void LinkedList::insert_alternate(LinkedList &another) {
    if(!another.length)
        return;
    if(!length){
        head=another.head;
        tail=another.tail;
        length=another.length;
        debug_data=another.debug_data;
    }else{
        Node*cur2=another.head;
        for(Node*cur1=head;cur1&&cur2;){
            Node*cur2_next_temp=cur2->next;
            insert_after(cur1,cur2);
            another.length--;
            cur2=cur2_next_temp;
            if(cur1==tail){
                tail=another.tail;
                cur1->next->next=cur2;
                length+=another.length;
                break;
            }
            cur1=cur1->next->next;
        }
    }
}

void LinkedList::insert_after(Node *src, Node *target) {
    assert(src&&target);
    target->next=src->next;
    src->next=target;
    debug_add_node(target);
    ++length;
}

Node* LinkedList::delete_and_link(Node *cur) {
    Node*ret=cur->prev;
    link(cur->prev,cur->next);
    delete_node(cur);
    return ret;
}

void LinkedList::delete_node_with_key(int value) {
    if(!length)
        return;
    if(head->data==value)
        delete_front();
    else{
        for(Node*cur=head;cur;cur=cur->next){
            if(cur->data==value){
                cur= delete_and_link(cur);
                if(!cur->next)
                    tail=cur;
                break;
            }
        }
    }
    debug_verify_data_integrity();
}
