#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define pq priority_queue
#define pii pair<int,int>
#define popcount(x) __builtin_popcount(x)
#define endl '\n'
int o,T,n,d;
const int N = 2e6+10,inf=1e18;
int a[N];
vector<int>g[N];
int dis[N],vis[N],cnt[N];
void dijkstra(int s){
    for(int i=1;i<=n;i++){
        dis[i]=inf;vis[i]=0;cnt[i]=0;
    }
    dis[s]=0;cnt[s]=1;
    pq<pii,vector<pii>,greater<pii> >q;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto v:g[u]){
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                cnt[v]=cnt[u];
                q.push({dis[v],v});
            }else if(dis[v]==dis[u]+1){
                cnt[v]++;
            }
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>o>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            dijkstra(i);
            for(int j=i+1;j<=n;j++){
                //cout<<i<<"->"<<j<<":"<<dis[j]<<" "<<cnt[j]<<endl;
                ans+=(cnt[j]==2);
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
    }
    return 0;
}