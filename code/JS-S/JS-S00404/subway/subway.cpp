#include<bits/stdc++.h>
using namespace std;
const int N=501,M=5e5+10;
long long c,n,m,d,q;
long long w[M],k[N],g[N][N],dis[N][N];
struct node{
    long long u,w;
};
struct edge{
    long long to,w;
    bool operator < (const edge& other)const{
        return w>other.w;
    }
};
vector<node>v[M];
vector<edge>e[N];
vector<long long>a[M];
map<long long,long long>mp[M];
void dijkstra(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++){
        dis[i][i]=0;
        priority_queue<edge>q;
        q.push({i,0});
        while(!q.empty()){
            edge x=q.top();q.pop();
            if(dis[i][x.to]!=x.w)continue;
            for(edge y:e[x.to]){
                if(dis[i][y.to]>dis[i][x.to]+y.w){
                    dis[i][y.to]=dis[i][x.to]+y.w;
                    q.push({y.to,dis[i][y.to]});
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            long long x,y;
            cin>>x>>y;
            a[x].push_back(i);
            v[x].push_back({i,y});
            mp[x][i]=y;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)g[i][j]=0;
            else g[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;i++){
        int num=v[i].size();
        for(int j=0;j<num;j++){
            for(int k=0;k<num;k++){
                g[v[i][j].u][v[i][k].u]=min(g[v[i][j].u][v[i][k].u],v[i][j].w+v[i][k].w);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(g[i][j]!=1e18&&i!=j)e[i].push_back({j,g[i][j]});
        }
    }
    dijkstra();
    for(int i=1;i<=q;i++){
        long long x,y;
        cin>>x>>y;
        long long ans=1e18;
        for(long long u:a[x]){
            for(long long v:a[y]){
                ans=min(ans,dis[u][v]+w[x]+w[y]+mp[x][u]+mp[y][v]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;

}
