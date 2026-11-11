#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0] && c1[1]==c2[1])
    {
        cout<<1;
    }
    if(c1[0]!=c2[0] || c1[1]!=c2[1])
    {
        cout<<"0000"<<endl;
        return 0;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1])
    {
        cout<<1;
    }
    if(s1[0]!=s2[0] || s1[1]!=s2[1])
    {
        cout<<"000"<<endl;
        return 0;
    }
    if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A') || (s1[2]=='C' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D'))
    {
        cout<<"11"<<endl;
        return 0;
    }
    if((s1[2]=='A' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='A'))
    {
        cout<<"10"<<endl;
        return 0;
    }
    cout<<"00"<<endl;
    return 0;
}
