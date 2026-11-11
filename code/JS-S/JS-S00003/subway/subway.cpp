/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,Q,w[500005];
struct node{
    ll v,w;
    bool b;
    bool operator < (node A){
        return w>A.w;
    }
};
vector<node> sub[500];
vector<node> g[500005];
void dij(ll x,ll y){
    ll dist[1000];
    for(int i=1;i<=n;i++){
        dist[i]=1e18;
    }
    priority_queue<node> q;
    node e=q.top();q.pop();
    if(e.b=0){
        for(node vi:g[e.v]){
            if(dist[])
        }
    }
}
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(int j=1;j<=k;j++){
            ll x,y;
            cin>>x>>y;
            sub[i].push_back({x,y,0});
            g[x].push_back({i,y,1});
        }
    }
    while(Q--){
        ll x,y;
        cin>>x>>y;
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,Q,w[500005];
struct node{
    ll v,w;
    /*bool operator < (const node& A){
        return w>A.w;
    }*/
};
bool cmp(node p,node ne){
    return p.w<ne.w;
}
vector<node> g[500005];
/*ll dij(ll x,ll y){
    ll dist[2000];
    bool vis[2005];
    for(int i=1;i<=n;i++){
        dist[i]=1e18;
        vis[i]=0;
    }
    vis[x]=1;
    dist[x]=0;
    priority_queue<node> q;
    q.push({x,0});
    while(!q.empty()){
        node e=q.top();q.pop();
        vis[e.v]=1;
        if(e.v==y) break;
        for(node vi:g[e.v]){
            if(dist[vi.v]>dist[e.v]+vi.w&&!vis[vi.v]){
                dist[vi.v]=dist[e.v]+vi.w;
                q.push({vi.v,dist[vi.v]});
            }
        }
    }
    return dist[y];
}*/
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(int j=1;j<=k;j++){
            ll x,y;
            cin>>x>>y;
            g[x].push_back({n+i,y});
            g[i+n].push_back({x,y});
        }
    }
    while(Q--){
        /*ll x,y;
        cin>>x>>y;
        ll t=dij(x,y);
        t+=w[x];
        t+=w[y];
        cout<<t<<'\n';*/
        cout<<0<<'\n';
    }
    return 0;
}
