#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char x,y;
    cin>>a>>b>>x>>c>>d>>y;
    if(a!=c)
    {
        cout<<0<<0<<0<<0;
    }
    else
    {
        cout<<1;
        if(b!=d)
        {
            cout<<0<<0<<0;
        }
        else
        {
            cout<<1;
            if(y>x)
            {
                swap(x,y);
            }
            if(x=='F')
            {
                if(y=='D')
                {
                    cout<<1<<1;
                }
                else
                {
                    cout<<0<<0;
                }
            }
            else if(x=='D')
            {
                cout<<0<<0;
            }
            else if(x=='C')
            {
                if(y=='B')
                {
                    cout<<1<<1;
                }
                else
                {
                    cout<<1<<0;
                }
            }
            else
            {
                cout<<1<<1;
            }
        }
    }
    return 0;
}
