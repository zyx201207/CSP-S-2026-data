#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m, ans[N], b[N], id[N], f[N];

struct str {
	int x, id;
} a[N];

int get(int x, int n) {
	for (int i = 1; i < n; i++)
		if (a[i].x == x && f[i])
			return i;
	return 0;
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x, a[i].id = i;
	}
	for (int i = 1; i <= n; i++) {
		int tmp = get(a[i].x, i);
		if (tmp > 0) {
			for (int j = tmp + 1; j < i; j++)
				f[j] = b[j] = 0;
			b[i] += tmp, f[tmp] = 0;
		} else
			b[i] -= i, f[i] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (f[i])
			b[i] += i;
	for (int i = 1; i <= n; i++) {
		b[i] += b[i - 1];
		ans[a[i].x] = max(ans[a[i].x], b[i]  + i);
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}
//ToonoHanna
