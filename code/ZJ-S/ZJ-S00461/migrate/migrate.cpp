#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, dd, x[100], mp[100][100], d[100][100], bin[100];
vector <int> tmp;
void solve() {
	cin >> n >> dd;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) d[i][j] = 1e18, mp[i][j] = 0;
	}
	for(int i = 1; i <= n; i++) d[i][i] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(x[j] - x[i] <= dd) mp[i][j] = d[i][j] = 1;
			else d[i][j] = 1e18;
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int tot = 0;
			for(int S = 0; S < (1 << n); S++) {
				tmp.clear();
				for(int k = 1; k <= n; k++) {
					if(S & (1 << (k - 1))) tmp.push_back(k), bin[k] = 1;
					else bin[k] = 0;
				}
				if(!bin[i] || !bin[j]) continue;
				if(tmp.size() - 1 != d[i][j]) continue;
				bool flg = 1;
				for(int k = 1; k < (int)tmp.size(); k++) {
					if(!mp[tmp[k - 1]][tmp[k]])  flg =0 ;
				}
				if(flg) tot++;
			}
			if(tot == 2) ans++;
		}
	}
	cout << ans << "\n";
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, T;
	cin >> c >> T;
	if(c <= 2) {
		while(T--) solve();
	}
	return 0;
}
