#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500010];
int b[500010];
int q[500010];
int c[500010];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i >= 1; i--)
		q[a[i]] = max(q[a[i]], i);
	for (int j = 1; j <= n; j++) {
		memset(c, 0, sizeof(c));
		for (int i = j; i <= n; i++) {
			if (!c[a[i]])
				b[a[i]]++, c[a[i]] = 1;
			i = q[a[i]];
		}
	}
	for (int i  = 1; i <= m; i++)
		cout << b[i] << ' ';
	return 0;
}
