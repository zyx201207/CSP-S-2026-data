#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        printf("1");
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            printf("1");
            char s = s1[2], t = s2[2];
            if ((s < 'D' && t < 'D') || (s >= 'D' && t >= 'D')) {
                printf("1");
                if ((s == 'D' && t == 'F') || (s == 'F' && t == 'D') || s - t == 1 || s - t == -1)
                    printf("1");
                else
                    printf("0");
            }
            else
                printf("00");
        }
        else
            printf("000");
    }
    else
        printf("0000");

}
