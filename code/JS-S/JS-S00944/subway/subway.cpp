#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+9,L=1e5+9,M=509,D=25;
const ll INF=1e18;
ll c,n,m,d,q,wt[N],dis[M][M],cnt[N];
pair<ll,ll>st[N][D];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(register ll i=1;i<=m;++i)cin>>wt[i];
    for(register ll i=1,sz;i<=n;++i){
        cin>>sz;
        while(sz--){
            ll a,t;
            cin>>a>>t;
            st[a][++cnt[a]]={i,t};
        }
    }
    for(register int i=1;i<=n;++i){
        for(register int j=1;j<=n;++j){
            dis[i][j]=INF;
        }
        dis[i][i]=0;
    }
    for(register int i=1;i<=m;++i){
        for(register int ui=1;ui<=cnt[i];++ui){
            pair<ll,ll>pu=st[i][ui];
            ll u=pu.first,uw=pu.second;
            for(register int vi=1;vi<=cnt[i];++vi){
                pair<ll,ll>pv=st[i][vi];
                ll v=pv.first,vw=pv.second;
                dis[u][v]=min(dis[u][v],uw+vw);
            }
        }
    }
    for(register int k=1;k<=n;++k){
        for(register int i=1;i<=n;++i){
            for(register int j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        ll u,v,ans=INF;
        cin>>u>>v;
        for(register int ui=1;ui<=cnt[u];++ui){
            pair<ll,ll>pu=st[u][ui];
            ll ul=pu.first,uw=pu.second;
            for(register int vi=1;vi<=cnt[v];++vi){
                pair<ll,ll>pv=st[v][vi];
                ll vl=pv.first,vw=pv.second;
                ans=min(ans,dis[ul][vl]+uw+vw+wt[u]+wt[v]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
