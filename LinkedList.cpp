//
// Created by rashadalsharpini on 02/11/23.
//
// ninja: no work to do.

#include "LinkedList.h"
template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<float>;
template class LinkedList<size_t>;
template class LinkedList<string>;
template class LinkedList<char>;
template class LinkedList<bool>;
template <typename T>
LinkedList<T>::~LinkedList() {
    while(head){
        Node<T>*current = head->next;
        delete head;
        head=current;
    }
}
template <typename T>
void LinkedList<T>::print1() {
    for(Node<T>*cur=head;cur;cur = cur->next){
        cout<<cur->data<<" ";
    }
    cout<<endl;
}
template <typename T>
void LinkedList<T>::print_reverse() {
    for(Node<T>*cur=tail;cur;cur=cur->prev)
        cout<<cur->data<<" ";
    cout<<endl;
}
template <typename T>
void LinkedList<T>::link(Node<T> *first, Node<T> *second) {
    if(first)
        first->next=second;
    if(second)
        second->prev=first;
}
template <typename T>
void LinkedList<T>::insert_end(T value) {
    Node<T>* item = new Node(value);
    debug_add_node(item);
    if(!head)
        head = tail = item;
    else{
        link(tail,item);
        tail = item;
    }
    length++;
}
template <typename T>
void LinkedList<T>::insert_front(T value) {
    Node<T>* item = new Node(value);

    if(!head)
        head = tail = item;
    else{
        link(item,head);
        head = item;
    }
    length++;
}
template <typename T>
Node<T>* LinkedList<T>::get_nth(int index) {
    int cnt = 0;
    for (Node<T> *cur = head; cur; cur = cur->next)
        if (cnt++ == index)
            return cur;
    return nullptr;
}
template <typename T>
int LinkedList<T>::Search(T value) {
    int index = 0;
    for(Node<T>* cur =head;cur;cur=cur->next,index++)
        if(cur->data==value)
            return index;
    return -1;
}
template <typename T>
int LinkedList<T>::improvedSearchV1(T value) { //not now
    int index = 0;
    Node<T>* previous = nullptr;
    for(Node<T>* cur =head;cur;cur=cur->next,index++) {
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
//template <typename T>
//int LinkedList<T>::improvedSearchV2(int value) {
//    int index = 0;
//    for(Node*<T>cur = head,<T>*prv=nullptr;cur;prv=cur,cur = cur->next){
//        if(cur->data==value){
//            if(!prv)
//                return index;
//            swap(prv->data,cur->data);
//            return index-1;
//        }
//        ++index;
//    }
//    return -1;
//}
template <typename T>
void LinkedList<T>::debug_verify_data_integrity() {
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
    for (Node<T>* cur = head; cur; cur = cur->next, cur_length++)
        assert(cur_length < 10000); // handling infinite cycle

    assert(cur_length == length);
}

template <typename T>
string LinkedList<T>::debug_to_string() {
        if(length==0)
            return "";
        ostringstream oss;
        for(Node<T>*cur=head;cur;cur=cur->next){
            oss<<cur->data;
            if(cur->next)
                oss<<"";
        }
        return oss.str();
}
template <typename T>
void LinkedList<T>::debug_add_node(Node<T> *node) {
    debug_data.push_back(node);
}
template <typename T>
void LinkedList<T>::debug_remove_node(Node<T> *node) {
    auto it = std::find(debug_data.begin(),debug_data.end(),node);
    if(it==debug_data.end())
        cout<<"Node does not exist"<<endl;
    else
        debug_data.erase(it);
}
template <typename T>
void LinkedList<T>::debug_print_node(Node<T> *node, bool is_seperate) {
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
template <typename T>
void LinkedList<T>::debug_print_list(string msg) {
    if(msg !="")
        cout<<msg<<endl;
     for(int i=0;i<(int)debug_data.size();i++)
        debug_print_node(debug_data[i]);
    cout<<"************************\n"<<flush;
}
template <typename T>
Node<T>* LinkedList<T>::get_nth_back(int n) {
    if(length<n)
        return nullptr;
    return get_nth(length - (n + 1));
}
template <typename T>
bool LinkedList<T>::is_same1(const LinkedList &other) {
    Node<T>*h1=head,*h2=other.head;
    while(h1&&h2){
        if(h1->data!=h2->data)
            return false;
        h1=h1->next,h2=h2->next;
    }
    return !h1 && !h2;
}
template <typename T>
bool LinkedList<T>::is_same(const LinkedList &other) {
    if(length != other.length)
        return false;
    Node<T>*other_h=other.head;
    for(Node<T>*cur_h=head;cur_h;cur_h=cur_h->next){
        if(cur_h->data!=other_h->data)
            return false;
        other_h=other_h->next;
    }
    return true;
}
template <typename T>
void LinkedList<T>::add_element(T value) {
    Node<T>*item = new Node(value);
    item->next=head;
    head=item;
}
template <typename T>
void LinkedList<T>::delete_node(Node<T> *node) {
    --length;
    delete node;
}
template <typename T>
void LinkedList<T>::delete_front() {
    if(!head)
        return;
    Node<T>*cur=head->next;
    delete_node(head);
    head=cur;
    if(head)
        head->prev= nullptr;
    else if(!length)
        tail= nullptr;
}template <typename T>
void LinkedList<T>::delete_first() {
    if(head){
        Node<T>* cur=head;
        head=head->next;
        delete_node(cur);
        if(!head)
            tail= nullptr;
        debug_verify_data_integrity();
    }
}
template <typename T>
void LinkedList<T>::delete_end() {
    if(!head)
        return;
    Node<T>*cur = tail->prev;
    delete_node(tail);
    tail=cur;
    if(tail)
        tail->next = nullptr;
    else if(!length)
        head = nullptr;
}
template <typename T>
void LinkedList<T>::delete_nth(int index) {
    if(index<0||index>length)
        cout<<"Error. No such nth node\n";
    else if(index==0)
        delete_front();
    else if(index==length-1)
        delete_end();
    else{
        Node<T>*cur = get_nth(index);
        link(cur->prev,cur->next);
        delete_node(cur);
    }
}
template <typename T>
void LinkedList<T>::delete_value(T value) {
    delete_nth(Search(value));
}
template <typename T>
void LinkedList<T>::swap_pair() {
    for(Node<T>*cur=head;cur;cur=cur->next){
        if(cur->next) {
            swap(cur->data, cur->next->data);
            // I forgot about the two steps move because I supposed to swap each pair
            cur=cur->next;
        }
    }
}
template <typename T>
void LinkedList<T>::reverse_nodes() { //single linked list
    if(length<=1)
        return;
    Node<T>*cur=tail;
    while(cur!=NULL){
        Node<T>*next=cur->next;
        cur->next=cur->prev;
        cur=next;
    }
    Node <T>*aux=tail;
    tail=head;
    head=aux;
//    tail=head;
//    Node*prv=head;
//    head=head->next;
//    while(head){
//        Node*next=head->next;
//        head->next=prv;
//        prv=head;
//        head=next;
//    }
//    head=prv;
//    tail->next=nullptr;
}
template <typename T>
void LinkedList<T>::embed_after(Node<T> *node_before, T value) {
    Node<T>*middle=new Node(value);
    ++length;
    debug_add_node(middle);
    Node<T>*node_after=node_before->next;
    link(node_before,middle);
    link(middle,node_after);
//    item->next=node->next;
//    node->next=item;
}
template <typename T>
void LinkedList<T>::insert_sorted(T value) {
    if(!length||value<=head->data)
        insert_front(value);
    else if(tail->data<=value)
        insert_end(value);
    else{
        for(Node<T>*cur=head;cur;cur=cur->next){
            if(value<=cur->data){
                embed_after(cur->prev,value);
                break;
            }
        }
    }
}
template <typename T>
void LinkedList<T>::swap_head_tail() {
    if(!head||!head->next)
        return;
    Node<T>*prv= get_nth(length-1);
    tail->next=head->next;
    prv->next=head;
    head->next= nullptr;
    swap(tail,head);
    debug_verify_data_integrity();
}
template <typename T>
void LinkedList<T>::left_rotate(int k) {
     if(length<=1||k%length==0)
         return;
     k%=length;
     Node<T>*nth= get_nth(k);
     tail->next=head;
     tail=nth;
     head=nth->next;
     tail->next= nullptr;
     debug_verify_data_integrity();
}
template <typename T>
void LinkedList<T>::remove_duplicates_from_not_sorted() {
    if(length<=1)
        return;
    for(Node<T>*cur1=head;cur1;cur1=cur1->next){
        for(Node<T>*cur2=cur1->next,*prv=cur1;cur2;){
            if(cur1->data==cur2->data){
                delete_next_node(prv);
                cur2=prv->next;
            }else
                prv=cur2,cur2=cur2->next;
        }
    }
    debug_verify_data_integrity();
}
template <typename T>
void LinkedList<T>::delete_last_occurence(int target) {
    if(!length)
        return;
    Node<T>*delete_my_next_node = nullptr;
    bool is_found = false;
    for(Node<T> *cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next)
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
template <typename T>
void LinkedList<T>::delete_next_node(Node<T> *node) {
    Node<T>* to_delete = node->next;
    bool is_tail = to_delete == tail;
    node->next = node->next->next;
    delete_node(to_delete);
    if(tail)
        tail = node;
}
template <typename T>
void LinkedList<T>::move_key_occurance_to_end(int key) {
    if(length<=1)
        return;
    int len=length;
    for(Node<T>*cur=head,*prv= nullptr;len--;){
        if(cur->data==key)
            cur=move_to_end(cur,prv);
        else
            prv=cur,cur=cur->next;
    }
    debug_verify_data_integrity();
}
template <typename T>
Node<T> *LinkedList<T>::move_to_end(Node<T> *cur, Node<T> *prv){
    Node<T>* next = cur->next;
    tail-> next = cur;
    if (prv)
        prv->next = next;
    else
        head = next;
    tail = cur;
    tail->next = nullptr;
    return next;
}
template <typename T>
int LinkedList<T>::max(Node<T> *head, bool is_first_call) {
    if(is_first_call)
        return this->max(this->head,false);
    if(head== nullptr)
        return INT_MIN;
    return std::max(head->data,this->max(head->next,false));
}
template <typename T>
void LinkedList<T>::odd_pos_even_pos() {
    if(length<=2)
        return;
    Node<T>*first_even=head->next;
    Node<T>*cur_odd=head;
    while(cur_odd->next&&cur_odd->next->next){
        Node<T>*next_even=cur_odd->next;
        cur_odd->next=cur_odd->next->next;
        next_even->next=next_even->next->next;
        cur_odd=cur_odd->next;
        if(length%2==1)
            tail=next_even;
    }
    debug_verify_data_integrity();
}
template <typename T>
void LinkedList<T>::insert_alternate(LinkedList &another) {
    if(!another.length)
        return;
    if(!length){
        head=another.head;
        tail=another.tail;
        length=another.length;
        debug_data=another.debug_data;
    }else{
        Node<T>*cur2=another.head;
        for(Node<T>*cur1=head;cur1&&cur2;){
            Node<T>*cur2_next_temp=cur2->next;
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
template <typename T>
void LinkedList<T>::insert_after(Node<T> *src, Node<T> *target) {
    assert(src&&target);
    target->next=src->next;
    src->next=target;
    debug_add_node(target);
    ++length;
}
template <typename T>
Node<T>* LinkedList<T>::delete_and_link(Node<T> *cur) {
    Node<T>*ret=cur->prev;
    link(cur->prev,cur->next);
    delete_node(cur);
    return ret;
}
//template <typename T>
//void LinkedList<T>::delete_node_with_key(int value) {
//    if(!length)
//        return;
//    if(head->data==value)
//        delete_front();
//    else{
//        for(Node*<T>cur=head;cur;cur=cur->next){
//            if(cur->data==value){
//                cur= delete_and_link(cur);
//                if(!cur->next)
//                    tail=cur;
//                break;
//            }
//        }
//    }
//    debug_verify_data_integrity();
//}

//template<typename T>
//void LinkedList<T>::print1() {
//
//}
