#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long c,m,n,d,q,k,sta[N],x,y,ans,dis[N],vis[N];
struct node{
    long long v,w;
};
bool operator < (node a,node b){
    return a.w>b.w;
}
vector<node> edge[N];
vector<node> tim;
priority_queue<node> pq;
void dijkstra(long long x){
    for (int i=1;i<=m;++i){
        dis[i]=1e9;
        vis[i]=0;
    }
    dis[x]=0;
    pq.push({x,0});
    while(!pq.empty()){
        node cur=pq.top();
        pq.pop();
        if (vis[cur.v]) continue;
        vis[cur.v]=1;
        for (node nxt:edge[cur.v]){
            if (dis[nxt.v]>dis[cur.v]+nxt.w){
                dis[nxt.v]=dis[cur.v]+nxt.w;
            }
            if (!vis[nxt.v]) pq.push({nxt.v,dis[nxt.v]});
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    long long a,t;
    for (int i=1;i<=m;++i) cin>>sta[i];
    for (int i=1;i<=n;++i){
        cin>>k;
        tim.clear();
        for (int j=1;j<=k;++j){
            cin>>a>>t;
            for (node ifo:tim){
                edge[ifo.v].push_back({a,t+ifo.w});
                edge[a].push_back({ifo.v,t+ifo.w});
            }
            tim.push_back({a,t});
        }
    }
    while(q--){
        cin>>x>>y;
        ans=sta[x]+sta[y];
        dijkstra(x);
        ans+=dis[y];
        cout<<ans<<"\n";
    }
    return 0;
}
