// Compilation line: g++ -std=c++17 lab09-main.cpp -o main

#include <iostream>
#include <string>
#include "ArrayStack.hpp"

using namespace std;

int main() {
    ArrayStack<int> stackA(10);

    for (int i = 0; i < 10; i++) {
        stackA.push(i);
        cout << i;
        if (i < 9) {
            cout << " ";
        }
    }
    cout << endl;

    if (stackA.isFull()) {
        cout << "Stack A is full!" << endl;
    }

    cout << "Stack A length: " << stackA.getLength() << endl;

    ArrayStack<int> stackB(stackA);
    cout << "Stack B length: " << stackB.getLength() << endl;

    try {
        stackB.push(10);
    }
    catch (string error) {
        cout << error << endl;
    }

    for (int i = 0; i < 5; i++) {
        cout << "Popping " << stackB.peek() << " from stack B" << endl;
        stackB.pop();
    }

    cout << "Stack B length: " << stackB.getLength() << endl;

    stackB.clear();
    if (stackB.isEmpty()) {
        cout << "Stack B is now empty after being cleared" << endl;
    }

    try {
        stackB.pop();
    }
    catch (string error) {
        cout << error << endl;
    }

    try {
        stackB.peek();
    }
    catch (string error) {
        cout << error << endl;
    }

    ArrayStack<int> stackC(10);
    stackC = stackA;

    cout << "Stack A length: " << stackA.getLength() << endl;
    cout << "Stack C length: " << stackC.getLength() << endl;

    return 0;
}









































/*
// needed because rotate uses Stack<T>::RIGHT and Stack<T>::LEFT
template <typename T>
void testRotate(ArrayStack<T>& stack, const string& stackName) {
    cout << "\nTesting rotate on " << stackName << ":\n";
    cout << "Before rotate:\n";
    cout << stack << endl;

    stack.rotate(Stack<T>::RIGHT); // The right rotate moves the top most element to the bottom 
    cout << "After RIGHT rotate:\n";
    cout << stack << endl;

    stack.rotate(Stack<T>::LEFT); // The left rotate moves the bottom most element to the top of the stack
    cout << "After LEFT rotate:\n";
    cout << stack << endl;
}

int main() {
    cout << "--------------\n";
    cout << "Driver Program\n";
    cout << "--------------\n";

    try {
        cout << "\nCreating a stack for my current classes...\n";
        ArrayStack<string> classes(5);

        cout << "Is the classes stack empty? ";
        cout << (classes.isEmpty() ? "Yes" : "No") << endl;

        cout << "\nPushing some classes onto the stack:\n";
        classes.push("CS");
        classes.push("Python");
        classes.push("English 1A");
        classes.push("Math");
        cout << classes << endl;

        cout << "Top class right now: " << classes.peek() << endl;
        cout << "Current number of classes in stack: " << classes.getLength() << endl;
        cout << "Maximum size of classes stack: " << classes.getMaxSize() << endl;

        cout << "\nPopping the top class off the stack...\n";
        classes.pop();
        cout << classes << endl;

        testRotate(classes, "my classes stack");

        cout << "\nClearing the classes stack...\n";
        classes.clear(); // clears the stack 
        cout << classes << endl; 

        cout << "Is the classes stack empty now? ";
        cout << (classes.isEmpty() ? "Yes" : "No") << endl; // prints a yes because classes.clear emptied the stack

        cout << "\n-------------------------------------\n";
        cout << "Testing an int stack with exam scores\n";
        cout << "-------------------------------------\n";

        ArrayStack<int> scores(4);

        cout << "Pushing sample exam scores:\n";
        scores.push(88);
        scores.push(92);
        scores.push(95);
        cout << scores << endl;

        cout << "Top score: " << scores.peek() << endl;
        cout << "Is the score stack full? ";
        cout << (scores.isFull() ? "Yes" : "No") << endl;

        cout << "\nAdding one more score...\n";
        scores.push(98);
        cout << scores << endl;

        cout << "Is the score stack full now? ";
        cout << (scores.isFull() ? "Yes" : "No") << endl;

        testRotate(scores, "my exam scores stack");

        cout << "\n-------------------------------------\n";
        cout << "Testing copy constructor with work shifts\n";
        cout << "---------------------------------------\n";

        ArrayStack<string> shifts(4);
        shifts.push("Brighton shift");
        shifts.push("Gene's shift");
        shifts.push("Icicles shift");

        cout << "Original shifts stack:\n";
        cout << shifts << endl;

        ArrayStack<string> copiedShifts(shifts);
        cout << "Copied shifts stack:\n";
        cout << copiedShifts << endl;

        cout << "\n----------------------------------------\n";
        cout << "Testing assignment operator with favorites\n";
        cout << "------------------------------------------\n";

        ArrayStack<string> favorites1(4);
        favorites1.push("Jewlery");
        favorites1.push("Music");
        favorites1.push("Beach");

        ArrayStack<string> favorites2(4);
        favorites2 = favorites1;

        cout << "Original favorites stack:\n";
        cout << favorites1 << endl;

        cout << "Assigned favorites stack:\n";
        cout << favorites2 << endl;

        cout << "\n-------------------------------------\n";
        cout << "Testing exceptions\n";
        cout << "-------------------------------------\n";

        try {
            ArrayStack<int> emptyStack(3);
            cout << "Trying to peek from an empty stack...\n";
            cout << emptyStack.peek() << endl;
        }
        catch (string error) {
            cout << "Caught exception: " << error << endl;
        }

        try {
            ArrayStack<int> emptyStack2(3);
            cout << "Trying to pop from an empty stack...\n";
            emptyStack2.pop();
        }
        catch (string error) {
            cout << "Caught exception: " << error << endl;
        }

        try {
            ArrayStack<string> fullStack(2);
            fullStack.push("SCU");
            fullStack.push("USD");
            cout << "Trying to push onto a full stack...\n";
            fullStack.push("USC");
        }
        catch (string error) {
            cout << "Caught exception: " << error << endl;
        }

        try {
            ArrayStack<string> oneItem(3);
            oneItem.push("Tilapia");
            cout << "Trying to rotate a stack with only one element...\n";
            oneItem.rotate(Stack<string>::RIGHT);
        }
        catch (string error) {
            cout << "Caught exception: " << error << endl;
        }

        cout << "\nAll tests finished.\n";
    }
    catch (string error) {
        cout << "Unhandled exception: " << error << endl;
    }

    return 0;
}
*/