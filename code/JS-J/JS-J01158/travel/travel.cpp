#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    long long a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b)
    {
        cout<<1;
        if(c[0]==d[0]&&c[1]==d[1])
        {
            cout<<1;
            if(c[2]<=67&&d[2]<=67)
            {
                cout<<1;
                if(c[2]+1==d[2]||c[2]-1==d[2])
                    cout<<1;
                else
                    cout<<0;
            }
            else if(c[2]>67&&d[2]>67)
            {
                cout<<1;
                if(c[2]+2==d[2]||c[2]-2==d[2])
                    cout<<1;
                else
                    cout<<0;
            }
            else
                cout<<0<<0;
        }
        else
            cout<<0<<0<<0;
    }
    else
        cout<<0<<0<<0<<0;
    return 0;
}
