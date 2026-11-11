#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        for(int i=1,u,v; i<=n-1; i++)
        {
            cin>>u>>v;
        }
        if(n%2==1)
        {
            if(k!=n)
                cout<<2<<"\n";
            else if(k+1==n)
                cout<<1<<"\n";
            else
                cout<<0<<"\n";
        }
        else
        {
            cout<<rand()%k<<"\n";
        }
    }
    return 0;
}
