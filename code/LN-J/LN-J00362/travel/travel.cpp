#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    bool n=1;
    for(int i=0;i<2;i++)
    {
        if(b[i]!=d[i])
        {
            cout<<"000";
            n=0;
            break;
        }
    }
    if(n==1)
    {
        cout<<"1";
        if(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D')
        {
            cout<<"1";
        }
        else
        {
            if(b[2]!='D'&&b[2]!='F'&&d[2]!='D'&&d[2]!='F')
            {
                cout<<"1";
            }
            else
            {
                cout<<"0";
            }
        }
        if(b[2]+1==d[2]||b[2]-1==d[2]||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D')
        {
            if(b[2]=='C'&&d[2]=='D'||b[2]=='D'&&d[2]=='C')
            {
                cout<<"0";
            }
            else
            {
                cout<<"1";
            }
        }
        else
        {
            cout<<"0";
        }
    }
    return 0;
}
