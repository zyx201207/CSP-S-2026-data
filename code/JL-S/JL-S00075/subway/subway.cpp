#include <bits/stdc++.h>
using namespace std;
const int N=5e6+10;
struct Edge{
    int v,w;
};
vector <Edge> e[N];
vector <Edge> t[N];
vector <Edge> a[N];
int dis[N],vis[N];
int w[N];
int c,n,m,d,q;
void dij(int s){
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        auto u=q.top();
        q.pop();
        if(vis[u.second])
            continue;
        vis[u.second]=1;
        for(auto v:e[u.second]){
            if(dis[v.v]>dis[u.second]+v.w){
                dis[v.v]=dis[u.second]+v.w;
                q.push({dis[v.v],v.v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            a[i].push_back({x,y});
            t[x].push_back({i,y});

        }
    }
    for(int i=1;i<=m;i++){
        for(auto u:t[i]){
            for(auto x:a[u.v]){
                if(x.v!=i){
                    e[i].push_back({x.v,u.w+x.w});
                    e[x.v].push_back({i,u.w+x.w});
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dij(l);
        cout<<dis[r]+w[r]+w[l]<<'\n';
    }
    return 0;
}
