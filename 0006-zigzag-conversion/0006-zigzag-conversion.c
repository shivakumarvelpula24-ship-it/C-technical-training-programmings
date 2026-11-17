#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows)
{
    int n = strlen(s);

    if(numRows == 1 || numRows >= n)
        return s;

    char* result = (char*)malloc(n + 1);
    int k = 0;

    for(int row = 0; row < numRows; row++)
    {
        int step1 = 2 * (numRows - row - 1);
        int step2 = 2 * row;

        int i = row;

        while(i < n)
        {
            result[k++] = s[i];

            int step;

            if(row == 0)
                step = step1;
            else if(row == numRows - 1)
                step = step2;
            else
                step = (i - row) % (step1 + step2) == 0
                       ? step1 : step2;

            if(step == 0)
                break;

            i += step;
        }
    }

    result[k] = '\0';
    return result;
}