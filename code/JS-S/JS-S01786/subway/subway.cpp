#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,INF=1e14;
int w[M],k[N],d[N][N];
struct Edge{
    int L,t;
};
vector<Edge>e[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,n,m,D,q,x,y;
    cin>>c>>n>>m>>D>>q;
    for(int i=1;i<=m;++i) cin>>w[i];
    for(int i=1;i<=n;++i){
        cin>>k[i];
        for(int j=1;j<=k[i];++j){
            cin>>x>>y;
            e[x].push_back(Edge{i,y});
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=j)
                d[i][j]=INF;
    for(int i=1;i<=m;++i){
        for(int j=0;j<e[i].size()-1;++j){
            for(int k=j+1;k<e[i].size();++k){
                x=e[i][j].L;y=e[i][k].L;
                d[x][y]=min(d[x][y],e[i][j].t+e[i][k].t);
                d[y][x]=d[x][y];
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    while(q--){
        cin>>x>>y;
        int ans=1e18,X,Y;
        for(int i=0;i<e[x].size();++i){
            for(int j=0;j<e[y].size();++j){
                X=e[x][i].L;Y=e[y][j].L;
                ans=min(ans,e[x][i].t+e[y][j].t+d[X][Y]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
//71minAC
