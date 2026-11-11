#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
#define rep(i,t1,t2,t3) for(decltype((t1)+(t2)+(t3)) i=(t1);i<=(t2);i+=(t3))
#define per(i,t1,t2,t3) for(decltype((t1)+(t2)+(t3)) i=(t1);i>=(t2);i-=(t3))
#define pb push_back
#define fi first
#define se second
constexpr i64 N=505,M=500005,INF=(i64(1)<<60);
i64 w[M],dis[N][N];
vector<pair<i64,i64>> to[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    i64 c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    rep(i,1,m,1) cin>>w[i];
    rep(i,1,n,1){
        i64 k;cin>>k;
        while(k--){i64 x,y;cin>>x>>y,to[x].pb({i,y});}
    }
    rep(i,1,n,1) rep(j,1,n,1) dis[i][j]=(i==j?0:INF);
    rep(i,1,m,1){
        //cout<<i<<"::\n";
        //for(auto j:to[i]) cout<<j.fi<<' '<<j.se<<'\n';
        i64 sz=i64(to[i].size());
        rep(t1,0,sz-1,1) rep(t2,0,sz-1,1) if(t1!=t2){
            pair<i64,i64> p1=to[i][t1],p2=to[i][t2];
            dis[p1.fi][p2.fi]=min(dis[p1.fi][p2.fi],p1.se+p2.se);
        }
    }
    rep(k,1,n,1) rep(i,1,n,1) rep(j,1,n,1){
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    while(q--){
        //cout<<"newcase\n";
        i64 x,y;cin>>x>>y;
        i64 ans=INF;
        for(auto tmp1:to[x]) for(auto tmp2:to[y]){
            //cout<<tmp1.fi<<' '<<tmp2.fi<<':'<<dis[tmp1.fi][tmp2.fi]+tmp1.se+tmp2.se<<'\n';
            ans=min(ans,dis[tmp1.fi][tmp2.fi]+tmp1.se+tmp2.se);
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
