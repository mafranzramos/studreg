#include <iostream>
#include <cctype>
using namespace std;

struct student {
    string name;
    string SRCODE;
    string subjCode;
    string profName;
    string sched;
};

int main() {
    string numbers, x;
    int numStudents, temp;
    char back, show;

    do {
        system("CLS");
        cout << "Enter the number of students: ";
        cin >> numStudents;
        cin.ignore();

        student a[numStudents];
        for (int i = 0; i < numStudents; i++) {
            system("CLS");

            do {
                cout << "\t\tEnter the data for student " << i + 1 << endl;
                cout << "Enter the SR-CODE: " << endl;
                cin >> a[i].SRCODE;
                cin.ignore();
                numbers = ""; 
                for (int j = 0; j < a[i].SRCODE.length(); j++) {
                    if (isdigit(a[i].SRCODE[j])) {
                        numbers += a[i].SRCODE[j];
                    }
                    else if (a[i].SRCODE[j] == '-') {
                        continue;
                    }
                    else {
                        system("CLS");
                        cout << "Invalid SR-CODE! Enter your SR-CODE correctly." << endl;
                        a[i].SRCODE.clear();
                        cin.ignore();
                        cin.get();
                        break;
                    }
                }
            } while (a[i].SRCODE.empty() || numbers.empty());

            do {
                cout << "Enter the name: " << endl;
                cin.ignore();
                getline(cin, a[i].name);
                if (a[i].name.empty()) {
                    system("CLS");
                    cout << "Please input your name." << endl;
                }
            } while (a[i].name.empty());

            do {
                cout << "Enter the subject code: " << endl;
                getline(cin, a[i].subjCode);
                if (a[i].subjCode.empty()) {
                    system("CLS");
                    cout << "Please input the subject code." << endl;
                }
            } while (a[i].subjCode.empty());

            do {
                cout << "Enter professor name: " << endl;
                getline(cin, a[i].profName);
                if (a[i].profName.empty()) {
                    system("CLS");
                    cout << "Please input the professor name." << endl;
                }
            } while (a[i].profName.empty());

            do {
                cout << "Enter schedule time: " << endl;
                getline(cin, a[i].sched);
                if (a[i].sched.empty()) {
                    system("CLS");
                    cout << "Please input the schedule time." << endl;
                }
            } while (a[i].sched.empty());
        }

        cout << "Press 's' to search SRCODE." << endl;
        cout << "Press 'a' to display all students registered." << endl;
        cin >> show;

        if (show == 's' || show == 'S') {
            system("CLS");
            cout << "\n Enter the SRCODE to display the details: " << endl;
            cin >> x;
            temp = 0;
            for (int i = 0; i < numStudents; i++) {
                if (x == a[i].SRCODE) {
                    cout << "\nName: " << a[i].name;
                    cout << "\nDetails: " << a[i].subjCode << ", " << a[i].profName << ", " << a[i].sched << endl;
                    temp = 1;
                    break;
                }
            }
            if (temp == 0) {
                cout << "\nThe student identified by the given ID does not exist." << endl;
            }
        }

        if (show == 'a' || show == 'A') {
            for (int i = 0; i < numStudents; i++) {
                cout << "\nSR-CODE: " << a[i].SRCODE;
                cout << "\nDetails: " << a[i].subjCode << ", " << a[i].profName << ", " << a[i].sched << endl;
            }
        }

        cout << "\t Continue registering? [Y/N]: ";
        cin >> back;
        cin.ignore(); 

    } while (back == 'y' || back == 'Y');

    return 0;
}
