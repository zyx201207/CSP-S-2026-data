#include<bits/stdc++.h>
using namespace std;
char n1[10],p1[10],n2[10],p2[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s %s %s %s",n1+1,p1+1,n2+1,p2+1);
    if(n1[1]==n2[1]&&n1[2]==n2[2]){
        printf("1");
        if(p1[1]==p2[1]&&p1[2]==p2[2]){
            printf("1");
            if((p1[3]<='C'&&p2[3]<='C')||(p1[3]>='D'&&p2[3]>='D')){
                printf("1");
                if(p1[3]>=p2[3])swap(p1[3],p2[3]);
                if((p1[3]=='A'&&p2[3]=='B')||(p1[3]=='B'&&p2[3]=='C')||(p1[3]=='D'&&p2[3]=='F'))
                    printf("1");
                else printf("0");
            }else printf("00");
        }else printf("000");
    }else printf("0000");
    printf("\n");
    return 0;
}