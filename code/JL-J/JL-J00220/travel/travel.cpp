#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s[1]>>s[2]>>s[3]>>s[4];
        if(s[1]==s[3]) cout<<1;//cx
        else{cout<<"0000";return 0;}
    string p1="", p2="";char t1,t2;
    p1+=s[2][0],p1+=s[2][1],t1=s[2][2],p2+=s[4][0],p2+=s[4][1],t2=s[4][2];//tp
    if(p1==p2) cout<<1;
    else cout<<0;
        int s1=t1-'A'-3,s2=t2-'A'-3;
        s1==0?s1=2:s1;
        s2==0?s2=2:s2;
        if(p1==p2&&s1*s2>0) cout<<1;
        else cout<<0;
    if(p1==p2&&abs(s1-s2)==1) cout<<1;
    else cout<<0;
    return 0;
}
