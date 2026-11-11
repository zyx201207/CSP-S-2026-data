#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],k,a,t,x,y;
long long dis[510][510],ans;
vector<pair<int,int>> vec[500010];
int main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;++i) cin>>w[i];
    for (int i=1;i<=n;++i) memset(dis[i]+1,0x3f,i-1<<3);
    for (int i=1;i<=n;++i) {
        cin>>k;
        for (int j=1;j<=k;++j) {
            cin>>a>>t;
            for (auto l:vec[a]) dis[i][l.first]=min(dis[i][l.first],(long long)(t+l.second));
            vec[a].push_back({i,t});
        }
    }
    for (int i=1;i<=n;++i) for (int j=i+1;j<=n;++j) dis[i][j]=dis[j][i];
    for (int k=1;k<=n;++k) for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for (int i=1;i<=q;++i) {
        cin>>x>>y;
        ans=1e18;
        for (auto j:vec[x]) for (auto k:vec[y]) ans=min(ans,w[x]+w[y]+dis[j.first][k.first]+j.second+k.second);
        cout<<ans<<'\n';
    }
}