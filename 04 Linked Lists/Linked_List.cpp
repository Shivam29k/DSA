// A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers. In simple words, a linked list consists of nodes where each node contains a data field and a reference(link) to the next node in the list.


// C++ program to implement a singly linked list

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// insert a tail 
// first will start from head then go to next node until it reach to null then it will insert the new node
// will rake head as a reference so that we can change the value
void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);

    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;    
}

// insert a head
// first will create a new node and then it will point to the head and then head will point to the new node
void insertAtHead(Node* &head, int val){
    Node* n = new Node(val);
    n->next = head;
    head = n;
}


// display the linked list
// first will start from head then go to next node until it reach to null and print the value at every node
void display(Node* head){
    Node*temp = head;

    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

// search in linked list
// first will start from head then go to next node until it reach to null and check the value at every node
bool search(Node* head, int key){
    Node* temp = head;
    while (temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// delete a node
// first will start from head then go to next node until it reach to null and check the value at every node
// if the value is equal to the key then it will point the previous node to the next node of the current node

void deleteNode(Node* &head, int val){
    Node* temp = head;
    while (temp->next != NULL){
        if(temp->next->data == val){
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }

}


int main(){
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 4);
    display(head);
    cout<<search(head, 3)<<endl;
    cout<<search(head, 5)<<endl;
    deleteNode(head, 2);
    display(head);
    return 0;
}
