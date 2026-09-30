#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        m_array = nums;
    }
    
    int sumRange(int left, int right) {
        int retval = 0;

        for (size_t i = left; i <= right; i++)
        {
            retval += m_array[i];
        }
        

        return retval;
    }
private:
    vector<int> m_array;
};

int main() {
    cout << "Running solution for Challenge 303" << endl;

    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray = NumArray(nums);
    std::cout << numArray.sumRange(0, 2) << std::endl; // return (-2) + 0 + 3 = 1
    std::cout << numArray.sumRange(2, 5) << std::endl; // return 3 + (-5) + 2 + (-1) = -1
    std::cout << numArray.sumRange(0, 5) << std::endl; // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

    return 0;
}