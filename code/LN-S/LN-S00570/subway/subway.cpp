#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,w[500005],K[505],dis[505][505];
unordered_map<ll,ll> t[500005];
vector<ll> g[500005];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>K[i];
        for(int j=1;j<=K[i];j++){
            ll u,ti;
            cin>>u>>ti;
            t[u][i]=ti;
            g[u].push_back(i);
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=dis[j][i]=1e18;
    for(int u=1;u<=m;u++){
        for(int i=0;i<g[u].size();i++){
            for(int j=0;j<g[u].size();j++){
                ll x=g[u][i],y=g[u][j];
                if(x==y) continue;
                dis[x][y]=min(dis[x][y],t[u][x]+t[u][y]);
                dis[y][x]=min(dis[y][x],t[u][x]+t[u][y]);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++) dis[i][i]=0;
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=n;j++) cout<<dis[i][j]<<' ';
    //    cout<<'\n';
    //}
    while(q--){
        ll x,y,ans=1e18;
        cin>>x>>y;
        for(int i=0;i<g[x].size();i++){
            for(int j=0;j<g[y].size();j++){
                int d1=g[x][i],d2=g[y][j];
                ans=min(ans,dis[d1][d2]+t[x][d1]+t[y][d2]+w[x]+w[y]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//diff -ZB subway.out subway.ans
