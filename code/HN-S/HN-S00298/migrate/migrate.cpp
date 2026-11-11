#include<bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000005];
vector<int> g[2000005];
long long dp[2000005];//dp[i]表示到i的最短路径条数
int dis[2000005];
void dijkstra(int s,int num){
    queue<int> pq;
    for(int i=1;i<=num;i++){
        dis[i]=0x3f3f3f3f;
        dp[i]=0;
    }
    dis[s]=0;
    dp[s]=1;
    pq.push(s);
    while(!pq.empty()){
        int u=pq.front();
        pq.pop();
        for(int v : g[u]){
            if(dis[v]==dis[u]+1)dp[v]+=dp[u];
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                dp[v]=dp[u];
                pq.push(v);
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        long long ans=0;
        int n;
        long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        //能飞到的岛建有向图
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(x[i]-x[j])<=d){
                    g[i].push_back(j);
                }
            }
        }
        for(int i=1;i<=n;i++){
            dijkstra(i,n);
            for(int j=1;j<=n;j++){
                if(dp[j]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
