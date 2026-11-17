char* longestPalindrome(char* s)
{
    int n = strlen(s);
    int max = 1;
    int start = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int left = i;
            int right = j;
            int flag = 1;

            while(left < right)
            {
                if(s[left] != s[right])
                {
                    flag = 0;
                    break;
                }

                left++;
                right--;
            }

            if(flag && (j - i + 1) > max)
            {
                max = j - i + 1;
                start = i;
            }
        }
    }

    s[start + max] = '\0';

    return s + start;
}