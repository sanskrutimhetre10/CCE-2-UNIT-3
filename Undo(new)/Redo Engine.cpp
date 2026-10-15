#include <iostream>
#include <string>
using namespace std;

// Node structure for the Linked List Stack
struct Node
{
    string data;
    Node* next;

    Node(string val)
    {
        data = val;
        next = NULL;
    }
};

// Stack implementation using a Singly Linked List
class Stack
{
private:
    Node* topNode;

public:
    Stack()
    {
        topNode = NULL;
    }

    // Insert element at the top of the stack (head of linked list)
    void push(string val)
    {
        Node* newNode = new Node(val);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Remove element from the top of the stack
    void pop()
    {
        if (empty())
        {
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Retrieve the top element without removing it
    string top()
    {
        if (empty())
        {
            return "";
        }
        return topNode->data;
    }

    // Check if the stack is empty
    bool empty()
    {
        return topNode == NULL;
    }

    // Clean up dynamically allocated nodes on destruction
    ~Stack()
    {
        while (!empty())
        {
            pop();
        }
    }
};

class UndoRedo
{
    Stack undoStack;
    Stack redoStack;
    string text;

public:
    UndoRedo()
    {
        text = "";
    }

    void insertText(string newText)
    {
        undoStack.push(text);
        text = text + newText;

        while (!redoStack.empty())
        {
            redoStack.pop();
        }
    }

    void undo()
    {
        if (undoStack.empty())
        {
            cout << "Nothing to undo!" << endl;
            return;
        }

        redoStack.push(text);
        text = undoStack.top();
        undoStack.pop();
    }

    void redo()
    {
        if (redoStack.empty())
        {
            cout << "Nothing to redo!" << endl;
            return;
        }

        undoStack.push(text);
        text = redoStack.top();
        redoStack.pop();
    }

    void display()
    {
        cout << "Text: " << text << endl;
    }
};

int main()
{
    UndoRedo editor;
    int choice;
    string data;

    do
    {
        cout << "\n--- Undo/Redo Engine ---" << endl;
        cout << "1. Insert Text" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Redo" << endl;
        cout << "4. Display Text" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter text: ";
            cin >> data;
            editor.insertText(data);
            break;

        case 2:
            editor.undo();
            break;

        case 3:
            editor.redo();
            break;

        case 4:
            editor.display();
            break;

        case 5:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
