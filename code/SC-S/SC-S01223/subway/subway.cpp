#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const long long INF=0x3f3f3f3f3f3f3f3f;
struct Edge{
    int to,w;
};
struct Node{
    int idx;
    long long dis;
    bool operator < (const Node &a) const{
        return dis>a.dis;
    }
};
int c,k,n,d,Q,w[N],tot;
long long d0[1005][21005],d1[N];
bool vis[N];
vector<Edge> e[N];
priority_queue<Node> q;
void Dijkstra(int st,long long a[]){
    memset(vis,0,sizeof vis);
    a[st]=0;
    q.emplace(Node{st,0});
    while(!q.empty()){
        int u=q.top().idx,dis=q.top().dis;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(Edge v:e[u]){
            if(a[v.to]>dis+v.w){
                a[v.to]=dis+v.w;
                q.emplace(Node{v.to,dis+v.w});
            }
        }
    }
    return;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&k,&n,&d,&Q);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    tot=n;
    for(int i=1;i<=k;i++){
        int len;
        scanf("%d",&len);
        int ls=0;
        for(int i=1;i<=len;i++){
            int a,t;
            scanf("%d%d",&a,&t);
            tot++;
            e[tot].emplace_back(Edge{a,t});
            e[a].emplace_back(Edge{tot,t});
            if(ls){
                e[ls].emplace_back(Edge{tot,0});
                e[tot].emplace_back(Edge{ls,0});
            }
            ls=tot;
        }
    }
    if(n<=1000){
        memset(d0,0x3f,sizeof d0);
        for(int i=1;i<=n;i++){
            Dijkstra(i,d0[i]);
            // cout<<d0[i][i+1]<<endl;
        }
        while(Q--){
            int u,v;
            scanf("%d%d",&u,&v);
            // cout<<Q<<endl;
            printf("%lld\n",d0[u][v]+w[u]+w[v]);
        }
        return 0;
    }
    while(Q--){
        int u,v;
        scanf("%d%d",&u,&v);
        for(int i=1;i<=tot;i++) d1[i]=INF;
        Dijkstra(u,d1);
        printf("%lld\n",d1[v]+w[u]+w[v]);
    }
    return 0;
}