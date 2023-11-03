#include <iostream>
#include"LinkedList.h"
using namespace std;
void test1(){
    cout<<"\ntest1\n";
    LinkedList list;
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.print1();
    string expected = "1 2 3 4";
    string result = list.debug_to_string();
    if(expected!=result){
        cout<<"no match : \n Expected:"
            <<expected<<"\nresult : "<<result<<endl;
        assert(false);
    }
    list.debug_print_list("************");
}
int main() {
    LinkedList ll;
    for(int i =0;i<10;++i)
        ll.insert_end(i);
    ll.print1();
    ll.insert_front(123);
    ll.print1();
    cout<<"\n\n No run time error\n";
    return 0;
}
