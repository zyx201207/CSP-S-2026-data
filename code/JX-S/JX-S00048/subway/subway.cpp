#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq;
int ju[500005];
struct edge{
    int v;
    long long w;
};
vector<edge> e[600005];
long long dis[600005];
bool vis[600005];
struct node{
    int id;
    long long w;
    bool operator<(const node &o)const{
        return w>o.w;
    }
};
priority_queue<node> q;
long long dijkstra(int st,int ed){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[st]=0;
    q.push({st,0});
    while(!q.empty()){
        //cout<<q.top().id<<" "<<q.top().w<<"\n";
        int u=q.top().id;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(edge it:e[u]){
            int v=it.v;
            long long w=it.w;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
    return dis[ed];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&qq);
    for(int i=1;i<=m;i++){
        scanf("%d",&ju[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int a,t;
            scanf("%d%d",&a,&t);
            e[a].push_back({i+m,t});
            e[i+m].push_back({a,t});
        }
    }
    for(int i=1;i<=qq;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%lld\n",dijkstra(l,r)+ju[l]+ju[r]);
    }
    return 0;
}
