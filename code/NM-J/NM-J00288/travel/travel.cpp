#include <bits/stdc++.h>
using namespace std;
int x, y;
char s1[4], s2[4];
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%d%s%d%s", &x, s1 + 1, &y, s2 + 1);
    if ( x == y ){
        printf("1");
        if ( s1[1] == s2[1] && s1[2] == s2[2] ){
            printf("1");
            if ( (s1[3] < 'D' && s2[3] < 'D') || (s1[3] > 'C' && s2[3] > 'C') ){
                printf("1");
                if ( (s1[3] == 'A' && s2[3] == 'B') || (s1[3] == 'B' && s2[3] == 'C') || (s1[3] == 'D' && s2[3] == 'F') )
                    printf("1\n");
                else
                    printf("0\n");
            }
            else
                printf("00\n");
        }
        else
            printf("000\n");
    }
    else
        printf("0000\n");
    return 0;
}
