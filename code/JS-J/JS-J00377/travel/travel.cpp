#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
char ans[10]="0000";
int ch[7]={1,2,3,4,0,5};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",c1,s1,c2,s2);
    if(strcmp(c1,c2)==0){
        ans[0]='1';
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            ans[1]='1';
            char f1=s1[2],f2=s2[2];
            if((f1<='C' && f2<='C') || (f1>'C' && f2>'C')){
                ans[2]='1';
                if(ch[f1-'A']==ch[f2-'A']+1 || ch[f1-'A']==ch[f2-'A']-1) ans[3]='1';
            }
        }
    }
    printf("%s",ans);
    return 0;
}
