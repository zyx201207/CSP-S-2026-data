#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
ll g[N][N];
int n,tc,m,D,Q,a[M],id[M],w[M];
vector<pair<int,int>> vc[M];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>tc>>n>>m>>D>>Q;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)g[i][j]=(ll)1e18;
    for(int i=1;i<=n;i++){
        int ln;
        cin>>ln;
        for(int j=1;j<=ln;j++)cin>>id[j]>>w[j],vc[id[j]].push_back({i,w[j]});
    }
    for(int i=1;i<=m;i++){
        int ln=(int)vc[i].size();
        for(int j=0;j<ln;j++)for(int k=j+1,x,y;k<ln;k++){
            x=vc[i][j].first,y=vc[i][k].first;
            g[x][y]=g[y][x]=min(g[x][y],(ll)vc[i][j].second+vc[i][k].second);
        }
    }
    for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    for(int i=1;i<=Q;i++){
        int x,y;
        cin>>x>>y;
        if(x==y)cout<<"0\n";
        else{
            ll ans=(ll)1e18;
            int u=vc[x].size(),v=vc[y].size();
            for(int j=0;j<u;j++)for(int k=0;k<v;k++)ans=min(ans,g[vc[x][j].first][vc[y][k].first]+vc[x][j].second+vc[y][k].second);
            cout<<ans+a[x]+a[y]<<'\n';
        }
    }
    return 0;
}