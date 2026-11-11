#include <bits/stdc++.h>
using namespace std;

namespace{
const int N=5e5+5;
int w[N];
vector<pair<int,int>>g[N];
using ll=long long;
ll dis[505][505];
void solve(){
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,a,t;j<=k;j++){
            cin>>a>>t;
            g[a].emplace_back(i,t);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++)for(const auto &[x,a]:g[i])for(const auto &[y,b]:g[i])if(x!=y)dis[x][y]=min(dis[x][y],(ll)a+b);
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x,y;
        cin>>x>>y;
        ll ans=0x7f7f7f7f7f7f7f7f;
        for(const auto &[u,a]:g[x])for(const auto &[v,b]:g[y])ans=min(ans,dis[u][v]+a+b);
        ans+=w[x]+w[y];
        cout<<ans<<'\n';
    }
}
}


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}