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
    bool contains(int);
    void addBeforeValue(int,int);
    void addAfterValue(int,int);
    void deleteValue(int);
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
    while(it != NULL){
        cout << it->value << " ";
        it = it->nextNode;
    }
}

bool linkedList :: contains(int v){
    node *it = head;

    while(it != NULL){
        if(it->value == v){
            return true;
        }
        it = it->nextNode;
    }
    return false;
}

void linkedList :: addBeforeValue(int n,int v){
	node *q = new node;
	node *it = head;
	q->value = v;
	
	if(contains(n)){
		if(head->value == n){
            delete(q);
			addNodeToHead(v);
		}else{
			while(it != NULL && it->nextNode!=NULL){
				if(it->nextNode->value == n){
					q->nextNode = it->nextNode;
					it->nextNode = q;
					break;
				}
				cout << it->nextNode->value << endl;
				it = it->nextNode;
			}				
		}
	}else{
		cout << "No existe" << endl;
	}
}

void linkedList :: addAfterValue(int n, int v){
    node *q = new node;
    node *it = head;
    q -> value = v;

    if(contains(n)){
        if(tail->value == n){
            delete(q);
            addNodeToTail(v);
        }else{
            while (it != NULL && it->nextNode !=NULL){
                if(it->value == n){
                    q->nextNode = it ->nextNode;
                    it -> nextNode = q;
                    break; 
                }
                it = it->nextNode;
            }
        }
    }else{
        cout << "No existe" << endl;
    }
}

void linkedList::deleteValue(int n){
    node *bit = head;
    node *it = head->nextNode;
    
    if(contains(n)){
        if(bit->value == n){
            head = it;
            delete(bit);
        }else{
            while(it != NULL){         
                if(it->value == n){
                    bit->nextNode = it->nextNode;
                    delete(it);
                }
                if( it == tail && it->value == n){
                    tail = bit;
                    bit->nextNode =NULL;
                    delete(it);
                }
                bit = it;
                it = it->nextNode;
            }
        }
        
    }else{
        cout << "El valor no existe" << endl;
    }
}

int main()
{
    linkedList *l = new linkedList();
    l->addNodeToHead(6);
    l->addNodeToTail(1);
    l->addNodeToHead(2);
    l->addNodeToTail(9);
    l->addBeforeValue(6,19);
    l->addAfterValue(1,15);
    l->displayNodes();
    l->deleteValue(2);
    l->deleteValue(6);
    l->deleteValue(9);
    l->displayNodes();

    cout<<endl;
    return 0;
}
