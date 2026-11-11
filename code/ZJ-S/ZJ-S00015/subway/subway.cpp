#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
    int to,w;
};
struct node{
    vector<edge>to;
};
node g[1<<20];
int dis[1<<20];
int vis[1<<20];
int c,n,m,d,q,xr,yr,w[1<<20];
void dij(int st){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int>>pq;
    pq.push({0,st});
    dis[st]=0;
    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        if(vis[t.second]){
            continue;
        }
        vis[t.second]=1;
        for(auto i:g[t.second].to){
            if(i.w+dis[t.second]<dis[i.to]){
                dis[i.to]=i.w+dis[t.second];
                if(!vis[i.to]){
                    pq.push({dis[i.to],i.to});
                }
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int tmp1,tmp2,k;
        cin>>k;
        for(int j=0;j<k;j++){
            scanf("%lld%lld",&tmp1,&tmp2);
            g[m+i].to.push_back({tmp1,tmp2});
            g[tmp1].to.push_back({m+i,tmp2});
        }
    }
    for(int i=0;i<q;i++){
        scanf("%lld%lld",&xr,&yr);
        dij(xr);
        printf("%lld\n",(w[xr]+w[yr]+dis[yr]));
    }
    return 0;
}