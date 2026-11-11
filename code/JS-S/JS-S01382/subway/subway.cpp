#include<bits/stdc++.h>
#define elif else if
#define endl '\n'
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll w[500005];
ll k[505];
ll a[505][25],t[505][25];
ll f[500005];
ll fi(ll x){
    if(f[x]==x)return x;
    return f[x]=fi(f[x]);
}
struct nd{
    ll u,v,w;
};vector<nd>e;
vector<pair<ll,ll>>E[500005];
bool cmp(nd x,nd y){
    return x.w<y.w;
}

bool vis[500005];
ll bfs(ll bg,ll ed){
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    queue<pair<ll,ll>>q;
    q.push({0,bg});
    vis[bg]=1;
    while(!q.empty()){
        auto [s,u]=q.front();
        q.pop();
        if(u==ed)return s;
        for(auto [v,w]:E[u]){
            if(vis[v])continue;
            vis[v]=1;
            q.push({s+w,v});
        }
    }
    return 0;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        f[i]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
        for(int p1=1;p1<=k[i];p1++){
            for(int p2=p1+1;p2<=k[i];p2++){
                e.push_back({a[i][p1],a[i][p2],t[i][p1]+t[i][p2]});
            }
        }
    }

    sort(e.begin(),e.end(),cmp);
    for(int i=0;i<e.size();i++){
        ll u=e[i].u,v=e[i].v,w=e[i].w;
        ll fx=fi(u),fy=fi(v);
        if(fx!=fy){
            E[u].push_back({v,w});
            E[v].push_back({u,w});
            f[fx]=fy;
        }
    }

    while(q--){
        ll u,v;
        cin>>u>>v;
        cout<<w[u]+w[v]+bfs(u,v)<<endl;
    }
    return 0;
}
