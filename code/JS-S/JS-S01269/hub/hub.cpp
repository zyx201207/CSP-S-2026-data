#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
int c,n,m,d,q;
vector<pii>g[N+M],G[N];
ll dijkstra(int s,int t){
    vector<pii>G[N];
    for(int i=1;i<=n;i++){
        if(g[i][s]){
            G[1+n].push_back({i,g[i][s]});
            G[i].push_back({1+n,g[i][s]});
        }
        if(g[i][t]){
            G[2+n].push_back({i,g[i][t]});
            G[i].push_back({2+n,g[i][t]});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<)
    }
    priority_queue<pli,vector<pli>,greater<pli> >q;
    ll dist[n+5];
    memset(dist,0x3f,sizeof(dist));
    q.push({0,n+1});
    dist[n+1]=0;
    while(!q.empty()){
        ll dis=q.top().first;
        int u=q.top().second;
        q.pop();
        if(dis>dist[u]) continue;
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i].first,w=G[u][i].second;
            if(dis+w<dist[v]){
                dist[v]=dis+w;
                q.push({dist[v],v});
            }
        }
    }
    return dist[n+2];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int a[m+5];
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int v,w;
            cin>>v>>w;
            g[i].push_back({n+v,w});
            g[n+v].push_back({i,w});
        }
    }
    for(int i=n+1;i<=n+m;i++){
        for(int j=0;j<g[i].size();j++){
            for(int k=j+1;k<g[i].size();k++){
                G[g[i][j]].push_back({k,g[i][j]+g[i][k]});
                G[k].push_back({j,g[i][j]+g[i][k]});
            }
        }
    }
    for(int i=1;i<=q;i++){
        int s,t;
        cin>>s>>t;
        cout<<dijkstra(s,t)+a[s]+a[t]<<'\n';
    }
    return 0;
}
