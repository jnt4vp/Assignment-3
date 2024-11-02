#include <iostream>
#include "queue.h"

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(){
            data = 0;
            next = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Queue {
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int num_items = 0;
    void push(int data){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
            num_items++;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    };
    void pop(){
        if(head == NULL){
            cout << "EMPTY\n";
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
            num_items--;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        num_items--;
        
    }
    int front(){
        return head->data;
    }
    int size(){
        return num_items;
    }
    bool empty() const {
        return num_items == 0;
    }
    void move_to_rear() {
        if (!empty()){  
            int frontElement = front();  
            pop();                       
            push(frontElement);          
        }
    }
};

int main(){
    Queue main;
    for(int i=0;i<10;i++){
        main.push(i);
    }
    for(int i=0;i<10;i++){
        cout << main.front() << "\n";
        main.pop();
    }
}