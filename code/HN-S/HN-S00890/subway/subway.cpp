#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=500005;
const ll inf=1e18;
int n,m,d,T;
ll w[M];
vector<pair<int,ll> >to[M];
ll dis[N][N];
void add_edge(int u,int v,ll w){
    dis[u][v]=min(dis[u][v],w);
    dis[v][u]=min(dis[v][u],w);
    return;
}
void Floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(dis[i][k]==inf)continue;
            for(int j=1;j<=n;j++){
                if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
    return;
}
ll solve(int x,int y){
    ll ans=inf;
    for(int i=0;i<(int)to[x].size();i++){
        for(int j=0;j<(int)to[y].size();j++){
            ans=min(ans,dis[to[x][i].first][to[y][j].first]+to[x][i].second+to[y][j].second);
        }
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int csd;cin>>csd;
    cin>>n>>m>>d>>T;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int x;ll y;cin>>x>>y;
            to[x].push_back({i,y});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)dis[i][j]=inf;
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int len=to[i].size();
        for(int j=0;j<len;j++){
            for(int k=j+1;k<len;k++){
                add_edge(to[i][j].first,to[i][k].first,to[i][j].second+to[i][k].second);
            }
        }
    }
    Floyd();
    while(T--){
        int x,y;cin>>x>>y;
        cout<<solve(x,y)+w[x]+w[y]<<"\n";
    }
    return 0;
}