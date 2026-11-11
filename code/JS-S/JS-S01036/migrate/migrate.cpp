#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,del##i##verme=int(n);i<del##i##verme;++i)
#define rep1(i,n) for(int i=1,parano##i##a=int(n);i<=parano##i##a;++i)
#define per(i,n) for(int i=int(n)-1;i>=0;--i)
#define per1(i,n) for(int i=int(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
const ll mod1=998244353;
const ll mod2=1000000007;
using namespace std;
unsigned time_related_rand()
{
    return unsigned(std::chrono::steady_clock::now().time_since_epoch().count());
}
int c,t;
int n;ll d;
ll x[2000005];
int L[2000005],R[2000005];
int sl[2000005],sr[2000005];
int vl[2000005],vr[2000005];
ll ans;
int calcl(int u,int v)
{
    int st=sl[v]-(R[u]==v);
    if(L[u]!=u&&R[L[u]]==v) st+=vl[L[u]];
    return st;
}
int calcr(int u,int v)
{
    int st=sr[u]-(L[v]==u);
    if(R[v]!=v&&L[R[v]]==u) st+=vr[R[v]];
    return st;
}
void Q()
{
    cin>>n>>d;
    rep1(i,n) cin>>x[i];
    int to=1;
    rep1(i,n)
    {
        while(x[i]-x[to]>d) ++to;
        L[i]=to;
    }
    to=n;
    per1(i,n)
    {
        while(x[to]-x[i]>d) --to;
        R[i]=to;
    }
    rep1(i,n) sl[i]=sr[i]=0;
    rep1(i,n)
    {
        if(R[i]!=i) ++sl[R[i]];
        if(L[i]!=i) ++sr[L[i]];
    }
    rep1(i,n)
    {
        vl[i]=sl[i];
        if(L[i]!=i&&R[L[i]]==i) vl[i]+=vl[L[i]];
    }
    per1(i,n)
    {
        vr[i]=sr[i];
        if(R[i]!=i&&L[R[i]]==i) vr[i]+=vr[R[i]];
    }
    ans=0;
    rep1(i,n-1)
    {
        int j=i+1;
        ans+=calcl(i,j)*1ll*calcr(i,j);
    }
    cout<<ans<<'\n';
}
int main()
{
    #ifndef DEBUG
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>c>>t;while(t--)Q();
    return 0;
}
/*
_i__e: _i__ ___ re_e__er _e
__i_ i_ _ _e__ __ere ___ _e__er_ e__e__ __e_e _r__ __e __r_ "reviver" _re re____e_ __ ___er_i_e_.
__r e_____e, __r__ _i_e "river" _re_'_ _____e_, ___ __r__ _i_e "____" _i____e_r.
___e ___ ___ re__ver __i_ _e__.
*/