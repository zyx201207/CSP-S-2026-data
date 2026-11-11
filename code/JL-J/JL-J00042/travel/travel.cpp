#include<iostream>
#include<cstdio>
using namespace std;
char c1[15],s1[15],c2[15],s2[15];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",c1,s1,c2,s2);
    if(c1[1]==c2[1]&&c1[0]==c2[0]){
        printf("1");
        if(s1[0]==s2[0]&&s2[1]==s1[1]){
            printf("1");
            if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<'D'&&s2[2]<'D')){
                printf("1");
                if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
                    printf("1");
                }
                else{
                    printf("0");
                }
            }
            else{
                printf("00");
            }
        }
        else{
            printf("000");
        }
    }
    else{
        printf("0000");
    }
    return 0;
}
