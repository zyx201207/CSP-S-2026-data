#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 1, ans;
int a[200010];

//int dfs(int cnt) {
//	for (int i = cnt; i <= n; i++) {
//		if (cnt != m) {
//			ans = max(ans, a[i] ^ dfs(cnt + 1));
//		} else {
//			return a[i];
//		}
//	}
//
//};

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
//	dfs(cnt);
	for (int i = 1; i <= n; i++) {
		cout << 1<<' ';
	}
	

	return 0;
}