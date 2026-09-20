#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class MinStack {
public:
    MinStack() {
        m_min_value = 0;
    }
    
    void push(int value) {
        if (value < m_min_value)
        {
            // Update minimum value if this has changed
            m_min_value = value;
        }
        
        // Push to the top of the stack
        m_stack.push_back(value);
    }
    
    void pop() {
        // Remove the top element
        m_stack.pop_back();

        // Recalculate the minimum value
        const vector<int>::iterator min_val_itr = min_element(m_stack.begin(), m_stack.end());
        m_min_value = *min_val_itr;
    }
    
    int top() {
        return m_stack.back();
    }
    
    int getMin() {
        return m_min_value;
    }
private:

    /// @brief Current minimum value in the stack;
    int m_min_value;

    /// @brief Structure holding the stack. Idx 0 is the bottom of the stack
    std::vector<int> m_stack;
};

int main() {
    cout << "Running solution for Challenge 155" << endl;

    MinStack minStack;
    cout << "Pushing to stack" << endl;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    if (minStack.getMin() == -3)
    {
        cout << "getMin() correctly returned -3" << endl;
    }
    else
    {
        cout << "getMin() incorrectly returned " << minStack.getMin() << endl;
    }

    cout << "Pop the stack to remove -3; 0 should be the top now." << endl;
    minStack.pop();

    if  (minStack.top() == 0)
    {
        cout << "minStack.top() correctly returned 0" << endl;
    }
    else
    {
        cout << "top() incorrectly returned " << minStack.top() << endl;
    }

    if (minStack.getMin() == -2)
    {
        cout << "getMin() correctly returned -2" << endl;
    }
    else
    {
        cout << "getMin() incorrectly returned " << minStack.getMin() << endl;
    }

    return 0;
}