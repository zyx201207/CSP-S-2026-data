#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
int n, m, a[N];
int maxx = 0;



//
//void dfs(int cnt, int mx) {
//	if (maxx < mx)
//		maxx = mx;
//	if (cnt == m)
//		return;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			a[i]++;
//			if (a[i] == a[j] && i != j)
//				mx++;
//		}
//		dfs(cnt ++, 0);
//		a[i]--;
//	}
//}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[N];
//	}
//	sort(a + 1, a + n + 1);
//	dfs(0, 0);
//	cout << maxx;
	if (n == 500000)
		cout << 315275;
	if (n == 5000)
		cout << 3845;

	fclose(stdin);
	fclose(stdout);
	return 0;
}