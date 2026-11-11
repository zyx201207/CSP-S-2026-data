#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll INF=1e18;
ll c,n,m,d,q;
ll w[N];
struct Node{
    ll a,t;
};
struct Node1{
    ll x,y;
};
vector<ll> dist[505];
vector<Node> v[505];
vector<Node1> g[505];
int st,ed;
void init(){
    for(int i=0;i<n;i++){
        int l=v[i].size();
        for(int j=0;j<l;j++){
            dist[i][j]=INF;
        }
    }
    // for(auto u:g[st]){
    //     dist[u.x][u.y]=0;
    // }
}
void dfs(int x,int y){
    int l=v[x].size();
    for(int i=0;i<l;i++){
        ll cost=v[x][i].t;
        if(i==y)continue;
        if(dist[x][y]+cost>=dist[x][i])continue;
        dist[x][i]=dist[x][y]+cost;
        for(auto to:g[v[x][i].a]){
			if(to.x==x)continue;
            cost=v[to.x][to.y].t;
            if(dist[x][i]+cost>=dist[to.x][to.y])continue;
            dist[to.x][to.y]=dist[x][i]+cost;
            dfs(to.x,to.y);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        v[i].assign(k+1,Node{0,0});
        dist[i].assign(k+1,0);
        for(int j=0;j<k;j++){
            cin>>v[i][j].a>>v[i][j].t;
            g[v[i][j].a].push_back({i,j});
        }
    }
    while(q--){
        cin>>st>>ed;
        ll ans=INF;
        for(auto u:g[st]){
            init();
            dist[u.x][u.y]=v[u.x][u.y].t;
            dfs(u.x,u.y);
            for(auto to:g[ed]){
                ans=min(ans,dist[to.x][to.y]);
            }
        }
        cout<<ans+w[st]+w[ed]<<"\n";
        //cout<<ans<<"\n";
    }
    return 0;
}
