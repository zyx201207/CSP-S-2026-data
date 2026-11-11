#include <bits/stdc++.h>
using namespace std;

char s1[3],s2[4],s3[3],s4[4];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    scanf("%s",s3+1);
    scanf("%s",s4+1);
    if(s1[1]==s3[1]&&s1[2]==s3[2]){
        printf("1");
        if(s2[1]==s4[1]&&s2[2]==s4[2]){
            printf("1");
            if((s2[3]=='A'&&s4[3]=='B')||(s2[3]=='B'&&s4[3]=='A')){
                printf("11");
            }
            else
                if((s2[3]=='B'&&s4[3]=='C')||(s2[3]=='C'&&s4[3]=='B')){
                    printf("11");
                }
                else
                    if((s2[3]=='A'&&s4[3]=='C')||(s2[3]=='C'&&s4[3]=='A')){
                        printf("10");
                    }
                    else
                        if((s2[3]=='D'&&s2[3]=='E')||(s2[3]=='E'&&s4[3]=='D')){
                            printf("11");
                        }
                        else
                            printf("00");
        }
        else
            printf("000");
    }
    else
        printf("0000");
    return 0;
}
