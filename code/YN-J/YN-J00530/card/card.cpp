#include <bits/stdc++.h>
using namespace std;
#define int long long
queue<int>qq;
int a[300005], c[300005];
int b[300005];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	int o = 0;
	for (int i = 1; i <= n; i++) {
		cout << i;
	}
	return 0;
}
