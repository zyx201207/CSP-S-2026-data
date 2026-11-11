#include <bits/stdc++.h>
using namespace std;
long long a[200005], ans = 0;
int n, m;
bool vis[200005], t1[105], t2[105], t3[105];

long long awy(long long a, long long b) {
	long long a1 = a, b1 = b, fh = 0;
	int t1s = 0, t2s = 0;
	for (int i = 1; i <= 30; i++) {
		t1[i] = 0;
		t2[i] = 0;
		t3[i] = 0;
	}
	while (a1 != 0) {
		t1s++;
		t1[t1s] = a1 % 2;
		a1 /= 2;
	}
	while (b1 != 0) {
		t2s++;
		t2[t2s] = b1 % 2;
		b1 /= 2;
	}
	for (int i = min(t1s, t2s); i >= 1; i--) {
		if ((t1[i] == 1 && t2[i] == 0) || (t1[i] == 0 && t2[i] == 1))
			t3[i] = 1;
	}
	for (int i = 1; i <= min(t1s, t2s); i++) {
		fh *= 2;
		fh += t3[i];
	}
	return fh;
}

void dfs(int r, long long z) {
	if (r == m && z > ans) {
		ans = z;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			dfs(r + 1, awy(z, a[i]));
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(0, LONG_LONG_MAX);
	cout << ans;
	return 0;
}
