/*
24. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.



Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t ft_strlen(const char *str)
{
    size_t i = 0;
    while (str && str[i])
    {
        ++i;
    }
    return i;
}

short diffCount(const char *s, size_t start, size_t end)
{
    short count = 0;
    char c = s[start];
    while (start <= end)
    {
        if (s[start] != c)
            count++;
        ++start;
    }
    return count;
}

char* ft_strdup(const char* s,size_t begin,size_t end)
{
    char *ptr = malloc((end - begin + 2) * sizeof(char));
    
    size_t i = 0;
    while (i + begin < end)
    {
        ptr[i] = s[begin + i];
        ++i;
    }
    ptr[i] = 0;
    return ptr;
}


int characterReplacement(char *s, int k)
{
    size_t len = ft_strlen(s);
    char* sub = NULL;
    int count = 0;
    size_t sub_len = 0;
    for (size_t i = 0; i < len; i++)
    {
        int diff = 0;
        size_t j = i;
        while (j < len)
        {
            diff = diffCount(s, i, j);
            if (diff <= k)
                count = diff;
            else
                break;
            ++j;
        }
        if (sub_len < j - i)
        {
            sub = ft_strdup(s,i,j);
            sub_len = j - i;
        }
    }
    printf("%s\n",sub);
    return 0;
}

int main()
{
    char * s = "AABABBA";

    characterReplacement(s,1);

    return 0;
}