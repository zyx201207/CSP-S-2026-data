#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[1010110],trs[600][600],vis[1010110],f[600][600];
vector<int>a[600],t[600],bel[1010110],bt[1010110];
struct no{
    int v,x;
};
bool operator<(no a,no b){return a.x>b.x;}
priority_queue<no>qq;
vector<no>g[600];
int dij(int x,int y){
    for(int i=1;i<=n;i++){
        vis[i]=LONG_LONG_MAX-2000000000;
    }vis[x]=0;
    qq.push({x,0});
    //cout<<"ok "<<x<<" "<<y<<endl;
    while(qq.size()){
        no u=qq.top();
        qq.pop();
        //cout<<"now is "<<u.v<<" "<<u.x<<endl;
        trs[x][u.v]=trs[u.v][x]=vis[u.v];
        f[x][u.v]=f[u.v][x]=1;
        if(u.v==y)return vis[u.v];
        for(int i=0;i<g[u.v].size();i++){
            int v=g[u.v][i].v;
            //cout<<"go "<<v<<endl;
            int w=g[u.v][i].x;
            if(vis[u.v]+w<vis[v]){
                vis[v]=vis[u.v]+w;
                //cout<<"yes "<<vis[v]<<endl;
                trs[x][v]=trs[v][x]=vis[v];
                f[x][v]=f[v][x]=1;
                qq.push({v,vis[v]});
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
            if(x!=y)trs[x][y]=LONG_LONG_MAX;

    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        while(k--){
            int x,y;
            cin>>x>>y;
            a[i].push_back(x);
            t[i].push_back(y);
            for(int j=0;j<bel[x].size();j++){//*20
                trs[i][bel[x][j]]=trs[bel[x][j]][i]=min(bt[x][j]+y,trs[bel[x][j]][i]);
                //cout<<"?? "<<trs[i][bel[x][j]]<<" "<<i<<" "<<bel[x][j]<<endl;
            }
            bel[x].push_back(i);
            bt[x].push_back(y);
        }
    }
 //   for(int k=1;k<=n;k++)
   //     for(int x=1;x<=n;x++)
     //       for(int y=1;y<=n;y++)
       //         trs[x][y]=min(trs[x][k]+trs[y][k],trs[x][y]);
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
            if(trs[x][y]!=LONG_LONG_MAX&&x!=y){g[x].push_back({y,trs[x][y]})}
    while(q--){
        int x,y,ans=LONG_LONG_MAX;
        cin>>x>>y;
        if(x==y){cout<<0<<endl;continue;}
        //cout<<bel[x].size()<<" asdf "<<bel[y].size()<<endl;
        for(int i=0;i<bel[x].size();i++){
            for(int j=0;j<bel[y].size();j++){
                    if(f[bel[x][i]][bel[y][j]]==0){
                        dij(bel[x][i],bel[y][j]);
                    }//cout<<w[x]<<" "<<w[y]<<" "<<bt[x][i]<<" "<<bt[y][j]<<" "<<trs[bel[x][i]][bel[y][j]]<<" "<<bel[x][i]<<" "<<bel[y][j]<<" "<<" "<<endl;
                ans=min(ans,w[x]+w[y]+bt[x][i]+bt[y][j]+trs[bel[x][i]][bel[y][j]]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;

}/*

0 3 3 20 999
1 2 3
2 1 6 2 5
2 2 1 3 4
2 3 999 1 3



125000000




400



inclusteam xiaoheshuangpin
dcciyiyz

2026/10/31 14:30
*/
