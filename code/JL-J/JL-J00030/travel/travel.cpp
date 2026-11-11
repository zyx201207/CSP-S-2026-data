#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out""w",stdout);
    int a,m;
    string b,n;
    cin>>a;
    for(int i=0;i<3;i++)
    {
        cin>>b[i];
    }
    cin>>m;
    for(int i=0;i<3;i++)
    {
        cin>>n[i];
    }
    string s;
    if(a==m)
    {
        if(b[0]==n[0]&&b[1]==n[1])
        {
            if(b[2]=='C'&&n[2]=='D'||b[2]=='D'&&n[2]=='C')
            {
                s="1100";
            }
            else
            {
                if(b[2]+1==n[2]||b[2]-1==n[2])
                {
                    s="1111";
                }
                else
                {
                    s="1110";
                }
            }
        }
        else
        {
            s="1000";
        }
    }
    else
    {
        s="0000";
    }
    cout<<s;
    return 0;
}

