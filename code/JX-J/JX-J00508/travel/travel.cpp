#include <bits/stdc++.h>
using namespace std;

char c1[4],s1[4],c2[4],s2[4];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",c1 + 1,s1 + 1,c2 + 1,s2 + 1);
    if (c1[1] == c2[1] && c1[2] == c2[2]){
        printf("1");
        if (s1[1] == s2[1] && s1[2] == s2[2]){
            printf("1");
            if (s1[3] - 'A' >= 0 && s1[3] - 'A' <= 2 && s2[3] - 'A' >= 0 && s2[3] - 'A' <= 2){
                printf("1");
                if (s1[3] - 'A' + 1 == s2[3] - 'A' || s1[3] - 'A' - 1 == s2[3] - 'A'){
                    printf("1");
                }
                else{
                    printf("0");
                }
            }
            else{
                if (s1[3] - 'A' >= 3 && s1[3] - 'A' <= 4 && s2[3] - 'A' >= 3 && s2[3] - 'A' <= 4){
                    printf("1");
                    if (s1[3] - 'A' + 1 == s2[3] - 'A' || s1[3] - 'A' - 1 == s2[3] - 'A'){
                        printf("1");
                    }
                    else{
                        printf("0");
                    }
                }
                else{
                    printf("00");
                    return 0;
                }
            }
        }
        else{
            printf("000");
            return 0;
        }
    }
    else{
        printf("0000");
        return 0;
    }
    return 0;
}
