#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
using ll=long long;
ll c,n,m,d,q,dp[N][N],w[M];
using pii=pair<ll,ll>;
#define mk make_pair
#define fi first
#define se second
vector<ll> a[N],t[N];
vector<pii> v[M];
#define pb emplace_back
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;memset(dp,0x3f,sizeof(dp));
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(ll i=1,k;i<=n;i++){
        cin>>k;
        while(k--){ll x,y;cin>>x>>y;a[i].pb(x);t[i].pb(y);v[x].pb(mk(i,y));}
    }
    for(ll i=1;i<=n;i++){
        for(ll k=0,z;k<a[i].size();k++){
            z=t[i][k];
            for(pii p:v[a[i][k]]){
                ll j=p.fi;
                if(i!=j) dp[i][j]=min(dp[i][j],z+p.se);
            }
        }
    }
    for(ll i=1;i<=n;i++) dp[i][i]=0;
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        }
    }
    while(q--){
        ll x,y,ans=2e18;
        cin>>x>>y;
        for(pii pi:v[x]){
            for(pii pj:v[y]) ans=min(ans,dp[pi.fi][pj.fi]+pi.se+pj.se);
        }
        ans+=w[x]+w[y];cout<<ans<<'\n';
    }
    return 0;
}