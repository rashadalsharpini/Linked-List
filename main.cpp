#include <iostream>
#include"LinkedList.h"
using namespace std;
int main() {
    LinkedList ll;
    for(int i =0;i<8;++i)
        ll.insert_end(i);
    ll.print1();
//    ll.delete_nth(2); // error no link in a backward way
//    ll.print_reverse();
//    ll.reverse_nodes();
//    ll.print_reverse();
    cout<<"\n\n No run time error\n";
    return 0;
}
//-1 0 1 2 3 4 5 6 7
