#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF=1e18;
inline void read(ll&a)
{
    ll cnt=0;
    ll f=1;
    char s=getchar_unlocked();
    while(!isdigit(s))
    {
        if(s=='-') f=-1;
        s=getchar_unlocked();
    }
    while(isdigit(s))
    {
        cnt=(cnt<<3)+(cnt<<1)+(s^48);
        s=getchar_unlocked();
    }
    a=cnt;
}
void solve()
{
    ll c,n,m,d,q;
    read(c);read(n);read(m);read(d);read(q);
    vector<ll> w_(m+1);
    vector<ll> k(n+1);
    vector<vector<ll>> a(n+1);
    vector<vector<ll>> t(n+1);
    vector<vector<pair<ll,ll>>> es(m+1);
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,INF));
    vector<vector<pair<ll,ll>>> sub(m+1);
    for(ll i=1;i<=m;++i)read(w_[i]);
    for(ll i=1;i<=n;++i)
    {
        dp[i][i]=0;
        read(k[i]);
        for(ll j=1;j<=k[i];++j)
        {
            ll _,__;
            read(_);read(__);
            a[i].emplace_back(_);
            t[i].emplace_back(__);
            sub[_].emplace_back(i,__);
        }
    }
    for(ll i=1;i<=m;++i)
        for(ll f=0;f<sub[i].size();++f)
            for(ll p=0;p<sub[i].size();++p)
            {
                if(f==p)continue;
                dp[sub[i][f].first][sub[i][p].first]=min(dp[sub[i][f].first][sub[i][p].first],sub[i][f].second+sub[i][p].second);
                dp[sub[i][p].first][sub[i][f].first]=min(dp[sub[i][p].first][sub[i][f].first],sub[i][f].second+sub[i][p].second);
            }
    for(ll k=1;k<=n;++k)
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
    while(q--)
    {
        ll s,t;
        read(s);read(t);
        ll ans=INF;
        for(ll f=0;f<sub[s].size();++f)
            for(ll p=0;p<sub[t].size();++p)
            {
                ans=min(ans,dp[sub[s][f].first][sub[t][p].first]+sub[t][p].second+sub[s][f].second);
            }
        printf("%lld",w_[s]+w_[t]+ans);
        puts("");
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    solve();
}