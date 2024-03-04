#include <iostream>
#include "Stack.h" // Include the Stack header
using namespace std;

int main() {
    Stack stack;
    int choice, value;

    while (true) {
        cout << "\nStack Operations:\n";
        cout << "1. Push a value\n";
        cout << "2. Pop a value\n";
        cout << "3. Check top value\n";
        cout << "4. Calculate average\n";
        cout << "5. Check if stack is empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            cout << "Enter the value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            if (stack.pop()) {
                cout << "Value popped successfully.\n";
            }
            else {
                cout << "Stack is empty. Cannot pop.\n";
            }
            break;
        case 3:
            try {
                cout << "Top of the stack: " << stack.top() << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        case 4:
            try {
                cout << "Average value of the stack elements: " << stack.average() << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        case 5:
            cout << "Stack is empty: " << (stack.isEmpty() ? "Yes" : "No") << endl;
            break;
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
