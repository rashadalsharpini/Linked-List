#include <iostream>
#include"LinkedList.h"
using namespace std;
int main() {
    LinkedList<string> ll;
    for(int i =0;i<10;++i) {
        string test;
        cin >> test;
        ll.insert_end(test);
    }
    ll.print1();
//    ll.reverse_nodes();
    ll.print_reverse();
    ll.print1();

    cout<<"\n\n No run time error\n";
    return 0;
}
//-1 0 1 2 3 4 5 6 7
