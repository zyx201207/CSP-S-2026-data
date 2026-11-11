#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500100],b[500100],g=1;
void solve()
{
    cin>>n>>m;
    for(ll i=1; i<=n; i++)
    {
        cin>>a[i];
        if(i>=4&&abs(a[i]-a[i-1])!=abs(a[i-2]-a[i-3]))
        {
            g=0;
        }
    }
    if(g==1)
    {
        if(m>=abs(a[1]-a[2])&&abs(a[1]-a[2])!=1)
        {
            cout<<floor(m/abs(a[1]-a[2]))+1;
            return;
        }
    }
    sort(a+1,a+n+1);
    a[1]+=m;
    for(ll i=1; i<=n; i++)
    {
        b[i]=b[i-1]+a[i];
    }
    for(ll i=n; i>=1; i--)
    {
        if(ceil(b[i]/i)>=a[i])
        {
            cout<<i;
            return;
        }
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    solve();
    return 0;
}
