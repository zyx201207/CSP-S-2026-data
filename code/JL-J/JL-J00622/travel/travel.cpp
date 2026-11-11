#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if((s1[0]=='1'&&s2[0]=='1')||(s1[0]=='0'&&s2[0]=='0'))
    {
        if(s1[1]==s2[1])
        {
            cout<<"1";
        }
        else
        {
            cout<<"000";
            return 0;
        }
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(s1[2]=='D')
    {
        if(s2[2]!='F')
        {
            cout<<"00";
            return 0;
        }
        cout<<"11";
        return 0;
    }
    if(s1[2]=='F')
    {
        if(s2[2]!='D')
        {
            cout<<"00";
            return 0;
        }
        cout<<"11";
        return 0;
    }
    if(s2[2]=='F')
    {
        if(s1[2]!='D')
        {
            cout<<"00";
            return 0;
        }
        cout<<"111";
        return 0;
    }
    if(s2[2]=='D')
    {
        if(s1[2]!='F')
        {
            cout<<"00";
            return 0;
        }
        cout<<"11";
        return 0;
    }
    //D && F
    cout<<"1";
    if(s1[2]==s2[2]+1||s1[2]==s2[2]-1)
    {
        cout<<"1";
        return 0;
    }
    cout<<"0";
    return 0;
}
