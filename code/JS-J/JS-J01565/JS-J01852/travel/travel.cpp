#include <bits/stdc++.h>
using namespace std;
char r[5],x[5];
char sr[10],sx[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=2;i++)
        cin>>r[i];
    for(int i=1;i<=3;i++)
        cin>>sr[i];
    for(int i=1;i<=2;i++)
        cin>>x[i];
    for(int i=1;i<=3;i++)
        cin>>sx[i];
    if(r[1]==x[1]&&r[2]==x[2])
        cout<<1;
    else cout<<0;
    if(r[1]==x[1]&&r[2]==x[2]&&sr[1]==sx[1]&&sr[2]==sx[2])
        cout<<1;
    else cout<<0;
    bool flag=0;
    if(r[1]==x[1]&&r[2]==x[2]&&sr[1]==sx[1]&&sr[2]==sx[2])
    {
        if(sr[3]=='D'&&sx[3]=='F'||(sr[3]=='F'&&sx[3]=='D'))
        {
            cout<<1;
            flag=1;
        }
        if(sr[3]=='A')
        {
            if(sx[3]=='B'||sx[3]=='C')
            {
                cout<<1;flag=1;
            }
        }
        if(sr[3]=='B')
        {
            if(sx[3]=='A'||sx[3]=='C')
            {
                cout<<1;flag=1;
            }
        }
        if(sr[3]=='C')
        {
            if(sx[3]=='B'||sx[3]=='A')
            {
                cout<<1;flag=1;
            }
        }
    }
    if(flag==0)cout<<0;
    bool flag2=0;
    if(r[1]==x[1]&&r[2]==x[2]&&sr[1]==sx[1]&&sr[2]==sx[2])
    {
        if(sr[3]=='D'&&sx[3]=='F'||(sr[3]=='F'&&sx[3]=='D'))
        {
            cout<<1;
            flag2=1;
        }
        if(sr[3]=='A')
        {
            if(sx[3]=='B')
            {
                cout<<1;flag2=1;
            }
        }
        if(sr[3]=='B')
        {
            if(sx[3]=='A'||sx[3]=='C')
            {
                cout<<1;flag2=1;
            }
        }
        if(sr[3]=='C')
        {
            if(sx[3]=='B')
            {
                cout<<1;flag2=1;
            }
        }
    }
    if(flag2==0)cout<<0;
    return 0;
}
