#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=404040;
ll t;
ll c,n,d;
ll a[404040];
ll ans=0;
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
ll dis[505050],vis[505050],cnt[505050];
void dijkstra(int s,int n){
    for(int i=1;i<=n;i++){
        dis[i]=1e9;
        vis[i]=0;
        cnt[i]=1;
    }
    q.push({s,0});
    dis[s]=0;
    while(!q.empty()){
        int u=q.top().u;
        int d=q.top().d;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto ed:e[u]){
            int v=ed.v,w=ed.w;
            if(dis[v]==dis[u]+w){
                cnt[v]++;
            }
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u];
                q.push({v,dis[v]});
            }
        }
    }
} 
void solve2(){
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            e[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(a[i]-a[j])<=d){
                    e[i].push_back({j,1});
                    e[j].push_back({i,1});
                }
            }
        }
        for(int i=1;i<=n;i++){
            dijkstra(i,n);
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
// g++ migrate.cpp -o migrate -std=c++14 -O2
// ./migrate