#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+10,N=505;
int c,n,m,d,q,s,t;
ll val[M],k[N];
int vis[N];
ll dis[N];
struct node{ll v,w;};
vector<node>e[M],ne[M];
vector<pair<ll,ll> >ls;
bool cmp(node A,node B){
    if(A.v!=B.v) return A.v<B.v;
    return A.w<B.w;
}
void dijkstra(int s){
    for(int i=1;i<=m;i++) vis[i]=0;
    for(int i=1;i<=m;i++) dis[i]=1e18;
    priority_queue<pair<ll,ll> >Q;
    Q.push({0,s});
    dis[s]=0;
    while(Q.size()){
        int tu=Q.top().second;
        Q.pop();
        if(vis[tu]) continue;
        vis[tu]=1;
        for(int i=0;i<ne[tu].size();i++){
            int tv=ne[tu][i].v;
            ll tw=ne[tu][i].w;
            if(dis[tv]>dis[tu]+tw){
                dis[tv]=dis[tu]+tw;
                Q.push({-dis[tv],tv});
            }
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>val[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        ls.clear();
        for(int j=1;j<=k[i];j++){
            int id,t;
            cin>>id>>t;
            ls.push_back({id,t});
        }
        for(int p=0;p<ls.size();p++){
            for(int q=p+1;q<ls.size();q++){
                int u=ls[p].first;
                int v=ls[q].first;
                ll w=ls[p].second+ls[q].second;
                e[u].push_back({v,w});
                e[v].push_back({u,w});
            }
        }
    }
    for(int i=1;i<=m;i++){
        sort(e[i].begin(),e[i].end(),cmp);
        for(int j=0;j<e[i].size();j++){
            if(j==0) ne[i].push_back(e[i][j]);
            else{
                if(e[i][j].v!=e[i][j-1].v) ne[i].push_back(e[i][j]);
            }
        }
    }
    while(q--){
        cin>>s>>t;
        dijkstra(s);
        ll ans=dis[t]+val[s]+val[t];
        cout<<ans<<'\n';
    }
    return 0;
}
