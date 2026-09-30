#include <iostream>
#include <queue>
#include <optional>

using namespace std;

/// @brief Implement a LIFO stack
class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        m_last_val = x;
        m_stack.push(x);
    }
    
    int pop() {
        int retval;

        // Find it
        retval = find_last(true);

        return retval;
    }
    
    int top() {
        int retval;

        // Find it
        retval = find_last(false);
        
        return retval;
    }
    
    bool empty() {
        return m_stack.empty();
    }
private:
    int find_last(bool also_pop_)
    {
        std::queue<int> temp_store;

        // Work through the stack to find the last value
        for (; !m_stack.empty(); m_stack.pop())
        {
            m_last_val = m_stack.front();
            temp_store.push(m_last_val.value());
        }

        // Reconstruct the stack without the last value incase this is a pop call
        for (; !temp_store.empty(); temp_store.pop())
        {
            m_stack.push(temp_store.front());
        }        

        if (!also_pop_)
        {
            // We're not popping therefore push to the end the last value
            m_stack.push(m_last_val.value());
        }

        return m_last_val.value();        
    }

    std::queue<int> m_stack;
    optional<int> m_last_val;
};   

int main() {
    cout << "Running solution for Challenge 225" << endl;

    MyStack myStack = MyStack();
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    std::cout << "myStack.top() = " << myStack.top() << std::endl; // return 3

    return 0;
}