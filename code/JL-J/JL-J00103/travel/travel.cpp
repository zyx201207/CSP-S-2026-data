#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >>c1>>s1>>c2>>s2;
    bool cx=1,p=1;
    for(int i=0;c1[i]!='\0';i++)if(c1[i]!=c2[i])cx=0;
    if(cx)cout<<1;
    else cout<<0;
    for(int i=0;i<2;i++)if(s1[i]!=s2[i])p=0;
    if(p&&cx)cout<<1;
    else cout<<0;
    bool c=((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F'));
    if(cx&&p&&c)cout<<1;
    else cout<<0;
    bool z=((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'));
    if(cx&&p&&z)cout<<1;
    else cout<<0;
}
