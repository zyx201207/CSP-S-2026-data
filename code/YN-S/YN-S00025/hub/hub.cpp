// author fkxr lg uid 995934
#include<bits/stdc++.h>
using namespace std;
//#define int long long 
#define in cin
#define out cout
#define mset(x,k) memset(x,k,sizeof(x))
using pii=pair<int,int>;
namespace MYcode{
    const int N=1e5+5;
    vector<int>e[N];
    int s;
    bool vis[100];
    void dfs(int x){
        vis[x]=0;
        for(auto i:e[x])if(vis[i]){
            //out<<"DFSAFDDSF\n";
            dfs(i);
        }
    }int dis[100][100];
    void work(){
        int c,T;in>>c>>T;
        for(;T--;){
            int n,k;
            in>>n>>k;
            mset(dis,0x3f);
            for(int i=0;i<n;i++)e[i].clear(),dis[i][i]=0;
            for(int i=1;i<n;i++){
                int x,y;in>>x>>y;
                x--,y--;
                e[x].push_back(y);
                e[y].push_back(x);
                dis[x][y]=dis[y][x]=1;
            }int ans=n;
            for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            mset(vis,0);
            for(s=0;s<(1<<n);s++){
                if(__builtin_popcount(s)>k)continue;
                for(int i=0;i<n;i++){
                    vis[i]=((s>>i)&1);
                }int cnt=0;
                for(int i=0;i<n;i++)
                    if(vis[i]){++cnt;dfs(i);}
                if(cnt>2)continue;
                int res=0;
                for(int i=0;i<n;i++){
                    int mn=n;
                    for(int j=0;j<n;j++)if(s&(1<<j)){
                        mn=min(mn,dis[i][j]);
                    }res=max(res,mn);
                }ans=min(ans,res);
            }out<<ans<<"\n";
        }
    }
}signed main(){
    string pid="hub";
    freopen((pid+".in").c_str(),"r",stdin);
    freopen((pid+".out").c_str(),"w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    MYcode::work();
    return 0;
}
/*

*/