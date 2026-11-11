#include <bits/stdc++.h>
using namespace std;

char c1[3],s1[5],c2[3],s2[5];
char a[5];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",c1,s1,c2,s2);
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        a[0]=1;
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        a[1]=1;
        if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                a[2]=1;
            }
        }
        else{
            if(s2[2]=='D'||s2[2]=='F')
                a[2]=1;
        }
    }
    }
    if(a[2]==1){
    if(s1[2]=='A'&&s2[2]=='B'){
            a[3]=1;
    }
    else{
        if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
                a[3]=1;
        }
        else{
            if(s1[2]=='C'&&s2[2]=='B'){
                    a[3]=1;
            }
            else{
                if(s1[2]=='D'&&s2[2]=='F')
                    a[3]=1;
                else{
                    if(s1[2]=='F'&&s2[2]=='D')
                        a[3]=1;
                }
            }
        }
        }
    }
    for(int i=0;i<=3;i++)
        printf("%d",a[i]);
    return 0;
}
