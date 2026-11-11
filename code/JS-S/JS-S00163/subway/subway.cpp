#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=40005;
const ll INF=1e18+7;
struct node{
    int first;
    ll second;
};
int n,c,e,q;
ll m;
int k[505];
ll b[505][505];
ll dis[505];
ll v[505][N];
int a[505][N];
vector<pair<int,ll> >adj[505];
void dijkstra(int s){
    for(int i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[s]=0;
    priority_queue<pair<int,ll>,vector<pair<int,ll> >,greater<pair<int,ll> > > q;
    q.push({s,0});
    while(!q.empty()){
        int u=q.top().first;
        ll d=q.top().second;
        q.pop();
        if(d>dis[u]) continue;
        for(auto &v : adj[u]){
            if(dis[v.first]>dis[u]+v.second){
                dis[v.first]=dis[u]+v.second;
                q.push({v.first,dis[v.first]});
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>e>>q;
    ll w[N];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    vector<pair<int,ll> >point[N];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>v[i][j];
            point[a[i][j]].push_back({i,v[i][j]});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            int pos=a[i][j];
            for(int k=0;k<point[pos].size();k++){
                if(point[pos][k].first!=i&&point[pos][k].second+v[i][j]<b[i][point[pos][k].first]){
                    b[i][point[pos][k].first]=point[pos][k].second+v[i][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]!=INF){
                adj[i].push_back({j,b[i][j]});
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=w[x]+w[y],tmp=INF;
        for(int i=0;i<point[x].size();i++){
            dijkstra(point[x][i].first);
            for(int j=0;j<point[y].size();j++){
                tmp=min(tmp,dis[point[y][j].first]);
            }
        }
        cout<<ans+tmp<<endl;
    }
    return 0;
}
