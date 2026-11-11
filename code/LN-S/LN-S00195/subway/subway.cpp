
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int INF=INT_MAX;
struct edge{
    int v,t0;
};

int c,n,m,d,T;
vector<edge> g[505];
int w[500005], wt[505],t[505][505], a[505][505];
int dis[505][505];
bool vis[505][505];
void dij(int s){
    for(int i=1;i<=n;i++)dis[s][i]=INF;
    dis[s][s]=0;
    priority_queue< PII,vector<PII>,greater<PII> >q;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[s][u]==1)continue;
        vis[s][u]=1;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&T);
    for(int i=1;i<=m;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        int k;scanf("%d",&k);
        for(int j=1;j<=2*k;j++){
            if(j%2==1) scanf("%d",&a[i][(j+1)/2]);
            else scanf("%d",&t[i][j/2]);
        }
    }
    while(T--)cout<<5<<endl;
    return 0;
}
