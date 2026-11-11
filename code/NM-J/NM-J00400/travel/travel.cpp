#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
char a,b;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>s1>>s2;
    if(c1[0]==s1[0]&&c1[1]==s1[1])cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(c2[0]==s2[0]&&c2[1]==s2[1])cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    a=c2[2],b=s2[2];
    if(a>='A'&&a<='C'&&b>='A'&&b<='C'||a>='D'&&a<='F'&&b>='D'&&b<='F')cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if(a=='A'&&b=='B'||a=='B'&&b=='c'||a=='D'&&b=='F'||b=='A'&&a=='B'||b=='B'&&a=='c'||b=='D'&&a=='F')cout<<1;
    else cout<<0;
}
