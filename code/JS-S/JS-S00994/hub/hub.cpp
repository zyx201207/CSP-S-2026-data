#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long c,t,n,k,vis[N],dis[N];
vector<int>g[N];
void dfs(int st){
    for(int i=1;i<=n;i++){
        dis[i]=1e18;
        vis[i]=0;
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    q.push({0,st});
    dis[st]=0;
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(auto v:g[u]){
            long long w=1;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        int ans=0;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        int u=1,v=1;
        for(int i=1;i<=n;i++){
            if(dis[u]<dis[i]){
                u=i;
            }
        }
        dfs(u);
        for(int i=1;i<=n;i++){
            if(dis[v]<dis[i]){
                v=i;
            }
        }
        if(dis[v]>k){
            ans=(dis[v]-k+2)/3;
        }else if(k<n){
            ans=1;
        }else{
            ans=0;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
