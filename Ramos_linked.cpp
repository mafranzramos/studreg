#include <iostream>
#include <cctype>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* head = NULL;

void appendNode(string info) {
    Node* n = new Node();
    n->data = info;
    n->next = NULL;

    if (head == NULL) {
        head = n;
    } else {
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = n;
    }
}


void displayList(void) {
    Node* curr;
    curr = head;
    while (curr != NULL) {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

int main() {
    string SRCODE, name, subjCode, profName, sched, x;
    int numStudents, temp;
    char back, show;

    do {
        system("CLS");
        cout << "Enter the number of students: ";
        cin >> numStudents;
        cin.ignore();

        for (int i = 0; i < numStudents; i++) {
            system("CLS");
            cout << "\t\tEnter the data for student " << i + 1 << endl;

        do {
            cout << "Enter the SRCODE: " << endl;
            getline(cin, SRCODE);
            appendNode(SRCODE);

            if (name.empty()) {
            system("CLS");
            cout << "Please input your SRCODE." << endl;
            }
        } while (SRCODE.empty());

        do {
        cout << "Enter the name: " << endl;
        getline(cin, name);
        appendNode(name);

            if (name.empty()) {
            system("CLS");
            cout << "Please input your name." << endl;
            }
        } while (name.empty());

        do {
            cout << "Enter the subject code: " << endl;
            getline(cin, subjCode);
            appendNode(subjCode);

            if (subjCode.empty()) {
            system("CLS");
            cout << "Please input your subject code." << endl;
            }
        } while (subjCode.empty());

        do {
            cout << "Enter professor name: " << endl;
            getline(cin, profName);
            appendNode(profName);

            if (name.empty()) {
            system("CLS");
            cout << "Please input your professor's name." << endl;
            }
        } while (profName.empty());

        do {
            cout << "Enter sched: " << endl;
            getline(cin, sched);
            appendNode(sched);

            if (sched.empty()) {
            system("CLS");
            cout << "Please input your sched." << endl;
            }
        } while (sched.empty());

        }

        cout << "Press 's' to search SRCODE." << endl;
        cout << "Press 'a' to display all students registered." << endl;
        cin >> show;

        cin.ignore();

    if (show == 's' || show == 'S') {
    system("CLS");
    cout << "\nEnter the SRCODE to display the details: " << endl;
    getline(cin, x);
    temp = 0;
    Node* curr = head;
    while (curr != NULL) {
            if (x == curr->data) {
            cout << "\nName: " << curr->next->data << endl;
            cout << "\nDetails: " << curr->next->next->data << ", " << curr->next->next->next->data << ", " << curr->next->next->next->next->data << endl;
            temp = 1;
            break;
        }
        curr = curr->next;
    }
    if (temp == 0) {
        cout << "\nThe student identified by the given SRCODE does not exist." << endl;
    }
}


        if (show == 'a' || show == 'A') {
            Node* curr = head;
            while (curr != NULL) {
                cout << "\nSR-CODE: " << curr->data << endl;
                cout << "\nDetails: " << curr->next->data << ", " << curr->next->next->data << ", " << curr->next->next->next->data << ", " << curr->next->next->next->next->data << endl;
                curr = curr->next->next->next->next->next;
            }
        }

        cout << "\t Continue registering? [Y/N]: ";
        cin >> back;
        cin.ignore();

    } while (back == 'y' || back == 'Y');

    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
