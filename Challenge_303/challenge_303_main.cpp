#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        // Pre compute the totals when you construct the class
        const int num_elem = nums.size();
        m_sum_array.resize(num_elem);
        m_sum_array[0] = nums[0];
        for (size_t i = 1; i < num_elem; i++)
        {
            int sum = m_sum_array[i-1] + nums[i];
            m_sum_array[i] += sum;
        }
    }
    
    int sumRange(int left, int right) {
        int retval = 0;
        if (left == 0)
        {
            retval = m_sum_array[right];
        }
        else
        {
            retval = m_sum_array[right] - m_sum_array[left - 1];
        }
        
        return retval;
    }
private:
    vector<int> m_sum_array;
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