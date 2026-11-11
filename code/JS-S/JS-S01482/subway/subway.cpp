#include<bits/stdc++.h>
using namespace std;
int dp[1501][1501],w[1001],k[501],n,m,dis[500501];
vector<int>a[501],t[501];
struct edge{
    int v,w;
    bool operator <(const edge &b)const{
        return w>b.w;
    }
};
vector<edge>G[500501];
bitset<500501>vis;
inline int dij(int start,int tar){
    memset(dis,0x3f,sizeof(dis));
    vis.reset();
    priority_queue<edge>q;
    dis[start]=0;
    q.push({start,0});
    int t,v,w;
    while(!q.empty()){
        t=q.top().v;q.pop();
        if(vis[t])continue;
        vis[t]=true;
        if(t==tar)return dis[t];
        for(auto e:G[t]){
            v=e.v;w=e.w;
            if(vis[v])continue;
            if(dis[v]>dis[t]+w){
                dis[v]=dis[t]+w;
                q.push({v,dis[v]});
            }
        }
    }
}

int main(){
    #ifndef testing
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    #endif
    memset(dp,0x3f,sizeof(dp));
    int c,d,q,x,y;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    if(q>2000){
        for(int i=1;i<=n+m;++i)dp[i][i]=0;
        for(int i=1;i<=n;++i){
            cin>>k[i];
            for(int ta,tt,j=1;j<=k[i];++j){
                cin>>ta>>tt;
                a[i].push_back(ta);
                t[i].push_back(tt);
                dp[i][ta+n]=dp[ta+n][i]=tt;
            }
        }
        for(int K=1;K<=n+m;++K){
            for(int u=1;u<=n+m;++u){
                for(int v=1;v<=n+m;++v){
                    dp[u][v]=min(dp[u][v],dp[u][K]+dp[K][v]);
                }
            }
        }
        ++q;
        while(--q){
            cin>>x>>y;
            cout<<w[x]+w[y]+dp[n+x][n+y]<<'\n';
        }
        return 0;
    }
    else{
        for(int i=1;i<=n;++i){
            cin>>k[i];
            for(int a,t,j=1;j<=k[i];++j){
                cin>>a>>t;
                G[i].push_back({n+a,t});
                G[n+a].push_back({i,t});
            }
        }
        ++q;
        while(--q){
            cin>>x>>y;
            cout<<w[x]+w[y]+dij(x+n,y+n)<<'\n';
        }
    }
}