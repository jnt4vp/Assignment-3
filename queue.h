//Project 3
//Jack Turner
//CS 303
//November 2, 2024

#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node();
        Node(int data);
};

class Queue {
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int num_items = 0;
    void push(int data); //Pushes item to the back of the queue
    void pop(); //Pops the front item in the queue
    int front(); //Returns the front item in the queue
    int size(); //Returns size of queue
    bool empty(); //Empties queue
    void move_to_rear(); //Moves the front item in a queue to the back
};