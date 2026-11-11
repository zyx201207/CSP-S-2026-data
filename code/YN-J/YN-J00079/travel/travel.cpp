#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int a=(c1[0]-'0')*10+c1[1]-'0',b=(c2[0]-'0')*10+c2[1]-'0';
    if (a==b)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    int c=(s1[0]-'0')*10+s1[1]-'0',d=(s2[0]-'0')*10+s2[1]-'0';
    if (c==d)
    {
        cout<<1;
        if(s1[2]=='A' && s2[2]=='B' || s1[2]=='B' && s2[2]=='A' || s1[2]=='A' && s2[2]=='C' || s1[2]=='C' && s2[2]=='A' || s1[2]=='B' && s2[2]=='C' || s1[2]=='C' && s2[2]=='B' || s1[2]=='D' && s2[2]=='E' || s1[2]=='E' && s2[2]=='D')
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(s1[2]=='A' && s2[2]=='B' || s1[2]=='B' && s2[2]=='A' || s1[2]=='B' && s2[2]=='C'|| s1[2]=='C' && s2[2]=='B' || s1[2]=='D' && s2[2]=='E'|| s1[2]=='E' && s2[2]=='D')
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
