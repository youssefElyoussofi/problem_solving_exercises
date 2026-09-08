/*
Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t ft_strlen(const char* str)
{
    size_t i = 0;
    while (str && str[i])
    {
        ++i;
    }
    return i;
}

short isPlindrom(const char* s, size_t start,size_t end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return 0;
        ++start;
        --end;
    }
    return 1;
}

char* ft_strdup(const char* s,size_t begin,size_t end)
{
    char *ptr = malloc((end - begin + 2) * sizeof(char));
    
    size_t i = 0;
    while (i + begin <= end)
    {
        ptr[i] = s[begin + i];
        ++i;
    }
    ptr[i] = 0;
    return ptr;
}

char* longestPalindrome(char* s)
{
    size_t len = ft_strlen(s);
    size_t size = 0;
    char *longest = NULL;

    for (size_t i = 0; i < len; ++i)
    {
        for (size_t j = len - 1; j >= i; --j)
        {
            if (isPlindrom(s,i,j))
            {
                if (j - i + 1 > size)
                {
                    size = j - i + 1;
                    longest = ft_strdup(s,i,j);
                }
            }
            if (i - j < size)
                break;
        }
        if (len - i < size)
            break;
    }
    return longest;
}


int main()
{
    char *ptr = "a";

    printf("%s\n",longestPalindrome(ptr));

    return 0;
}