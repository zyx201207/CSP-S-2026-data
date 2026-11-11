#include<bits/stdc++.h>
using namespace std;
long long w[50005];
long long x,y;
long long c,n,m,d,q;//c 表示测试点编号、n 地铁线路数、m 地铁站数、d 每个地铁站最多被几条线路经过,q 以及出行计划数
struct node{
    long long id,t;
}a[505][50005];
long long k[505];
long long geshu[50005][25];
bool vis[50005];
long long dfs(long long u,long long o){
    if(u==y){
        return 0;
    }
    vis[u]=1;
    long long minn=INT_MAX;
    for(long long i=1;i<=geshu[u][0];i++){
        long long pe=0;
        for(long long j=1;j<=k[geshu[u][i]];j++){
            if(a[geshu[u][i]][j].id==u){
               pe=j;
               break;
            }
        }
        for(long long j=1;j<=k[geshu[u][i]];j++){
            if(a[geshu[u][i]][j].id==y){
                minn=a[geshu[u][i]][j].t+a[geshu[u][i]][pe].t;
                break;
            }
            if(a[geshu[u][i]][j].id!=u&&geshu[u][i]!=o&&vis[a[geshu[u][i]][j].id]==0){
                minn=min(minn,dfs(a[geshu[u][i]][j].id,geshu[u][i])+a[geshu[u][i]][j].t+a[geshu[u][i]][pe].t);
            }
        }
    }
    vis[u]=0;
    return minn;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];//每个地铁站的地铁口走到站厅需要的时间
    }
    for(long long i=1;i<=n;i++){
        cin>>k[i];//第 i 条线路经过的地铁站数
        for(long long j=1;j<=k[i];j++){
            cin>>a[i][j].id;//表示第 i 条线路经过的第 j 个地铁站
            cin>>a[i][j].t;//从该地铁站的站厅走到第 i 条线路的站台需要的时间
            geshu[a[i][j].id][0]++;
            geshu[a[i][j].id][geshu[a[i][j].id][0]]=i;
        }
    }
    while(q--){
        cin>>x>>y;//x 起点 y 终点
        cout<<dfs(x,-1)+w[x]+w[y]<<"\n";
    }
    return 0;
}
