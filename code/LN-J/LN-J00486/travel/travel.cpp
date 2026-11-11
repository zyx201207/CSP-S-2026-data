#include <bits/stdc++.h>
using namespace std;

char c1[11],s1[11],c2[11],s2[11];
int b1=0,b2=0,b3=0,b4=0;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s",c1+1);
    scanf("%s",s1+1);
    scanf("%s",c2+1);
    scanf("%s",s2+1);
    if(c1[1]==c2[1]&&c1[2]==c2[2])
        b1=1;
    if(b1){
        if(s1[1]==s2[1]&&s1[2]==s2[2])
                b2=1;
        if(b2){
            if((s1[3]>='A'&&s1[3]<='C')&&(s2[3]>='A'&&s2[3]<='C'))
                b3=1;
            else if((s1[3]>='D'&&s1[3]<='E')&&(s2[3]>='D'&&s2[3]<='E'))
                b3=1;
            if(b3){
                if(abs(s1[3]-s2[3])==1)
                        b4=1;
            }
        }
    }
    printf("%d%d%d%d",b1,b2,b3,b4);
}
