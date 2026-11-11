#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
bool spA = true;
bool spB = true;
int n, m;
int a[MAXN + 7];
int chos[MAXN + 7];
bool vis[MAXN + 7];
int mx = -1;
void dfs(int x) {
	if (x == m) {
		int ans = chos[1];
		for (int i = 2; i <= m; i++) {
			ans &= chos[i];
		}
		mx = max(mx, ans);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			chos[x + 1] = a[i];
			dfs(x + 1);
			chos[x + 1] = 0;
			vis[i] = false;
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	//cout << "OK\n";
	int tisDEn = n;
	while (tisDEn != 1) {
		if (tisDEn % 2 == 1) {
			spB = false;
			//cout << "!\n";
		}
		tisDEn /= 2;
	}
	//cout << "OK\n";
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i - 1)
			spB = false;//, cout << i << '\n';
		int tis = a[i];
		while (tis) {
			if (tis % 2 == 0) {
				spA = false;
			}
			tis /= 2;
		}
	}
	//cout << "OK\n";
	if (m == 1) {
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, a[i]);
		}
		cout << ans << '\n';
		return 0;
	}
	if (m == n) {
		int ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans << '\n';
		return 0;
	}
	if (m == 2 && !spA && !spB) {
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans << '\n';
		return 0;
	}
	//if (spB)cout << "spB\n";
	if (spA == true) {
		sort(a + 1, a + n + 1);
		cout << a[n - m + 1] << '\n';
		return 0;
	}
	if (spB == true) {
		//cout << "?\n";
		cout << m * (n / m - 1) << '\n';
		return 0;
	}

	//if (m == n - 1) {
		
	//}
	dfs(0);
	//cout << "OK\n";
	cout << mx << '\n';
	
	return 0;
}
// 25 + 25 + 5
