#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
long long a[200005];
bool vis[200005], t1[35], t2[35];

long long awy(long long a, long long b) {
	long long a1 = 1, b1 = b;
	int t1s = 0, t2s = 0;
	while (a1 != 0) {
		t1s++;
		t1[t1s] = a1 % 2;
		a1 /= 2;
	}
	while (a1 != 0) {
		t2s++;
		t2[t2s] = b1 % 2;
		b1 /= 2;
	}
	for (int i = t1s; i >= 1; i--) {
		if (t1[i] && t)
		}
}

void dfs(int r, long long z) {
	if (r > n)
		return;
	if (r == n && z > ans) {
		ans = z;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			dfs(r - 1, z & a[i]);
		}
	}
}

int main() {
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(m, 0);
	cout << ans;
	return 0;
}