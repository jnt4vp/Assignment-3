#include <iostream>
#include <vector>

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
            this->data = NULL;
        }
};

class LinkedList {
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int num_items = 0;
    void push_front(int data){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
            num_items++;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
        num_items++;
    };
    void push_back(int data){
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
    void pop_front(){
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
    void pop_back(){
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
        Node* current = head;
        while(current->next != tail){
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = NULL;
        num_items--;
    }
    void empty(){
        while(head != NULL){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
        num_items = 0;
    }
    void insert(int index, const int item){
        if(index <= 0){
            push_front(item);
            return;
        }
        if(index > num_items){
            push_back(item);
            return;
        }
        Node* current = head;
        for(int i=0;i<index-1;i++){
            current = current->next;
        }
        Node* newNode = new Node(item);
        newNode->next = current->next;
        current->next = newNode;
        num_items++;
    }
    bool remove(int index){
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
        Node* current = head;
        for(int i=0;i<index-1;i++){
            current = current->next;
        };
        Node* temp = current->next;
        current->next = temp->next;
        if(temp == tail){
            tail = current;
        }
        delete temp;
        num_items--;
        return true;
    }
    int find(const int item){
        Node* current = head;
        int index = 0;
        while(current != NULL){
            if(current->data == item){
                return index;
            }
            current = current ->next;
            index++;
        }  
    }


};

void insertion_sort(LinkedList &list) {
    if (list.head == nullptr) return;
    Node* sorted = nullptr;
    Node* current = list.head;
    while (current != nullptr) {
        Node* next = current->next;
        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* sortedCurrent = sorted;
            while (sortedCurrent->next != nullptr && sortedCurrent->next->data < current->data) {
                sortedCurrent = sortedCurrent->next;
            }
            current->next = sortedCurrent->next;
            sortedCurrent->next = current;
        }
        current = next; 
    }
    list.head = sorted;
}