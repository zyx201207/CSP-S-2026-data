#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],ans,t[505][500005],x,y,vis[500005][3],g;
vector<int>miaow[505],miao[500005];
void dfs(int u,int line,int w,bool ji){
    if(u==y){
        g=min(g,w);
        return;
    }
    if(ji)for(auto i:miao[u]){
        if(vis[i][2]==0&&i!=line){
            vis[i][2]=1;
            dfs(u,i,w+t[i][u],0);
            vis[i][2]=0;
        }
    }
    else
    for(auto i:miaow[line]){
        if(vis[i][1]==0&&i!=u){
            vis[i][1]=1;
            dfs(i,line,w+t[line][i],1);
            vis[i][1]=0;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int l=1;l<=x;l++){
            cin>>y;
            miaow[i].push_back(y);
            miao[y].push_back(i);
            cin>>t[i][y];
        }
    }
    while(q--){
        cin>>x>>y;
        g=1e9;
        vis[x][1]=1;
        dfs(x,0,w[x]+w[y],1);
        vis[x][1]=0;
        printf("%d\n",g);
    }
    return 0;
}
