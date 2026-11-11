#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>c1>>s1>>c2>>s2;
    bool flag1=false,flag2=false,flag3=false;
    if(c1[0]==c2[0]&&c1[1]==c2[1])cout<<1,flag1=true;
    else cout<<0;
    if(flag1&&(s1[0]==s2[0]&&s1[1]==s2[1]))cout<<1,flag2=true;
    else cout<<0;
    if(flag2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s1[2]<='F'&&s2[2]>'C'&&s2[2]<='F')))cout<<1,flag3=true;
    else cout<<0;
    int x=s1[2]-'A'+1,y=s2[2]-'A'+1;
    if(flag3&&(x==y-1||x==y+1||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))cout<<1;
    else cout<<0;
    return 0;
}
