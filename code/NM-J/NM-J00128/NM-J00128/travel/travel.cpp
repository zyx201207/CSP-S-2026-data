#include <bits/stdc++.h>
using namespace std;

string a,b,c,d;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    bool flag=true;
    for(int i=0;i<2;i++)
    {
        if(a[i]!=c[i]) flag=false;
    }
    if(flag)
    {
        cout<<1;
        bool flak=true;
        for(int i=0;i<2;i++)
        {
            if(b[i]!=d[i]) flak=false;
        }
        if(flak)
        {
            cout<<1;
            if(b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D')
            {
                cout<<1;
                if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='B'||b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D')
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
                cout<<0<<0;
            }
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;

    return 0;
}
