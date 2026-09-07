/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0;i < haystack.size();++i)
        {
            string::iterator it = needle.begin();
            for (size_t j = i; haystack[j] != *haystack.end(); ++j)
            {
                if (haystack[j] != *it)
                    break;
                ++it;
            }
            if (it == needle.end())
                return i;
        }
    }
};