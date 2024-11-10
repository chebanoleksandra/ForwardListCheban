#include "ForwardList.h"
#include <iostream>
using namespace std;
int main()
{
    ForwardList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(4);
    list.print();
    /*Node* first_node = list.GetHead()->next->next;
    list.push_after(first_node, 5);
    list.print();
    const Node* res = list.find(2);
    if (res)
    {
        cout << "Result: " << res->value;
    }*/

    ForwardList list2(list);
    list2.print();
    ForwardList list3 = list2;
    list3.print();
    return 0;
}