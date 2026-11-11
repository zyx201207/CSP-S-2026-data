#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5e5+1;
int taskid,n,m,d,Q,w[N],dis[501][501],c[501][501],vis[501],k,a,t,x,y;
vector<PII>G[501],H[N];
void dijkstra(int x){
    priority_queue<PII,vector<PII>,greater<PII> >q;
    memset(vis,0,sizeof vis);
    q.push({0,x});
    dis[x][x]=0;
    while(q.size()){
        int u=q.top().se;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].se,w=G[u][i].fi;
            if(dis[x][v]>dis[x][u]+w){
                dis[x][v]=dis[x][u]+w;
                if(!vis[v]) q.push({dis[x][v],v});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>taskid>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            H[a].push_back({t,i});
        }
    }
    memset(dis,0x3f,sizeof dis);
    memset(c,0x3f,sizeof c);
    for(int i=1;i<=m;i++){
        for(int j=0;j<H[i].size();j++){
            for(int k=j+1;k<H[i].size();k++){
                int cnt=H[i][j].fi+H[i][k].fi;
                c[H[i][j].se][H[i][k].se]=min(c[H[i][j].se][H[i][k].se],cnt);
                c[H[i][k].se][H[i][j].se]=min(c[H[i][k].se][H[i][j].se],cnt);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            G[i].push_back({c[i][j],j});
            G[j].push_back({c[j][i],i});
        }
    }
    for(int i=1;i<=n;i++) dijkstra(i);
    while(Q--){
        int ans=1e18;
        cin>>x>>y;
        for(int i=0;i<H[x].size();i++){
            for(int j=0;j<H[y].size();j++){
                ans=min(ans,dis[H[x][i].se][H[y][j].se]+H[x][i].fi+H[y][j].fi);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
}
