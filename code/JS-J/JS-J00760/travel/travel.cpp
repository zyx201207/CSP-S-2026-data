#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        exit(0);
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        exit(0);
    }
    char a=s1[2],b=s2[2];
    if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='F'&&b>='D'&&b<='F'))
    {
        cout<<1;
    }
    else
    {
        cout<<"00";
        exit(0);
    }
    if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='D'&&b=='F')||(a=='F'&&b=='D'))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
