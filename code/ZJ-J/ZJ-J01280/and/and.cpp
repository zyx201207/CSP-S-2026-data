#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
long long sum, mx = -4e18, sm, mb, x;
long long a[200006];
long long dp[200006];
long long t[200005];
string s[200006], ans[200006];
void dfs(int now) {
	int smm = 0;
	for (int i = 1; i <= x; i++) {
		smm += (ans[i][now] == '1' ? 1 : 0);
	}	
	if (smm == m or now >= mx) {
			int anss = 0;
			for (int j = 0; j <= sm; j++) {
				anss += (ans[1][j] == '1' ? 1 : 0) * pow(2, (sm - j - 1));
			}
			for (int i = 1; i <= m; i++) {
				//cout << ans[i] << endl;
				int summ = 0;
				for (int j = 0; j < sm; j++) {
					summ += (ans[i][j] == '1' ? 1 : 0) * pow(2, (sm - j - 1));
				}
				//cout << summ << endl;
				anss = (anss & summ);
			}
			cout << anss;
			return;
		}
	string ss[200005] = {""};
	int nx = 0;
	for (int i = 1; i <= x; i++) {
		if (ans[i][now - 1] == '1') {
			nx++;
			ss[nx] = ans[i];
		}
	}
	for (int i = 1; i <= nx; i++) {
		ans[i] = ss[i];
		//cout << ans[i] << endl;
	}
	x = nx;
	dfs(now + 1);
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	sum = a[1];
	for (int i = 2; i <= n; i++) {
		sum = (sum & a[i]);
	}
	if (m == n) {
		cout << sum;
		return 0;
	}
	if (m == 1) {
		cout << mx;
		return 0;
	}
	while (mx) {
		mx /= 2;
		sm++;
	}
	for (int i = 1; i <= n; i++) {
		int tt = a[i];
		while (tt) {
			s[i] = (tt % 2 == 1 ? '1' : '0') + s[i];
			tt /= 2;
		}
		while (s[i].size() < sm) s[i] = '0' + s[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sm; j++) {
			t[j + 1] += (s[i][j] == '0' ? 0 : 1);
		}
	}
	for (int i = 1; i <= sm; i++) {
		if (t[i] >= m) {
			mb = i;
			break;
		}
	}
	//cout << mb << endl;
	if (mb == 0) {
		cout << 0;
		return 0;	
	}
	for (int i = 1; i <= n; i++) {
		if (s[i][mb - 1] == '1') {
			x++;
			ans[x] = s[i];
			//cout << ans[x] << endl;
		}
	}
	dfs(mb);
	return 0;
} 
