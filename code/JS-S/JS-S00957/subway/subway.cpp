#include<bits/stdc++.h>
using namespace std;
const int N=507,M=5e5+7;
int c,n,m,d,q,wsta[M],w[N][M],st,ed;
long long ans;
bool vis[N][M];
vector<int> vt[N];
void init(){
    scanf("%d%d%d%d",&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
      scanf("%d",&wsta[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            int v;
            scanf("%d",&v);
            scanf("%d",&w[i][j]);
            vt[i].push_back(v);
        }
    }
}
void dfs(int xianlu,int sta,long long sum){
    if(vt[xianlu][sta]==ed){
        ans=min(ans,sum+w[xianlu][sta]);
        return;
    }
    if(vis[xianlu][sta]) return;
    vis[xianlu][sta]=1;
    for(int i=1;i<=n;i++)
      for(int j=0;j<vt[i].size();j++)
        if(vt[i][j]==vt[xianlu][sta]) dfs(i,j,sum+w[xianlu][sta]);
    if(sta<vt[xianlu].size()-1)dfs(xianlu,sta+1,sum+w[xianlu][sta]);
    if(sta>0) dfs(xianlu,sta-1,sum+w[xianlu][sta]);
}
void work2(){
    memset(vis,0,sizeof(vis));
    ans=1e18;
    scanf("%d%d",&st,&ed);
    for(int i=1;i<=n;i++)
      for(int j=0;j<vt[i].size();j++)
        if(vt[i][j]==st) dfs(i,j,0);
    printf("%lld\n",ans+wsta[st]+wsta[ed]);
}
void work(){
    while(q--)
      work2();
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    while(cin>>c){
        init();
        work();
    }
    return 0;
}
