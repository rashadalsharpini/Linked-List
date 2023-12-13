#include <iostream>
#include"LinkedList.h"
using namespace std;
int main() {
    LinkedList<int> ll;
    for(int i =0;i<10;++i) {
        ll.insert_sorted(i);
    }
    ll.print();
//    ll.reverse_nodes();
    ll.print_reverse();

    cout<<"\n\n No run time error\n";
    return 0;
}
//-1 0 1 2 3 4 5 6 7
