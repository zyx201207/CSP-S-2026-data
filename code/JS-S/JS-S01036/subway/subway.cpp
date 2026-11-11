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
int c,n,m,d,q,k,x,y;
int idx;ll wt;
ll dis[505][505];
ll w[500005];
vector<pair<int,ll> > Q[500005];
int main()
{
    #ifndef DEBUG
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    rep1(i,m) cin>>w[i];
    rep1(i,n)
    {
        cin>>k;
        rep1(j,k)
        {
            cin>>idx>>wt;Q[idx].pb(mp(i,wt));
        }
    }
    memset(dis,0x3f,sizeof(dis));rep1(i,n) dis[i][i]=0;
    rep1(i,m)
    {
        rep(j,Q[i].size()) rep(tk,j)
        {
            pair<int,ll> P1=Q[i][j],P2=Q[i][tk];
            dis[P1.fi][P2.fi]=min(dis[P1.fi][P2.fi],P1.se+P2.se);
        }
    }
    rep1(i,n) rep1(j,n) dis[i][j]=min(dis[i][j],dis[j][i]);
    rep1(tk,n) rep1(i,n) if(i!=tk) rep1(j,n) dis[i][j]=min(dis[i][j],dis[i][tk]+dis[tk][j]);
    rep1(i,q)
    {
        cin>>x>>y;
        ll ans=0x3f3f3f3f3f3f3f3fll;
        for(pair<int,ll>P1:Q[x]) for(pair<int,ll>P2:Q[y])
        {
            ans=min(ans,dis[P1.fi][P2.fi]+P1.se+P2.se);
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0; 
}
/*
_i__e: _i__ ___ re_e__er _e
__i_ i_ _ _e__ __ere ___ _e__er_ e__e__ __e_e _r__ __e __r_ "reviver" _re re____e_ __ ___er_i_e_.
__r e_____e, __r__ _i_e "river" _re_'_ _____e_, ___ __r__ _i_e "____" _i____e_r.
___e ___ ___ re__ver __i_ _e__.
*/