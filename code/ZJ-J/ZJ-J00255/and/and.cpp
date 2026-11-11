#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+1);
    vector<vector<bool>> dg(n+1,vector<bool>(31));
    queue<ll> q;
    ll ans=0;
    for(ll i=1;i<=n;++i)
    {
        cin >> a[i];
        ll pos=0;
        ll k=a[i];
        while(k)
        {
            dg[i][pos]=k&1;
            k>>=1;
            pos++;
        }
        q.push(i);
    }
    for(ll i=29;i>=0;--i)
    {
        queue<ll> las=q;
        queue<ll>el;
        ll ok=0;
        while(!q.empty())
        {
            ll pos=q.front();
            q.pop();
            if(dg[pos][i])
            {
                ok++;
                el.push(pos);
            }
        }
        if(ok>=m)
        {
            ans+=1ll<<i;
            q=el;
        }
        else
        {
            q=las;
        }
    }
    cout << ans;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}