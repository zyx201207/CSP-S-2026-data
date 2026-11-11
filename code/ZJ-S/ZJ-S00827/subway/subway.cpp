#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long n,m,d,q,w[MAXN],dp[505][505];
vector< pair<int,long long> > a[MAXN];
void solve(){
	cin>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int K;
    	cin>>K;
        for(long long j=1,a,t;j<=K;j++) cin>>a>>t,::a[a].push_back({i,t});
    } for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=(i^j?1e18:0);
    for(int i=1;i<=m;i++) for(int j=0;j<a[i].size();j++) for(int k=0;k<a[i].size();k++) dp[a[i][j].first][a[i][k].first]=min(dp[a[i][j].first][a[i][k].first],a[i][j].second+a[i][k].second);
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    while(q--){
        int x,y;
		cin>>x>>y;
        long long ans=1e18;
        for(int i=0;i<a[x].size();i++) for(int j=0;j<a[y].size();j++) ans=min(ans,a[x][i].second+a[y][j].second+dp[a[x][i].first][a[y][j].first]);
        cout<<ans+w[x]+w[y]<<"\n";
    }
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int Cid,T=1;
    cin>>Cid;
//  cin>>T;
    while(T--) solve();
    return 0;
}
