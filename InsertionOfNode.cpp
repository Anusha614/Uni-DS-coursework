#include <iostream> 
using namespace std; 
 
//CREATE A NODE CLASS 
class Node { 
 
    public: 
 
        int data; 
        Node* next; 
 
        Node (int val) { 
            data = val; 
            next = NULL; 
    } 
}; 
 
int main () { 
    // //create head make it point to null 
    // Node* head = NULL; 
    // //create newNode which point to node w data stored as 4 
    // Node*newNode = new Node(4); 
    // //make head point where newNode is pointing 
    // head = newNode; 
    // //create newNode to make it point to node w stored data 8 
    // Node*newNode2 = new Node(8); 
    // //make newNode point to where newNode2 is pointing 
    // newNode -> next = newNode2; 
 
    //MAKE A LIST OF 5 
    Node* head = new Node(1); 
    Node* temp = head; 
 
    for (int i = 2; i<=5; i++) { 
 
        Node*newNode = new Node(i); 
        temp -> next = newNode; 
        temp = newNode; 
 
    } 
 
    //printing original list 
    temp = head; 
    while (temp != NULL) { 
        cout << temp -> data << " "; 
        temp = temp -> next; 
    } 
 
    //INSERT NODE AT START 
    temp = head; 
    Node* startNode = new Node(10); 
    startNode -> next = head; 
    head = startNode; 
 
    //print list after inserting node at start 
    temp = head; 
    while (temp != NULL) { 
        cout << temp -> data << " "; 
        temp = temp -> next; 
    } 
 
    //INSERT NODE IN MIDDLE 
     
    Node* middleNode = new Node(15); 
 
    temp = head;
    for (int i = 0; i < 3; i ++) { 
        temp = temp->next; 
    } 
 
    //make middle point to where temp was pointing 
    middleNode -> next = temp -> next; 
    //make temp point to middleNode 
    temp -> next = middleNode; 
 
    //printing list after inserting node in middle 
    temp = head; 
    while (temp != NULL) { 
        cout << temp -> data << " "; 
        temp = temp -> next; 
    } 
 
    //INSERT NODE AT END 
    Node* endNode = new Node(20); 
 
    while (temp -> next != NULL) { 
        temp = temp -> next; 
    } 
 
    temp -> next = endNode; 
 
    //printing list after inserting node at end 
    temp = head; 
    while (temp != NULL) { 
        cout << temp -> data << " "; 
        temp = temp -> next; 
    } 
}