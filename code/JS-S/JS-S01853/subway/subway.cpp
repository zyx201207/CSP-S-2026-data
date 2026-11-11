#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
typedef pair<ll,ll> PII;
ll c,n,m,d,q;
ll w[M],dis[N][N];
vector<PII> g[M];
vector<PII> e[N];
void djikstra(ll dis[],ll s){
    priority_queue<PII,vector<PII>,greater<PII>>q;
    dis[s]=0;
    q.push({0,s});
    while(q.size()){
        ll u=q.top().second;
        q.pop();
        for(auto t:e[u]){
            ll v=t.first;
            ll w=t.second;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
    
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        for(int j=1;j<=x;j++){
            ll tim,sta;
            cin>>sta;
            cin>>tim;
            g[sta].push_back({i,tim});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<g[i].size()-1;j++){
            for(int k=j+1;k<g[i].size();k++){
                ll u=g[i][j].first;
                ll v=g[i][k].first;
                ll cost=g[i][j].second+g[i][k].second;
                e[u].push_back({v,cost});
                e[v].push_back({u,cost});
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(auto t:e[i]){
    //         cout<<i<<' '<<t.first<<' '<<t.second<<'\n';
    //     }
    // }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        djikstra(dis[i],i);
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dis[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    while(q--){
        ll s,t,ans=LLONG_MAX;
        cin>>s>>t;
        for(auto a:g[s]){
            for(auto b:g[t]){
                ans=min(ans,dis[a.first][b.first]+a.second+b.second);
            }
        }
        ans+=w[t]+w[s];
        cout<<ans<<'\n';
    }
	return 0;
}
