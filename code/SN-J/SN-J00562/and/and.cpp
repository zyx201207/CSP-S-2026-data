#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], pre[N], cnt[N], vis[N];
void DFS (int start, int step, int ans) {
	if (start >= n) return;
	if (step >= m) {
		pre[start] = max(pre[start], ans);
		return;
	}
	if (vis[start]) DFS(start + 1, step, ans);
	else {
		DFS (start + 1, step, ans);
		ans &= a[start];
		vis[start] = 1;
		DFS (start + 1, step + 1, ans);
		vis[start] = 0;
	}
}
signed main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < n; i++) {
//		int t = a[i];
//		cout << "t1=" << t  << "a[i] = " << a[i] << '\n';
//		if (i + m - 1 >= n) for (int j = i - m + 1; j <= i; j++) cout << "t=" << t << '\n', t &= a[j];
//		else for (int j = i + 1; j <= i + m - 1; j++) t &= a[j];
//		pre[i] = t;
////		if (i < m - 1) pre[i] = a[i];
////		else pre[i] = max (pre[i - m + 1] & a[i], a[i]);
//	}
//	for (int i = 0; i < n; i++) cout << a[i] << ' ';
//	cout << endl;
//	DFS(0, 0, (int)pow(2, 31) - 1);
//	cout << (int)pow(2, 31) - 1;
//	for (int i = 0; i < n; i++) cout << pre[i] << ' ';
//	cout << endl;
//	cout << *max_element(pre, pre + n);
	for (int i = 0; i < n; i++) {
		int t = 0, t2 = a[i];
		while (t2) {
			t += t2 % 2;
			t2 /= 2;
		}
		cnt[i] = t;
	}
	cout << a[*max_element(cnt, cnt + n)];
	return 0;
}
