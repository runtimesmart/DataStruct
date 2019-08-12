//
// Created by Yl on 2019-08-01.
//

#ifndef PRATISE_SEQLIST_H
#define PRATISE_SEQLIST_H
typedef struct {
    int data;
} Data;

typedef struct node {
    Data data;
    node *next;

} Node, *LinkList;

class Seq {
public:
    //数组的插入
    static void seqInsert(int x, int i);

    //数组的删除
    static void seaDelete(int i);

    static LinkList buildLinklist();

    static LinkList indexNode(LinkList head, unsigned int i);

    static void insertLinkList(LinkList head, Data data, int i);

    void deleteNode(LinkList node, int i);

    //常规尾插法
    static LinkList createLinkList();

    //尾指针 尾插法
    static LinkList createLinkListTail();

    //头插法
    static LinkList createLinkListToHead();
};


#endif //PRATISE_SEQLIST_H
