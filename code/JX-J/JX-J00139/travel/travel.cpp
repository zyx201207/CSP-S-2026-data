#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10];
int s,c;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;

   if(c1[0]==c2[0]&&c1[1]==c2[1]){
        printf("1");
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            printf("1");
            if(s1[2]=='D'&&s2[2]=='F'){
                printf("11");
            }
            else if((s1[2]=='B'||s1[2]=='C'||s1[2]=='A')&&(s2[2]=='B'||s2[2]=='C'||s2[2]=='A')){
                printf("1");
                if(int(s1[2]-s2[2])==1||int(s1[2]-s2[2])==-1){
                    printf("1");
                }
                else printf("0");
            }
            else printf("00");
        }
        else printf("000");
    }
    else printf("0000");
    return 0;
}

