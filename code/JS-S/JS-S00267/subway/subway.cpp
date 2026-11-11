#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
    ll to,w;
};
struct node{
    ll to,t;
};
int c,n,m,d,q,w[500005],minv[505][505],k;
ll dist[505][505];
vector <node> luxian[500005];
vector <node> s[505];
vector <edge> edges[505];
set <pair<ll,int>> Q;
inline void dijkstra(int s){
    dist[s][s]=0;
    Q.insert({dist[s][s],s});
    while(!Q.empty()){
        auto cur=Q.begin();
        int u=cur->second;
        if(dist[s][u]==0x3f3f3f3f3f3f3f3f) break;
        Q.erase(Q.begin());
        for(auto v:edges[u]){
            if(dist[s][u]+v.w<dist[s][v.to]){
                Q.erase({dist[s][v.to],v.to});
                dist[s][v.to]=dist[s][u]+v.w;
                Q.insert({dist[s][v.to],v.to});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            luxian[a].push_back({i,t});
            s[i].push_back({a,t});
        }
    }
    memset(minv,0x3f,sizeof(minv));
    for(int i=1;i<=n;i++){
        for(auto u:s[i]){
            int a=u.to,t1=u.t;
            for(auto v:luxian[a]){
                int to=v.to,t2=v.t;
                if(i==to) continue;
                minv[i][to]=minv[to][i]=min(minv[i][to],t1+t2);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(minv[i][j]!=0){
                edges[i].push_back({j,minv[i][j]});
                edges[j].push_back({i,minv[i][j]});
                minv[i][j]=minv[j][i]=0;
            }
        }
    }
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=n;i++){
        dijkstra(i);
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ll res=0x3f3f3f3f3f3f3f3f;
        for(auto k1:luxian[x]){
            for(auto k2:luxian[y]){
                if(k1.to==k2.to){
                    res=min(res,k1.t+w[x]+w[y]+k2.t);
                }
                res=min(res,dist[k1.to][k2.to]+k1.t+k2.t+w[x]+w[y]);
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
