#include <bits/stdc++.h>
using namespace std;

#define int long long 

constexpr int maxn = 10;
constexpr int maxk = 256;

char c1[maxn], s1[maxn], c2[maxn], s2[maxn];

int convert[maxk];

signed main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    scanf("%s%s%s%s", c1, s1, c2, s2);

    convert['A'] = 1;
    convert['B'] = 1;
    convert['C'] = 1;
    convert['D'] = 2;
    convert['F'] = 2;

    if(strcmp(c1, c2) == 0)
    {
        putchar('1');
        if(s1[0] == s2[0] && s1[1] == s2[1])
        {
            putchar('1');
            if(convert[s1[2]] == convert[s2[2]])
            {
                putchar('1');
                if(s1[2] > s2[2]) swap(s1[2], s2[2]);
                if(s1[2] == 'D' && s2[2] == 'F') 
                {
                    putchar('1');
                }
                else if(s1[2] == 'B' && s2[2] == 'C')
                {
                    putchar('1');
                }
                else if(s1[2] == 'A' && s2[2] == 'B')
                {
                    putchar('1');
                }
                else putchar('0');
            }
            else printf("00");
        }
        else printf("000");
    }
    else printf("0000");

    return 0;
}