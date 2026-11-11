#include <bits/stdc++.h>
using namespace std;
int n, d, a[2000005], sum = 0;
map<string, bool> mp;

//int zzz(int x, int y, int cnt) {
//	if (x == y)
//		return cnt;
//	for (int i = x + 1; i <= y; i++) {
//		if (a[x] + d < a[i]) {
//			zzz(i - 1, y, cnt + 1);
//		}
//	}
//}

void dfs(int x, int y, string s, int jj, int cnt) {
	if (x == y) {
		if (!mp.count(s) && cnt <= jj) {
//			cout << s << endl;
			sum++;
			return;
		}
	}
	for (int i = x + 1; i <= y; i++) {
		if (a[x] + d >= a[i]) {
			dfs(i, y, s + char(i + '0'), jj, cnt + 1);
		}
	}
}

void solve() {
	int ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 3; j <= n; j++) {
			sum = 0;
			mp.clear();
//			int _z = zzz(i, j, 0);
//			cout << _z << ' ';
			dfs(i, j, "", 1e9, 0);
//			cout << i << ' ' << j << ' ' << sum << endl;
			if (sum == 2) {
//				cout << i << ' ' << j << endl;
				ans++;
			}
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int C, T;
	cin >> C >> T;
	while (T--) {
		solve();
	}
	return 0;
}
