#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for(ll i=0;i<n;++i)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll ans=1;
    ll dc=0;
    ll cnt=0;
    queue<ll> q;
    ll las=0;
    for(ll i=0;i<n;++i)
    {
        dc++;
        q.push(a[i]);
        if(i==0)
        {
            las=a[i];
            continue;
        }
        cnt+=(a[i]-las)*(dc-1);
        //cout << i << ':'  << cnt << ' '<< dc << endl;
        while(cnt>m)
        {
            ll u=q.front();
            q.pop();
            cnt-=a[i]-u;
            dc--;
        }
        ans=max(ans,dc);
        las=a[i];
    }
    cout << ans;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}