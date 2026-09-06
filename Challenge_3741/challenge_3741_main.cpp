#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int retval = -1;
        int num_elem = nums.size();

        // Find values in the array with 3 instances
        vector<int> val_with_3_instances;
        for (int idx = 0; idx < num_elem; idx++) {
            int val = nums[idx];
            
            // Determine whether we've already processed this value 
            const bool already_processed = (find(val_with_3_instances.begin(), val_with_3_instances.end(), val) != val_with_3_instances.end());

            if ((count(nums.begin(), nums.end(), val) == 3) && !already_processed) {
                // If there are 3 instances of it and we've not processed this value then crack on
                const int i = idx;
                const int j = distance(nums.begin(), find(nums.begin() + i + 1, nums.end(), val));
                const int k = distance(nums.begin(), find(nums.begin() + j + 1, nums.end(), val));

                const int dist = abs(i - j) + abs(j - k) + abs(k - i);

                if (retval == -1) {
                    // First time being assigned so assign regardless
                    retval = dist;
                } else {
                    retval = std::min(retval, dist);
                }

                // Remember which when we've found a value with 3 occurrences
                val_with_3_instances.push_back(val);                
            }
        }

        return retval;
    }
};

int main() {
    cout << "Running solution for Challenge 3741" << endl;

    Solution solution;

    vector<int> test_case_1 = {1,2,1,1,3};
    const int test_case_1_res = solution.minimumDistance(test_case_1);
    cout << "Test case 1 result = " << test_case_1_res << endl;

    vector<int> test_case_2 = {1,1,2,3,2,1,2};
    const int test_case_2_res = solution.minimumDistance(test_case_2);
    cout << "Test case 2 result = " << test_case_2_res << endl;

    vector<int> test_case_3 = {1};
    const int test_case_3_res = solution.minimumDistance(test_case_3);
    cout << "Test case 3 result = " << test_case_3_res << endl;

    return 0;
}