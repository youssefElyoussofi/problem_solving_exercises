/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // vector<string> strs;
        int length = 0;

        string test;
        int i = 0;
        while(i < s.size())
        {
            for (size_t j = i; j < s.size(); ++j)
            {
                if (test.find(s[j]) == string::npos)
                    test.push_back(s[j]);
                else
                    break;
            }
            // strs.push_back(test);
            if (test.size() > length)
                length = test.size();
            test.clear();
            ++i;
        }
        // int length = 0;
        // for (size_t i = 0; i < strs.size(); i++)
        // {
        //     if (strs[i].size() > length)
        //         length = strs[i].size();
        // }
        return length;
    }
};

int main()
{
    Solution s;

    s.lengthOfLongestSubstring("abcabcbb");

    return 0;
}