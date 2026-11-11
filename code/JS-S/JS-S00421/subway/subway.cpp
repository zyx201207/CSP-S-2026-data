#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
    int u,w;
    bool operator < (const Node& b)const{
        return w>b.w;
    }
};
vector <int> g[605],c[605];
int C,n,m,d,Q,a[605],dist[605][605];
void add(int u,int v,int w){
    g[u].push_back(v);
    c[u].push_back(w);
}
priority_queue <Node> q,q1;
bool vis[605];
void dij(int s){
    q=q1;
    for(int i=1;i<=n+m;i++){
        dist[s][i]=1e18,vis[i]=0;
    }
    dist[s][s]=0;
    q.push({s,0});
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i],w=c[u][i];
            if(dist[s][u]+w<dist[s][v]){
                dist[s][v]=dist[s][u]+w;
                q.push({v,dist[s][v]});
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
    cin>>C>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        while(tmp--){
            int x,y;
            cin>>x>>y;
            int u=m+i,v=x;
            add(u,v,y);
            add(v,u,y);
        }
    }
    for(int i=1;i<=m+n;i++){
        dij(i);
    }
    while(Q--){
        int u,v;
        cin>>u>>v;
        cout<<dist[u][v]+a[u]+a[v]<<"\n";
    }

    return 0;
}

