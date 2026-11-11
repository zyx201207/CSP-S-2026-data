#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[500005],f[501][501];
vector<pair<int,int> > dd[500005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			f[i][j] = 1e18;
		}
		f[i][i] = 0;
	}
	for (int i = 1;i <= n;i++){
		int kk;
		cin >> kk;
		for (int j = 1;j <= kk;j++){
			int a,b;
			cin >> a >> b;
			dd[a].push_back({i,b});
		}
	}
	for (int i = 1;i <= m;i++){
		int le = dd[i].size();
		for (int j = 0;j < le;j++){
			for (int k = 0;k < le;k++){
				if (j == k){
					continue;
				}
				f[dd[i][j].first][dd[i][k].first] = min(f[dd[i][j].first][dd[i][k].first],dd[i][j].second + dd[i][k].second);
			}
		}
	}
	for (int k = 1;k <= n;k++){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++){
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	while (q--){
		int xr,yr;
		cin >> xr >> yr;
		int ans = 1e18;
		int l1 = dd[xr].size(),l2 = dd[yr].size();
		for (int i = 0;i < l1;i++){
			for (int j = 0;j < l2;j++){
				ans = min(ans,dd[xr][i].second + f[dd[xr][i].first][dd[yr][j].first] + dd[yr][j].second);
			}
		}
		cout << ans + w[xr] + w[yr] << "\n";
	}
	return 0;
}
