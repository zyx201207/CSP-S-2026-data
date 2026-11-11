#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF=1e18;
ll types;
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
        ll n,d;
        read(n);read(d);
        vector<ll> x(n+1);
        vector<ll> ws(n+1);
        vector<vector<ll>> dp(n+1,vector<ll>(n+1,INF));
        vector<vector<ll>> ct(n+1,vector<ll>(n+1,INF));
        for(ll i=1;i<=n;++i)
        {
            dp[i][i]=0;
            read(x[i]);
            for(ll j=1;j<i;++j)
                if(x[i]-x[j]<=d)
                {
                    dp[i][j]=1;
                    dp[j][i]=1;
                }
        }
        for(ll k=1;k<=n;++k)
            for(ll i=1;i<=n;++i)
                for(ll j=1;j<=n;++j)
                {
                    if(dp[i][j]>dp[i][k]+dp[k][j])
                    {
                        ct[i][j]=0;
                        dp[i][j]=dp[i][k]+dp[k][j];
                    }
                    else if(dp[i][j]==dp[i][k]+dp[k][j]) ct[i][j]++;
                }
        ll ans=0;
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j)
                ans+=(ct[i][j]==2);
        printf("%lld",(ans>>1));
        puts("");
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll t;
    read(types);
    read(t);
    while(t--)
    solve();
}