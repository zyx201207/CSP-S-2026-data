// author fkxr lg uid 995934
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define in cin
#define out cout
#define mset(x,k) memset(x,k,sizeof(x))
using pii=pair<int,int>;
namespace MYcode{
    const int M=5e5+5,N=505;
    int w[M],dis[N][N];
    vector<pii>e[M];//点i可以转到的地铁线
    void work(){
        int c,n,m,q,d;in>>c>>n>>m>>d>>q;
        for(int i=1;i<=m;i++)in>>w[i];
        for(int i=1;i<=n;i++){
            int k;in>>k;
            for(;k--;){
                int x,y;in>>x>>y;
                e[x].push_back({i,y});
            }
        }mset(dis,0x3f);
        for(int i=1;i<=m;i++){
            for(int a=0;a<e[i].size();a++){
                for(int b=a+1;b<e[i].size();b++){
                    int x=e[i][a].first,y=e[i][b].first;
                    int d=e[i][a].second+e[i][b].second;
                    dis[x][y]=min(dis[x][y],d);
                    dis[y][x]=min(dis[y][x],d);
                }
            }
        }for(int i=1;i<=n;i++)dis[i][i]=0;
        for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        //all ok
        for(;q--;){
            int x,y;in>>x>>y;
            int ans=1e18;
            for(auto i:e[x])for(auto j:e[y]){
                int a=i.first,b=j.first;
                ans=min(ans,dis[a][b]+i.second+j.second);
            }out<<ans+w[x]+w[y]<<"\n";
        }
    }
}signed main(){
    string pid="subway";
    freopen((pid+".in").c_str(),"r",stdin);
    freopen((pid+".out").c_str(),"w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    MYcode::work();
    return 0;
}