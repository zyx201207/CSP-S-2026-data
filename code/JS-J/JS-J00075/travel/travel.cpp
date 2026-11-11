#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    getline(cin , s);
    if (s[0] == s[7] && s[1] == s[8])
        printf("1");
    else
        printf("0");
    if (s[0] == s[7] && s[1] == s[8])
        if (s[3] == s[10] && s[4] == s[11])
            printf("1");
         else
            printf("0");
    else
        printf("0");
    if (s[0] == s[7] && s[1] == s[8])
        if (s[3] == s[10] && s[4] == s[11])
            if ((s[5] <= 'C' && s[12] <= 'C') || (s[5] >= 'D' && s[12] >= 'D'))
                printf("1");
            else
                printf("0");
        else
            printf("0");
    else
        printf("0");

    if (s[0] == s[7] && s[1] == s[8])
        if (s[3] == s[10] && s[4] == s[11])
            if ((s[5] <= 'C' && s[12] <= 'C') || (s[5] >= 'D' && s[12] >= 'D'))
                if ((s[5] == 'C' && s[12] == 'D') || (s[5] == 'D' && s[12] == 'C') || abs((int)(s[5] - s[12])) > 1)
                    printf("0");
                else
                    printf("1");
            else
                printf("0");
        else
            printf("0");
    else
        printf("0");
    return 0;
}
