#include <iostream>

using namespace std;

struct node {
    int value;
    node *nextNode;
};

class linkedList{
private:
    node *tail, *head;
public:
    linkedList();
    void addNodeToHead(int);
    void addNodeToTail(int);
};

linkedList::linkedList(){
    tail = NULL;
    head = NULL;
}

void linkedList :: addNodeToHead (int v){
    node *q = new node;
    q->value = v;

    if(head == NULL){
        head = q;
        tail = q;
    }else{
        q->nextNode = head;
        head = q;
        delete(q);
    }
}

void linkedList :: addNodeToTail (int v){
    node *q = new node;
    q->value = v;

    if(tail == NULL){
        head = q;
        tail = q;
    }else{
        q->nextNode = tail;
        tail = q;
    }

}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
