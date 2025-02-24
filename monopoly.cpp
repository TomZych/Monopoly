#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class circularLinkedList{

private:
    Node<T>* head;
    Node<T>* current;

public:
    circularLinkedList() : head(nullptr), current(nullptr) {}

    void append(T val){
        Node<T>* newNode = new Node<T>(val);
        if (!head){
            head = newNode;
            head->next = head;
            current = head;
        } else {
            Node<T>* temp = head;
            while (temp->next != head){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
    void step(){
        if (current != nullptr){
            current = current->next;
        }
    }
    T getCurrentData(){
        if (current != nullptr){
            return current->data;
        }
        return T();
    }
    void roll(){
        int total = (rand() % 7) + (rand() % 7);
        cout << "Rolled total: " << total << "\n";
        for (int i = 0; i < total; i++){
            step();
        }
    }
};

int main() {
    srand(time(0));

    circularLinkedList<string> monopolyBoard;

    monopolyBoard.append("Go");
    monopolyBoard.append("Mediterranean Avenue");
    monopolyBoard.append("Community Chest");
    monopolyBoard.append("Baltic Avenue");
    monopolyBoard.append("Income Tax");
    monopolyBoard.append("Reading Railroad");
    monopolyBoard.append("Oriental Avenue");
    monopolyBoard.append("Chance");
    monopolyBoard.append("Vermont Avenue");
    monopolyBoard.append("Connecticut Avenue");
    monopolyBoard.append("Jail (Just Visiting)");
    monopolyBoard.append("St. Charles Place");
    monopolyBoard.append("Electric Company");
    monopolyBoard.append("States Avenue");
    monopolyBoard.append("Virginia Avenue");
    monopolyBoard.append("Pennsylvania Railroad");
    monopolyBoard.append("St. James Place");
    monopolyBoard.append("Community Chest");
    monopolyBoard.append("Tennessee Avenue");
    monopolyBoard.append("New York Avenue");
    monopolyBoard.append("Free Parking");
    monopolyBoard.append("Kentucky Avenue");
    monopolyBoard.append("Chance");
    monopolyBoard.append("Indiana Avenue");
    monopolyBoard.append("Illinois Avenue");
    monopolyBoard.append("B&O Railroad");
    monopolyBoard.append("Atlantic Avenue");
    monopolyBoard.append("Ventnor Avenue");
    monopolyBoard.append("Water Works");
    monopolyBoard.append("Marvin Gardens");
    monopolyBoard.append("Go to Jail");
    monopolyBoard.append("Pacific Avenue");
    monopolyBoard.append("North Carolina Avenue");
    monopolyBoard.append("Community Chest");
    monopolyBoard.append("Pennsylvania Avenue");
    monopolyBoard.append("Short Line Railroad");
    monopolyBoard.append("Chance");
    monopolyBoard.append("Park Place");
    monopolyBoard.append("Luxury Tax");
    monopolyBoard.append("Boardwalk");

    cout << "Starting at: " << monopolyBoard.getCurrentData() << "\n"; 
    monopolyBoard.roll(); 
    cout << "Current space after roll: " << monopolyBoard.getCurrentData() << "\n";

    return 0;
}

/*
Starting at: Go
Rolled total: 8
Current space after roll: Vermont Avenue

Starting at: Go
Rolled total: 6
Current space after roll: Oriental Avenue
*/