#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace _44pts{
    vector<pair<int,int> >vec[1005];
    int w[1005],k[1005];
    int a[1005],t[1005];
    priority_queue<pair<int,int> >que;
    int dist[1005][1005];
    bool vis[1005];
    void Dijkstra(int st){
        dist[st][st]=0;
        que.push({0,st});
        while (!que.empty()){
            int u=que.top().second;
            que.pop();
            if (vis[u]==true)continue;
            vis[u]=true;
            for (auto i:vec[u]){
                int v=i.first,w=i.second;
                if (dist[st][v]>dist[st][u]+w){
                    dist[st][v]=dist[st][u]+w;
                    que.push({-dist[st][v],v});
                }
            }
        }
    }
    void main(){
        int n,m,d,q;
        scanf("%lld%lld%lld%lld",&n,&m,&d,&q);
        for (int i=1;i<=m;i++)scanf("%lld",&w[i]);
        for (int i=1;i<=n;i++){
            scanf("%lld",&k[i]);
            for (int j=1;j<=k[i];j++){
                scanf("%lld%lld",&a[j],&t[j]);
            }
            for (int j=1;j<=k[i];j++){
                for (int l=1;l<=k[i];l++){
                    if (j==l)continue;
                    vec[a[j]].push_back({a[l],t[j]+t[l]});
                }
            }
        }
        memset(dist,0x3f,sizeof(dist));
        for (int i=1;i<=m;i++){
            memset(vis,false,sizeof(vis));
            Dijkstra(i);
        }
        int st,en;
        while (q--){
            scanf("%lld%lld",&st,&en);
            printf("%lld\n",dist[st][en]+w[st]+w[en]);
        }
    }
}
namespace _100pts{
    priority_queue<pair<int,int> >que;
    int dist[505][505];
    bool vis[505];
    int w[500005];
    vector<pair<int,int> >vec[505];
    void Dijkstra(int st){
        dist[st][st]=0;
        que.push({0,st});
        while (!que.empty()){
            int u=que.top().second;
            que.pop();
            if (vis[u]==true)continue;
            vis[u]=true;
            for (auto i:vec[u]){
                int v=i.first,w=i.second;
                if (dist[st][v]>dist[st][u]+w){
                    dist[st][v]=dist[st][u]+w;
                    que.push({-dist[st][v],v});
                }
            }
        }
    }
    vector<pair<int,int> >in[500005];
    int z[505][505];
    vector<pair<int,int> >path[505];
    void main(){
        int n,m,d,q,k,a,t;
        scanf("%lld%lld%lld%lld",&n,&m,&d,&q);
        for (int i=1;i<=m;i++)scanf("%lld",&w[i]);
        for (int i=1;i<=n;i++){
            scanf("%lld",&k);
            for (int j=1;j<=k;j++){
                scanf("%lld%lld",&a,&t);
                path[i].push_back({a,t});
                in[a].push_back({i,t});
            }
        }
        memset(z,0x3f,sizeof(z));
        for (int i=1;i<=m;i++){
            for (auto u:in[i]){
                for (auto v:in[i]){
                    if (u==v)continue;
                    z[u.first][v.first]=min(z[u.first][v.first],u.second+v.second);
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                vec[i].push_back({j,z[i][j]});
                vec[j].push_back({i,z[i][j]});
            }
        }
        memset(dist,0x3f,sizeof(dist));
        for (int i=1;i<=n;i++){
            memset(vis,false,sizeof(vis));
            Dijkstra(i);
        }
        while (q--){
            int st,en;
            scanf("%lld%lld",&st,&en);
            int ans=1e18;
            for (auto u:in[st]){
                for (auto v:in[en]){
                    ans=min(ans,dist[u.first][v.first]+u.second+v.second);
                }
            }
            ans=ans+w[st]+w[en];
            printf("%lld\n",ans);
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;
    scanf("%lld",&c);
    if (c<=11&&c>=1){
        _44pts::main();
        return 0;
    }
    else{
        _100pts::main();
    }
    return 0;
}