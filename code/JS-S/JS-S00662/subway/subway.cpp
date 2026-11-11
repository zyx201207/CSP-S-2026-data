#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=505050;
int c,n,m,d,qq;
ll w[505050];
int k[555];
int l,r;
int ma=0;
struct sta{
    ll x,v;
};
vector<sta> a[555];
struct node{
    ll v,w;
};
vector<node> e[MAXN];
struct edge{
    ll u,d;
    bool operator> (const edge A) const{
        return d>A.d;
    }
};
priority_queue<edge,vector<edge>,greater<edge> > q;
ll dis[505050],vis[505050];
ll dd[1010][1010];
void dijkstra(int s,int n){
    for(int i=1;i<=n;i++){
        dis[i]=1e9;
        vis[i]=0;
    }
    q.push({s,0});
    dis[s]=0;
    while(!q.empty()){
        ll u=q.top().u;
        ll d=q.top().d;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto ed:e[u]){
            ll v=ed.v,ww=ed.w;
            if(dis[v]>dis[u]+ww){
                dis[v]=dis[u]+ww;
                q.push({v,dis[v]});
            }
        }
    }
} 
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,v;
            cin>>x>>v;
            a[i].push_back({x,v});
            ma=max(ma,x);
        }
        for(int j=0;j<k[i];j++){
            for(int jj=0;jj<k[i];jj++){
                if(j!=jj){
                    e[a[i][j].x].push_back({a[i][jj].x,a[i][j].v+a[i][jj].v});
                }
            }
        }
    }
    // for(int i=1;i<=5;i++){
    //     for(int j=0;j<e[i].size();j++){
    //         cout<<i<<" "<<e[i][j].v<<" "<<e[i][j].w<<'\n';
    //     }
    // }
    for(int i=1;i<=ma;i++){
        dijkstra(i,ma);
        for(int j=1;j<=ma;j++){
            dd[i][j]=dis[j];
        }
    }
    while(qq--){
        cin>>l>>r;
        cout<<dd[l][r]+w[l]+w[r]<<'\n';
    }
    return 0;
}
// g++ subway.cpp -o subway -std=c++14 -O2
// ./subway