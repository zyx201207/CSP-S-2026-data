#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 15;
int n, m, a[maxn];
int maxv = 0;
int ans[50];
int use [maxn][50];
bool vis[maxn];
bool hs[maxn];

signed main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	for (int i = 1; i <= n; i ++)
		vis[i] = 1;
	for (int i = 1; i <= n; i++) {
		int ls = a[i], tot = 0;
		while (ls > 0) {
			use[i][++tot] = ls % 2;
			ls /= 2;
		}
	}
	for (int i = 30; i >= 1; i --) {
		for (int j = 1; j <= n; j ++)
			hs[j] = vis[j];
		for (int j = 1; j <= n; j++) {
			if (!use[j][i])
				vis[j] = false;
		}
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			cnt += vis[j];
		if (cnt < m) {
			for (int j = 1; j <= n; j++)
				vis[j] = hs[j];
			ans [i] = 0;
		} else
			ans[i] = 1;
	}
	long long pw = 1, num = 0;
	for (int i = 1; i <= 30; i ++) {
		num += ans[i] * pw;
		pw *= 2;
	}
	cout << num << endl;
	return 0;
}