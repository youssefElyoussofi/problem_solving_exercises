/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

*/

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;


class Solution {              
    private:
        unordered_map<char,char> pents;
    public:
        Solution(){
            pents[')'] = '(';
            pents[']'] = '[';
            pents['}'] = '{';
        }
        bool isValid(string s) {
            stack<char> st;  

            for (size_t i = 0; i < s.size(); ++i)
            {
                if (pents.find(s[i]) == pents.end())
                    st.push(s[i]);
                else if (!st.empty() && pents[s[i]] == st.top())
                    st.pop();
                else
                    return false;
            }
            return st.empty();
        }
};