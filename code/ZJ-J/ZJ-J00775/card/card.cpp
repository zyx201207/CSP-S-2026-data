#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int M = 3e5 + 10;

int n, m;
int ans[M], a[N], b[N], c[M];
bool flag, z[N];

void solve1 () {
	for (int i = 1; i <= n; i++) {
		ans[a[i]] = i;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return ;
}

void solve2 () {
	for (int t = 1; t <= n; t++) {
		for (int i = t; i <= n; i++)
			z[a[i]] = false, b[i] = false;
		for (int i = t; i <= n; i++) {
			if (!z[a[i]]) {
				z[a[i]] = true;
				c[a[i]] = i;
			}
			else {
				for (int j = c[a[i]]; j < i; j++)
					z[a[j]] = false, c[a[j]] = 0, b[j] = true;
				z[a[i]] = true;
			}
		}
		for (int i = t; i <= n; i++)
			ans[a[i]] += !b[i];
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return ;
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	flag = true;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1])
			flag = false;
	}
	if (flag)
		solve1 ();
	else
		solve2 ();
	return 0;
}