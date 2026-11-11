#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=5e5+6,M=5e2+6;
int c,n,m,D,Q,w[N],len[M];
ll d[M][M];
vector<pair<int,ll> > e[N];
void floyd() {
    for (int k=1;k<=n;++k) for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
void Solve () {
    cin>>c>>n>>m>>D>>Q;
    for (int i=1;i<=m;++i) cin>>w[i];
    for (int i=1;i<=n;++i) {
        cin>>len[i];
        for (int j=1;j<=len[i];++j) {
            int x,y; cin>>x>>y;
            e[x].push_back({i,y});
        }
    }
    for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) d[i][j]=1e18;
    for (int i=1;i<=m;++i) for (int j=0;j<e[i].size();++j) for (int k=j+1;k<e[i].size();++k) d[e[i][j].first][e[i][k].first]=d[e[i][k].first][e[i][j].first]=min(d[e[i][j].first][e[i][k].first],e[i][j].second+e[i][k].second);
	for (int i=1;i<=n;++i) d[i][i]=0;
    floyd();
    for (int i=1;i<=Q;++i) {
        int s,t; cin>>s>>t;
        ll ans=w[s]+w[t],res=1e18;
        for (int j=0;j<e[s].size();++j) for (int k=0;k<e[t].size();++k) res=min(res,e[s][j].second+d[e[s][j].first][e[t][k].first]+e[t][k].second);
        cout<<ans+res<<"\n";
    }
} 
signed main() {
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T=1; //cin>>T;
    while (T--) Solve();
    return 0;
}
//容易发现,我们只需要计算两个地铁线路间的最小换乘时间，然后对于s,t枚举从哪个线路出发即可
//计算换乘时间可以md^2,这样可以在线路间floyd
//复杂度qd^2+md^2,约2.4e8
