#include <iostream>

using namespace std;

#include "seqlist.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    int a;
    int *p = &a;
    *p = 100;
    cout << "*p的值" << *p << endl;
    cout << "p的值" << p << endl;
    Seq *seq = nullptr;
    cout << "指针地址==" << seq << endl;
    seq->seqInsert(5, 4);
    seq->seaDelete(4);

    LinkList l = seq->buildLinklist();
    cout << l << endl;
    cout << &l << endl;

//   seq->insertLinkList()

//   Node *node= seq->createLinkList();
   Node *node= seq->createLinkListTail();
   while (nullptr!=node){
       cout<<"输出链表--"<<node->data.data<<endl;
       node=node->next;
   }
    return 0;
}

void Seq::seqInsert(int x, int i) {
    int *list = new int[6]{1, 2, 3, 4, 7};
    cout << "查看指针地址==" << list << endl;

    cout << "查看指针==" << list[0] << endl;
    cout << "查看取地址==" << &list[0] << endl;


    for (int j = 5; j >= i; j--) {
        list[j] = list[j - 1];
    }
    list[i - 1] = x;

    for (int k = 0; k < 6; k++) {
        cout << "输出 -- " << list[k] << endl;
    }
}

void Seq::seaDelete(int i) {
    int templeArray[7] = {1, 2, 3, 4, 5, 6, 7};
    for (int j = i; j < 7; j++) {
        templeArray[j] = templeArray[j + 1];
    }

    for (int k = 0; k < 6; k++) {
        cout << "删除后 -- " << templeArray[k] << endl;
    }
}

LinkList Seq::buildLinklist() {
    Node *head;
    head = (Node *) (malloc(sizeof(LinkList)));

    //或者这样，因为molloc分配的堆内存 对象必须是指针接收
    LinkList linkList1;
    linkList1 = (LinkList) malloc(sizeof(Node));
    head->data.data = 1;
    head->next = nullptr;
    return head;
}

LinkList Seq::indexNode(LinkList head, unsigned int i) {
    if (i <= 0) {
        return nullptr;
    } else {
        int index = 1;
        LinkList current = head->next;
        while (nullptr != current && index < i) {
            index++;
            current = current->next;
        }
        if (nullptr == current) {
            return nullptr;
        }
        return current;
    }
}

void Seq::insertLinkList(LinkList head, Data data, int i) {
    LinkList prev;
    if (1 == i) {
        prev = head;
    } else {
        prev = indexNode(head, i - 1);//找到i-1的位置的Node
    }
    if (nullptr != prev) {
        LinkList node = (LinkList) malloc(sizeof(LinkList));
        node->data = data;
        node->next = prev->next;
        prev->next = node;
    }
}

void Seq::deleteNode(LinkList head, int i) {
    LinkList prev;
    if (1 == i) {
        prev = head;
    } else {
        prev = indexNode(head, i - 1);
        if (nullptr != prev) {
            LinkList p = prev->next;
            prev->next = p->next;
            free(p);
        }
    }
}

LinkList Seq::createLinkList() {
    int d;

    LinkList head = buildLinklist();
    cin >> d;
    int i = 1;
    while (d != 0) {
        Data newData;
        newData.data = d;
        insertLinkList(head,newData,i);
        i++;
        cin >> d;
    }
    return head;
}

LinkList Seq::createLinkListTail() {
    LinkList head=buildLinklist();
    int d;
    LinkList tail=head;
    cin>>d;
    while (0!=d){
        LinkList newData=(LinkList)malloc(sizeof(LinkList));
        newData->data.data=d;

        //设置尾指针指向 新节点
        tail->next=newData;
        //将新新节点设置为尾指针，便于下一循环设置next
        tail=newData;
        cin>>d;
    }
    tail->next= nullptr;
    return head;
}

LinkList Seq::createLinkListToHead() {
    int d;
    cin>>d;
    LinkList head=buildLinklist();
    while (0!=d){
        LinkList newNode=(LinkList)malloc(sizeof(LinkList));
        newNode->data.data=d;
        newNode->next=head->next;
        head->next=newNode;

        cin>>d;
    }
    return head;
}



