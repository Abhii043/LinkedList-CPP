#include<iostream>
#include"./include/LinkedList.h"

using linkedlist::linkedList;

int main()
{
    linkedList l;
    l.insertAtbegin(10);
    l.insertAtbegin(20);
    l.insertAtlast(27);
    l.insertAtlast(30);
    l.insertAtPos(5, 25);
    l.display();
    std::cout << l.getLength() << '\n';
    l.deleteIndex(3);
    l.display();
    std::cout << l.getLength() << '\n';
}