#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2;
char s1[5],s2[5],tmp[5];
int ty[5]={0,0,0,1,1};
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s",tmp);
    c1=(tmp[0]-'0')*10+tmp[1]-'0';
    scanf("%s",s1+1);
    scanf("%s",tmp);
    c2=(tmp[0]-'0')*10+tmp[1]-'0';
    scanf("%s",s2+1);
    putchar((c1==c2)+'0');
    putchar((c1==c2 and s1[2]==s2[2] and s1[1]==s2[1])+'0');
    putchar((c1==c2 and s1[2]==s2[2] and s1[1]==s2[1] and (s1[3]>'C'==s2[3]>'C'))+'0');
    putchar((c1==c2 and s1[2]==s2[2] and s1[1]==s2[1] and (s1[3]>'C'==s2[3]>'C') and (abs(s1[3]-s2[3])==1) or (s1[3]=='D' and s2[3]=='F' ) or (s2[3]=='D' and s1[3]=='F' ))+'0');
    return 0;
}