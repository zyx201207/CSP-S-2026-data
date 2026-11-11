#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,x[500005];
vector<pair<int,int>>g[500005];
int dp[500005];
int dist[505000];
bool vis[505000];
struct node{
    int dis,u;
};
bool operator < (node a,node b){
    return a.dis>b.dis;
}
void dijkstra(int s){
    priority_queue<node>q;
    for(int i=1;i<=n;i++){
        vis[i]=false;
        dist[i]=INT_MAX;
        dp[i]=0;
    }
    dist[s]=0;
    q.push({0,s});
    dp[s]=1;
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<(int)g[u].size();i++){
            int w=g[u][i].second,v=g[u][i].first;
            if(dist[v]>dist[u]+w){
                dp[v]=dp[u];
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
            else if(dist[v]==dist[u]+w){
                dp[v]+=dp[u];
            }
        }
    }
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j!=i&&abs(x[j]-x[i])<=d){
                g[i].push_back({j,1});
            }
        }
    }
    int cnt=0;
    for(int s=1;s<=n;s++){
        dijkstra(s);
        for(int i=1;i<=n;i++){
            if(dp[i]==2){
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
}
int main(){
    freopen("mlgrate.in","r",stdin);
    freopen("mlgrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
