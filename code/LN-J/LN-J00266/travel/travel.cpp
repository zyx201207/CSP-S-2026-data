#include<bits/stdc++.h>
using namespace std;
bool bf=1;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    char a=s1[2],b=s2[2];
    s1.erase(2,1);
    s2.erase(2,1);
    if(c1==c2 && bf==1) cout<<1;
    else
    {
        cout<<0;
        bf=0;
    }
    if(s1==s2 && bf==1) cout<<1;
    else
    {
        cout<<0;
        bf=0;
    }
    if((a<='C'&&b<='C' || a>='D'&&b>='D') && bf==1) cout<<1;
    else
    {
        cout<<0;
        bf=0;
    }
    if((a=='A'&&b=='B' || a=='B'&&b=='C' || a=='B'&&b=='A' || a=='C'&&b=='B' || a=='D'&&b=='F' || a=='F'&&b=='D') && bf==1) cout<<1;
    else cout<<0;
    return 0;
}
