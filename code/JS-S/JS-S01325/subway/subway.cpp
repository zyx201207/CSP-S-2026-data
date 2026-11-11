#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N=505;
const int M=5e5+5;
int w[M];
vector<pair<int,int>> P[M];//xianlu pair<id,t>
vector<int> G[N];//duixianlujiant
int f[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;++i)
        cin>>w[i];
    for (int i=1;i<=n;++i){
        int k,a,t,tmp=0;
        cin>>k;
        for (int j=1;j<=k;++j){
            cin>>a>>t;
            P[a].push_back({i,t});
        }
    }
    memset(f,0x3f,sizeof(f));
    for (int i=1;i<=n;++i)
        f[i][i]=0;
    for (int i=1;i<=m;++i){
        for (int j=0;j<P[i].size();++j)
            for (int k=0;k<P[i].size();++k)
                f[P[i][j].first][P[i][k].first]=min(f[P[i][j].first][P[i][k].first],P[i][j].second+P[i][k].second);
    }
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        int ans=LLONG_MAX;
        for (int i=0;i<P[x].size();++i)
            for (int j=0;j<P[y].size();++j)
                ans=min(ans,f[P[x][i].first][P[y][j].first]+P[x][i].second+P[y][j].second);
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}