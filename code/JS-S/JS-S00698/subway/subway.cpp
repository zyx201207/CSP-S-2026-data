#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll,int> PLI;
const int M=5e5+5;
const int EC = 1e6+5;
const ll INF=LLONG_MAX;
int c,n,m,d,q,u,v;
ll w[M],cost[1005][1005],t[M],dis[1005];
ll sve[1005][1005];
int k,id[M];
int head[1005],nxt[EC],to[EC],val[EC];
priority_queue<PLI,vector<PLI>,greater<PLI>> pq;
void addedge(int u,int v,ll w,int id) {
    nxt[id]=head[u];
    head[u]=id;
    to[id]=v;
    val[id]=w;
}
void build() {
    int ec=1;
    for(int i=1;i<=min(1000,m);++i) {
        for(int j=i+1;j<=min(1000,m);++j) {
            if(cost[i][j]!=INF) {
                addedge(i,j,cost[i][j],ec++);
                addedge(j,i,cost[i][j],ec++);
            }
        }
    }
}
void solve(int u) {
    for(int i=1;i<=min(1000,m);++i)dis[i]=INF;
    dis[u]=0;
    pq.push({0,u});
    while(!pq.empty()) {
        ll w=pq.top().first,x=pq.top().second;
        pq.pop();
        if(w!=dis[x])continue;
        for(int e=head[x];e!=0;e=nxt[e]) {
            if(to[e]==x)continue;
            if(to[e]>1000)continue;
            ll cost=w+val[e];
            if(dis[to[e]]>cost) {
                dis[to[e]]=cost;
                pq.push({cost,to[e]});
            }
        }
    }
    for(int i=1;i<=min(1000,m);++i) {
        sve[u][i]=dis[i];
    }
}
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i) {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=min(1000,m);++i) {
        for(int j=1;j<=min(1000,m);++j) {
            cost[i][j]=INF;
        }
    }
    for(int i=1;i<=n;++i) {
        scanf("%d",&k);
        for(int j=1;j<=k;++j) {
            scanf("%d%lld",&id[j],&t[j]);
        }
        for(int j=1;j<=k;++j) {
            for(int p=j+1;p<=k;++p) {
                cost[id[j]][id[p]]=min(cost[id[j]][id[p]],t[j]+t[p]);
                cost[id[p]][id[j]]=min(cost[id[p]][id[j]],t[j]+t[p]);
            }
        }
    }
    build();
    for(int i=1;i<=min(1000,m);++i)solve(i);
    while(q--) {
        scanf("%d%d",&u,&v);
        printf("%lld\n",w[u]+w[v]+sve[u][v]);
    }
    return 0;
}
