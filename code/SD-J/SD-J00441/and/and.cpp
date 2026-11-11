#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n, m;
int a[MAXN];
bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	int ans = 0;
	for (int i = 31; i >= 0; i--) {
		if ((1 << i) > a[1]) continue;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j] & (1 << i)) cnt ++;
		}
		if (cnt >= m) {
			n = min(cnt, n);
			ans += (1 << i);
		}
	}
	cout << ans << '\n';
}
