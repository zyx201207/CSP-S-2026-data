#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+5,M=5e5+5,D=25;
struct edge{
    ll v,w;
};
struct node{
    ll u,w;
    bool operator<(const node &t)const{
        return w>t.w;
    }
};
int c,n,m,d,q,k;
ll wt[M],dis[N][N];
vector<edge> e[N],swy[N],stn[M];
void dijkstra(int s){
    priority_queue<node> q;
    q.push({s,0});
    dis[s][s]=0;
    while(q.size()){
        node t=q.top();
        q.pop();
        ll u=t.u,w=t.w;
        if(w>dis[s][u]) continue;
        for(int i=0;i<e[u].size();i++){
            int v=e[u][i].v,vw=e[u][i].w;
            if(dis[s][v]>w+vw){
                dis[s][v]=w+vw;
                q.push({v,dis[s][v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++) cin>>wt[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            ll v,w;
            cin>>v>>w;
            swy[i].push_back({v,w});
            stn[v].push_back({i,w});
        }
    }
    for(int i=1;i<=m;i++){
        for(int a=0;a<stn[i].size();a++){
            edge u=stn[i][a];
            for(int b=0;b<stn[i].size();b++){
                edge v=stn[i][b];
                if(a==b) continue;
                e[u.v].push_back({v.v,u.w+v.w});
            }
        }
    }
    for(int i=1;i<=n;i++) dijkstra(i);
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=dis[0][0];
        for(int i=0;i<stn[x].size();i++){
            edge u=stn[x][i];
            for(int j=0;j<stn[y].size();j++){
                edge v=stn[y][j];
                ans=min(ans,dis[u.v][v.v]+u.w+v.w);
            }
        }
        ans+=wt[x]+wt[y];
        cout<<ans<<'\n';
    }
    return 0;
}
