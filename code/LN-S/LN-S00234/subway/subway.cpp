#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;
int c,n,m,d,qq,a[N],x,t,y,tot,dis[N],k,ans;
bool vis[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector<pair<int,int> > v[N];
int dijkstra(int s,int e){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[s]=0;
    q.push({0,s});
    while(q.size()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0;i<v[u].size();i++){
            int to=v[u][i].first,w=v[u][i].second;
            if(dis[to]>dis[u]+w){
                dis[to]=dis[u]+w;
                if(!vis[to]) q.push({dis[to],to});
            }
        }
    }
    return dis[e];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    tot=m;
    for(int i=1;i<=n;i++){
        cin>>k;
        tot++;
        for(int j=1;j<=k;j++){
            cin>>x>>t;
            v[x].push_back({tot,t});
            v[tot].push_back({x,t});
        }
    }
    for(int i=1;i<=qq;i++){
        cin>>x>>y;
        ans=a[x]+a[y]+dijkstra(x,y);
        cout<<ans<<'\n';
    }
    return 0;
}
