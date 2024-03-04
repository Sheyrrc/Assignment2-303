#include "Stack.h"
#include <iostream>
using namespace std;

void Stack::push(int value) {
    data.push_back(value);
}

bool Stack::pop() {
    if (data.empty()) {
        return false;
    }
    data.pop_back();
    return true;
}

int Stack::top() const {
    if (data.empty()) {
        throw out_of_range("Stack is empty.");
    }
    return data.back();
}

bool Stack::isEmpty() const {
    return data.empty();
}

double Stack::average() const {
    if (data.empty()) {
        throw out_of_range("Stack is empty.");
    }
    double sum = 0;
    for (int value : data) {
        sum += value;
    }
    return sum / data.size();
}
