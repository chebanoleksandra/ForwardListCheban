#include "ForwardList.h"
#include "List.h"
#include <iostream>
using namespace std;
int main()
{
    /*ForwardList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(4);
    list.print();
    Node* first_node = list.GetHead()->next->next;
    list.push_after(first_node, 5);
    list.print();
    const Node* res = list.find(2);
    if (res)
    {
        cout << "Result: " << res->value;
    }

    ForwardList list2(list);
    list2.print();
    ForwardList list3 = list2;
    list3.print();*/

    List<int> list;
    list.push_back(10);
    list.push_back(1);
    list.push_back(-5);
    list.push_front(0);
    list.push_front(15);
    list.push_front(15);
    list.show();
    list.reverse();
    list.show();
    list.pop_back();
    list.show();
    list.pop_front();
    list.show();

    List<int> list2;
    list2.push_back(15);
    list2.push_back(3);
    list2.push_back(8);
    list2.push_back(10);
    list2.show();

    List<int>* list3 = list + list2;
    list3->show();

    List<int>* list4 =  list * list2;
    list4->show();
    return 0;
}