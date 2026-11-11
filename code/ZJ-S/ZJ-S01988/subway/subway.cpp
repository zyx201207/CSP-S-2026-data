#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5010;
int a[MAXN],t[MAXN];
int w[MAXN];
int d[MAXN][MAXN];
int t1[MAXN],t2[MAXN];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,y,q;
	cin >> c >> n >> m >> y >> q;
	
	
	if (c != 20 && c != 21) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				d[i][j] = 1e9;
			}
		}
		for (int i = 1; i <= m; i++) {
			d[i][i] = 0;
		}
		for (int i = 1; i <= m; i++) {
			cin >> w[i];
		}
		for (int x = 1; x <= n; x++) {
			int p;
			cin >> p;
			for (int j = 1; j <= p; j++) {
				cin >> a[j] >> t[j];
			}
			for (int i = 1; i <= p; i++) {
				for (int j = 1; j <= p; j++) {
					d[a[i]][a[j]] = min(d[a[i]][a[j]],t[i] + t[j]);
				}
			}
		}
		for (int k = 1; k <= m; k++) {
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= m; j++) {
					d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
				}
			}
		}
		while(q--) {
			int u,v;
			cin >> u >> v;
			cout << w[u] + w[v] + min(d[u][v],d[v][u]) << '\n';
		}
	}
	
	
	else if (c == 20 || c == 21){
		for (int i = 1; i <= m; i++) {
			cin >> w[i];
		}
		for (int x = 1; x <= n; x++) {
			int p;
			cin >> p;
			for (int j = 1; j <= p; j++) {
				cin >> a[j] >> t[j];
				if (x == 1){
					t1[a[j]] = t[j];
				}
				else{
					t2[a[j]] = t[j];
				}
			}
		}
		int minn = 1e9;
		for (int i = 1; i <= m; i++){
			if (t1[i] && t2[i]){
				minn = min(minn,t1[i] + t2[i]);
			}
		}
		while(q--){
			int u,v;
			cin >> u >> v;
			int ans = 1e9;
			if (t1[u] && t1[v]){
				ans = min(ans,t1[u] + t1[v]);
			}
			if (t2[u] && t2[v]){
				ans = min(ans,t2[u] + t2[v]);
			}
			if (t1[u] && t2[v]){
				ans = min(ans,minn + t1[u] + t2[v]);
			}
			if (t2[u] && t1[v]){
				ans = min(ans,minn + t2[u] + t1[v]);
			}
			cout << ans + w[u] + w[v] << '\n';
		}
	}
	
	
	return 0;
}
