#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m, a[N], ans;
int f[N], g[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		g[i] = max(g[i - 1], a[i]);
	for (int j = 2;j <= m; j++) {
		for (int i = j;i <= n;i++) {
			for (int k = j - 1;k < i;k++)
				f[i] = max(f[i], g[k] & a[i]);
		}
		for (int i = 1;i <= n;i++)
			g[i] = f[i], f[i] = 0;
	}
	
	for (int i = 1;i <= n;i++)
		ans = max(ans, g[i]);
	cout << ans;

	//freopen("and3.ans", "r", stdin);
	//int p;cin >> p;
	//cout << p << ' ' << ans;
	
	return 0;
}

/*

f[i][j]:前i个数中选择j个数中得到的最大值
f[1...m][1] = max(a[1...i])
f[i][j] = max(f[i - 1][j - 1] & a[i], f[i - 2][j - 1] & a[i])

*/

// WHY NOT?????!!!!!
