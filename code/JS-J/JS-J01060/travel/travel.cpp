#include <bits/stdc++.h>
using namespace std;
string a1,s1,a2,s2;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a1 >> s1 >> a2 >> s2;
    if(a1[0] == a2[0] && a1[1] == a2[1])
    {
        printf("1");
        if(s1[0] == s2[0] && s1[1] == s2[1])
        {
            printf("1");
            if((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C'))
            {
                printf("00\n");
            }
            else
            {
                printf("1");
                if(abs((int)s1[2] - (int)s2[2]) == 1 || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))
                {
                    printf("1\n");
                }
                else
                {
                    printf("0\n");
                }
            }
        }
        else
        {
            printf("000\n");
        }
    }
    else
    {
        printf("0000\n");
    }
    return 0;
}
