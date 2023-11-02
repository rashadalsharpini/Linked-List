#include <iostream>
using namespace std;
#include"LinkedList.h"
int main() {
    LinkedList ll;
    for(int i =0;i<10;++i)
        ll.insert_end(i);
    ll.print1();
    int idx = ll.Search(7);
    cout<<ll.get_nth(idx)->data<<endl;
    cout<<"\n\n No run time error\n";
    return 0;
}
