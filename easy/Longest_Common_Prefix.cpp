/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string f = strs[0];
        int j = 0;
        for(;j < f.size();++j)
        {
            bool found = true;
            for(int i = 1;i < strs.size();++i)
            {
                if (strs[i][j] != f[j])
                {
                    found = false;
                    break;
                }
            }
            if (found == false)
                break;
        }
        return f.substr(0,j);
    }
};