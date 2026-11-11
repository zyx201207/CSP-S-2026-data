#include<bits/stdc++.h>
using namespace std;
int ww[200005];
int c,n,m,d,q;//n是地铁线路 m是地铁站数
vector<pair<int,int> > g[500505];//节点 距离
long long dis[500505];
void dijkstra(int s,int num){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    for(int i=1;i<=num;i++)dis[i]=0x3f3f3f3f;
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(d>dis[u])continue;
        for(auto Edge : g[u]){
            int v=Edge.first;
            int w=Edge.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>ww[i];
    //建图 构建虚点 线路i为节点n+i
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u,t;
            cin>>u>>t;
            g[u].push_back({m+i,t});
            g[m+i].push_back({u,t});
        }
    }
    for(int i=1;i<=q;i++){
        int s1,s2;
        cin>>s1>>s2;
        dijkstra(s1,n+m);
        long long ans=dis[s2];
        ans+=ww[s1];
        ans+=ww[s2];
        cout<<ans<<'\n';
    }
    return 0;
}
