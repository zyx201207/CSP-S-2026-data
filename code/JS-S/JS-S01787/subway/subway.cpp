#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll inf,n,m,s,dis[505][505],h[505],cnt,w[505],c,a[505][505],b[505][505],d,q,k[505];
bool vis[505];
struct edge{
    ll u,v,w;
}e[2005];
struct node{
    ll u;
    ll d;
    friend bool operator<(const node a,const node b){
        return a.d>b.d;
    }
};
void add(ll u,ll v,ll w){
    e[++cnt].u=h[u];
    e[cnt].v=v;
    e[cnt].w=w;
    h[u]=cnt;
}
void dij(){
    memset(vis,0,sizeof(vis));
    priority_queue<node>q;
    dis[s][s]=0;
    q.push({s,0});
    while(!q.empty()){
        ll u=q.top().u;
        ll d=q.top().d;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=h[u];i;i=e[i].u){
            ll v=e[i].v,w=e[i].w;
            if(dis[s][v]>=dis[s][u]+w){
                dis[s][v]=dis[s][u]+w;
                q.push({v,dis[s][v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>b[i][j];
            for(int k1=1;k1<j;k1++){
                add(a[i][k1],a[i][j],b[i][j]+b[i][k1]);
                add(a[i][j],a[i][k1],b[i][j]+b[i][k1]);
            }
        }
    }
    memset(dis,0x3f,sizeof(dis));
    inf=dis[0][0];
    while(q--){
        ll v,u;
        cin>>u>>v;
        s=u;
        if(dis[u][v]==inf)dij();
        cout<<w[u]+dis[u][v]+w[v]<<'\n';
    }
    return 0;
}
