#include<bits/stdc++.h>
#define EQ ==
using namespace std;
typedef long long ll;
const int M=1010;
int n,m,d,q,tot=0;
ll w[M<<1],dis[M<<1],ans[100100];
bool vis[M<<1];
vector<pair<int,int> > qry[M];
vector<pair<int,ll> > edge[M<<1];
priority_queue<pair<ll,int> > Q;
inline void dijsktra(int st){
    for(int t=1;t<=tot;t++){
        dis[t]=1e18;vis[t]=0;
    }
    dis[st]=0;vis[st]=1;
    Q.push({0,st});
    while(!Q.empty()){
        int u=Q.top().second;
        Q.pop();vis[u]=0;
        for(auto t : edge[u]){
            int v=t.first;ll val=t.second;
            if(dis[v]>dis[u]+val){
                dis[v]=dis[u]+val;
                if(!vis[v]){
                    Q.push({-dis[v],v});
                    vis[v]=1;
                }
            }
        }
    }
}
inline void solve(){
    cin>>n>>m>>d>>q;tot=m;
    for(int t=1;t<=m;t++){
        cin>>w[t];
    }
    for(int t=1;t<=n;t++){
        int k;cin>>k;tot++;
        for(int i=1;i<=k;i++){
            int a,b;cin>>a>>b;
            edge[a].push_back({tot,b});
            edge[tot].push_back({a,b});
        }
    }
    for(int t=1;t<=q;t++){
        int u,v;cin>>u>>v;
        qry[u].push_back({v,t});
    }
    for(int t=1;t<=m;t++){
        dijsktra(t);
        for(auto i : qry[t]){
            int v=i.first;
            ans[i.second]=dis[v]+w[v]+w[t];
        }
    }
    for(int t=1;t<=q;t++){
        cout<<ans[t]<<'\n';
    }
}
int main(){
    cin.tie(0)->ios::sync_with_stdio;
    cout.tie(0)->ios::sync_with_stdio;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c;cin>>c;
    solve();
    return 0;
}