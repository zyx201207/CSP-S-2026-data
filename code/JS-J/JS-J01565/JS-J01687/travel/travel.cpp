#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int smax,smin;
int main()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    bool flag=1;
    for(int i=0;i<=1;i++)
    {
        if(s1[i]!=s2[i])
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        cout<<1;
        if(s1[2]-'0'>s2[2]-'0')
        {
            smax=s1[2]-'0';
            smin=s2[2]-'0';
        }
        else
        {
            smax=s2[2]-'0';
            smin=s1[2]-'0';
        }
        if((smax<='C'-'0')||(smin>='D'-'0'))
        {
            cout<<1;
            if(smax-smin==1)
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
            cout<<"00";
        }
    }
    else
    {
        cout<<"000";
    }
    return 0;
}
