#include<bits/stdc++.h>
#define int long long
#define REP(i,a,b,c) for(int i=a;i<=b;i+=c)
#define PER(i,a,b,c) for(int i=a;i>=b;i-=c)
#define sz(s) s.size()
using namespace std;
const int N=5e5+5,M=1005;
const int INF=1e18;
int c,n,m,d,q,w[N],tot,dis[N],dis2[M+500][M+500];
bool vis[N];
struct Node{
    int v,w;
};
vector<Node>adj[N];
void dijkstra(int sx){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,sx});
    while(!q.empty()){
        int u=q.top().second; q.pop();
        if(vis[u]) continue; vis[u]=1;
        for(auto e:adj[u]){
            int v=e.v,p=e.w;
            if(dis[v]>dis[u]+p){
                dis[v]=dis[u]+p;
                q.push({dis[v],v});
            }
        }
    }
}
void dijkstra2(int sx){
    REP(i,1,n+m,1) vis[i]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,sx});
    while(!q.empty()){
        int u=q.top().second; q.pop();
        if(vis[u]) continue; vis[u]=1;
        for(auto e:adj[u]){
            int v=e.v,p=e.w;
            if(dis2[sx][v]>dis2[sx][u]+p){
                dis2[sx][v]=dis2[sx][u]+p;
                q.push({dis2[sx][v],v});
            }
        }
    }
}
void solve2(){
    REP(i,1,n+m,1){
        REP(j,1,n+m,1){
            dis2[i][j]=INF;
            if(i==j) dis2[i][j]=0;
        }
    }
    REP(i,1,m,1) dijkstra2(i);
    REP(i,1,q,1){
        int x,y; cin>>x>>y;
        cout<<w[x]+w[y]+dis2[x][y]<<"\n";
    }
}
void solve(){
    cin>>c>>n>>m>>d>>q;
    REP(i,1,m,1) cin>>w[i];
    REP(i,1,n,1){
        int k; cin>>k;
        REP(j,1,k,1){
            int a,t; cin>>a>>t;
            adj[m+i].push_back({a,t});
            adj[a].push_back({m+i,t});
        }
    }
    if(m<=1000){
        solve2();
        return ;
    }
    REP(i,1,q,1){
        int x,y; cin>>x>>y;
        REP(i,1,n+m,1) dis[i]=INF,vis[i]=0;
        dis[x]=0; dijkstra(x);
        cout<<w[x]+w[y]+dis[y]<<"\n";
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t=1;
    while(t--) solve();
}
