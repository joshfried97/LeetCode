#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int retval = 1;
        int current_sum = 1;
        const int string_len = s.length();
        string sub_string("");
        sub_string.push_back(s[0]);
        vector<string> sub_string_vector;
        sub_string_vector.push_back(sub_string);

        // We will always start at the second character as the minimum the answer can always be is 1
        // due to the starting character
        for (size_t i = 1; i < string_len; i++)
        {
            const char current_character = s[i];
            const bool char_not_in_sub_string = (sub_string.find(current_character) == string::npos);
            if (char_not_in_sub_string)
            {
                // Build the substring
                sub_string.push_back(current_character);

                current_sum++;
                if (current_sum > retval)
                {
                    retval = current_sum;
                }                
            }
            else
            {
                // We now have a repeated character therefore we store this substring and reset
                sub_string_vector.push_back(sub_string);
                sub_string = "";
                current_sum = 0;
            }
        }

        return retval;
    }
};

int main() {
    cout << "Running solution for Challenge 3" << endl;

    Solution solution;

    string test_case_1 = "abcabcbb";
    const int test_case_1_res = solution.lengthOfLongestSubstring(test_case_1);
    cout << "Test case 1 result = " << test_case_1_res << endl;

    string test_case_2 = "bbbbb";
    const int test_case_2_res = solution.lengthOfLongestSubstring(test_case_2);
    cout << "Test case 2 result = " << test_case_2_res << endl;

    string test_case_3 = "pwwkew";
    const int test_case_3_res = solution.lengthOfLongestSubstring(test_case_3);
    cout << "Test case 3 result = " << test_case_3_res << endl;

    return 0;
}