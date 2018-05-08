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
    void displayNodes();
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
        tail->nextNode = q;
        tail = q;
    }

}

void linkedList :: displayNodes(){
    node *it = head;
    while(it!=NULL){
        cout<<it->value<<" ";
        it=it->nextNode;
    }

}

int main()
{
    linkedList *l = new linkedList();
    l->addNodeToHead(6);
    l->addNodeToTail(9);
    l->displayNodes();

    cout<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
