#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5e2+10;
long long c,n,m,d,q,a[N],vis[N],dis[N],dp[1050][1050];//1~m zhan m+1~m+1+n xu ni dian
vector<pair<int,long long>>g[N];
void dfs(int st){
    for(int i=1;i<=n+m;i++){
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
        for(auto i:g[u]){
            long long v=i.first,w=i.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u,w,v=i+m;
            cin>>u>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
    }
    for(int i=1;i<=m;i++){
        dfs(i);
        for(int j=1;j<=m;j++){
            dp[i][j]=dis[j]+a[i]+a[j];
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<dp[u][v]<<'\n';
    }
    return 0;
}
