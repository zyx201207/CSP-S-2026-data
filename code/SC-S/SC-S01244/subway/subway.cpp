#include<bits/stdc++.h>
using namespace std;
const int N=509,M=500009;
struct state{
    int line,dep;
};
vector<state>station[M];
int c,n,m,d,q,w[M];
long long dis[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k,a,t;cin>>k;
        for(int j=1;j<=k;j++)cin>>a>>t,station[a].push_back({i,t});
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)dis[i][j]=9e18;
    for(int i=1;i<=m;i++)
        for(int j=0;j<(int)station[i].size()-1;j++)
            for(int k=j+1;k<(int)station[i].size();k++)
                dis[station[i][k].line][station[i][j].line]=dis[station[i][j].line][station[i][k].line]=
                min(dis[station[i][j].line][station[i][k].line],(long long)station[i][j].dep+station[i][k].dep);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][k]<9e18&&dis[k][j]<9e18)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int u,v;q--;){
        cin>>u>>v;
        long long res=9e18;
        for(int i=0;i<(int)station[u].size();i++)
            for(int j=0;j<(int)station[v].size();j++)
                res=min(res,station[u][i].dep+dis[station[u][i].line][station[v][j].line]+station[v][j].dep);
        cout<<w[u]+res+w[v]<<'\n';
    }
}