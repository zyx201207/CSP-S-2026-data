#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500007;
int c,n,m,d,q,w[N],dis[507][507],f[507][N+507];
vector<pair<int,int>>G[N+507];
void bfs(int x){
    int vis[N+507]={0};
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({x,0});
    while(!q.empty()){
        auto frt=q.top();
        q.pop();
        int u=frt.first,sum=frt.second;
        if(f[x][u]<=sum)continue;
        f[x][u]=sum;
        vis[u]=1;
        if(u<=m)dis[x][u]=sum;
        for(auto V:G[u]){
            int v=V.first,w=V.second;
            if(vis[v])continue;
            q.push({v,sum+w});
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
    for(int k,i=1;i<=n;i++){
        scanf("%lld",&k);
        for(int t,a,j=1;j<=k;j++){
            scanf("%lld%lld",&a,&t);
            G[a].push_back({i+m,t});
            G[i+m].push_back({a,t});
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m+n;j++)f[i][j]=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=m;i++)bfs(i);
    while(q--){
        int x,y;
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",dis[x][y]+w[x]+w[y]);
    }
    return 0;
}
/*
bfs
6:30
*/
