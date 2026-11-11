#include <bits/stdc++.h>
using namespace std;

char carA[5], carB[5], codeA[5], codeB[5];

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    scanf("%s%s%s%s", carA + 1, codeA + 1, carB + 1, codeB + 1);
    if (carA[1] != carB[1] || carA[2] != carB[2])
    {
        printf("0000");
        return 0;
    }
    printf("1");
    if (codeA[1] != codeB[1] || codeA[2] != codeB[2])
    {
        printf("000");
        return 0;
    }
    printf("1");
    if ((codeA[3] > 'C' && codeB[3] <= 'C') || (codeA[3] <= 'C' && codeB[3] > 'C'))
    {
        printf("00");
        return 0;
    }
    printf("1");
    if (abs(codeA[3] - codeB[3]) != 1)
    {
        printf("0");
        return 0;
    }
    printf("1");
    return 0;
}
