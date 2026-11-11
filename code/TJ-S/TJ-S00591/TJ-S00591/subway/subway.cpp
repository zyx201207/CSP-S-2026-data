#include<bits/stdc++.h>
#define int long long
#define cen cout << "\n"
#define cs cout << " "
using namespace std;
const int N=509,M=5e5+9;
int w[M],dp[N][N];
vector<pair<int,int> > belong[M];
int Min(int a,int b){return a>b?b:a;}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,n,m,d,q;cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++){
		int len;cin >> len;
		for(int j=1;j<=len;j++){
			int a,t;cin >> a >> t;
			belong[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=4e18;
	for(int k=1;k<=m;++k){
		int len=belong[k].size();
		for(int i=0;i<len;++i)for(int j=i+1;j<len;++j)dp[belong[k][j].first][belong[k][i].first]=dp[belong[k][i].first][belong[k][j].first]=Min(dp[belong[k][i].first][belong[k][j].first],belong[k][i].second+belong[k][j].second);
	}
	for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dp[i][j]=Min(dp[i][j],dp[i][k]+dp[k][j]);
	for(int i=1;i<=n;++i)dp[i][i]=0;
	while(q--){
		int l,r;cin >> l >> r;
		int ans=4e18;
		for(int i=0;i<belong[l].size();++i)for(int j=0;j<belong[r].size();++j){
			ans=Min(ans,dp[belong[l][i].first][belong[r][j].first]+belong[l][i].second+belong[r][j].second);
		}
		cout << ans+w[l]+w[r];
		cen;
	}
	return 0;
}
/*
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
放我T2过 pls pls pls 放我T2过 pls pls pls 放我T2过 pls pls pls
*/




















