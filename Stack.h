#ifndef STACK_H
#define STACK_H
using namespace std;

#include <vector>
#include <stdexcept>

class Stack {
private:
    std::vector<int> data;

public:
    void push(int value);
    bool pop();
    int top() const;
    bool isEmpty() const;
    double average() const;
};

#endif // STACK_H
