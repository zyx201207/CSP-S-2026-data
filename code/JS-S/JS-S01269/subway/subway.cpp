#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
int c,n,m,d,q;
vector<pii>G[N+M];
ll dijkstra(int s,int t){
    priority_queue<pli,vector<pli>,greater<pli> >q;
    ll dist[n+m+1];
    memset(dist,0x3f,sizeof(dist));
    q.push({0,s});
    dist[s]=0;
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
    return dist[t];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
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
            G[i+m].push_back({v,w});
            G[v].push_back({i+m,w});
        }
    }
    for(int i=1;i<=q;i++){
        int s,t;
        cin>>s>>t;
        cout<<dijkstra(s,t)+a[s]+a[t]<<'\n';
    }
    return 0;
}
