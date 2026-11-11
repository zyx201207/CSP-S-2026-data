#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,M=5e5+5+N;
int c,n,m,d,q,x,y;
ll w[M],k,a,t,dis[N][N],ans;
basic_string<pair<int,ll>>e[N];
basic_string<int>crxl[M];
priority_queue<pair<ll,int>>pq;
unordered_map<int,ll>xl[N];
bitset<N>vis;
int main(){
    freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)cin >> w[i];
    for(int i=1;i<=n;i++){
        cin >> k;
        for(int j=1;j<=k;j++)cin >> a >> t,xl[i][a]=t,crxl[a]+=i;
    }
    for(int i=1;i<=m;i++)for(int x:crxl[i])for(int y:crxl[i])if(x!=y)e[x]+={y,xl[x][i]+xl[y][i]};
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=1e17;
    for(int i=1;i<=n;i++){
        dis[i][i]=0,vis.reset(),pq.emplace(0,i);
        while(!pq.empty()){
            int u=pq.top().second;pq.pop();
            if(vis[u])continue;
            vis[u]=1;
            for(auto[v,w]:e[u])if(dis[i][v]>dis[i][u]+w)dis[i][v]=dis[i][u]+w,pq.emplace(-dis[i][v],v);
        }
    }
    while(q--){
        cin >> x >> y,ans=LLONG_MAX;
        for(int i:crxl[x])for(int j:crxl[y])ans=min(ans,xl[i][x]+xl[j][y]+dis[i][j]);
        cout << w[x]+w[y]+ans << '\n';
    }
    return 0;
}