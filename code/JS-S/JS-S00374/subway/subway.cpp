#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=505;
typedef long long ll;
typedef pair<ll,ll> pll;
struct edge{
    int v;
    ll w1;
};
vector<edge>g[N];
vector<int>sy[N];
ll c,n,m,d,q;
ll w[N],t[M][N/10],dis[M];
bool vis[M][N],vis1[N];
void djstl(int s){

    dis[s]=0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis1[u]){
            continue;
        }
        vis1[u]=1;
        for(edge e:g[u]){
            int to=e.v;
            ll w=e.w1;
            if(dis[to]>dis[u]+w){
                dis[to]=dis[u]+w;
                pq.push({dis[to],to});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[N];
    }
    for(int i=1;i<=n;i++){
        int T,u,we;
        cin>>T;
        for(int j=1;j<=T;j++){
            cin>>u>>we;
            sy[u].push_back(i);
            vis[i][u]=1;
            t[i][u]=we;
            for(int k=1;k<i;k++){
                if(vis[k][u]){
                    g[i].push_back({k,t[i][u]+t[k][u]});
                    g[k].push_back({i,t[i][u]+t[k][u]});
                }
            }
        }
    }

    ll ma=LLONG_MAX;
    for(int i=1;i<=q;i++){
        ma=LLONG_MAX;
        ll x,y;
        cin>>x>>y;
        for(int e:sy[x]){
            fill(dis,dis+m+1,LLONG_MAX);
            fill(vis1,vis1+m+1,0);
            djstl(e);
            for(int lj:sy[y]){
                ma=min(ma,dis[lj]+w[e]+w[lj]);
            }
        }
        cout<<ma<<'\n';
    }
    return 0;
}

