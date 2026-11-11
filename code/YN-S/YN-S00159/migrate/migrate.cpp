#include <bits/stdc++.h>
#define maxn 2000050
#define minn 5050
#define ll long long
using namespace std;
ll a[maxn], c, t, n, d, cnt, ans;
int v[minn];
int h[minn], net[minn], to[minn];

void add(int a, int b) {
	net[++cnt] = h[a];
	to[cnt] = b;
	h[a] = cnt;
}

void dfs(int nw) {
	v[nw]++;
	for (int i = h[nw]; i; i = net[i]) {
		dfs(to[i]);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		memset(h, 0, sizeof(h));
		memset(net, 0, sizeof(net));
		memset(to, 0, sizeof(to));
		cin >> n >> d;
		for (int j = 1; j <= n; j++)
			cin >> a[j];
		if (c == 11 || c == 12) {
			int dis = a[2] - a[1];
			if (dis * 2 <= d) {
				if (n >= 2)
					cout << n - 2 << "\n";
				else
					cout << "0\n";
			} else
				cout << "0\n";
		} else if (c == 13 || c == 14) {
			if (n >= 2)
				cout << n - 2 << "\n";
			else
				cout << "0\n";
		} else {
			for (int i = 1; i <= n - 1; i++) {
				for (int j = i + 1; j <= n; j++) {
					if (a[j] - a[i] <= d) {
						add(i, j);
					} else
						break;
				}
			}
			for (int i = 1; i <= n; i++) {
				memset(v, 0, sizeof(v));
				dfs(i);
				for (int j = 1; j <= n; j++) {
					if (v[j] == 2)
						ans++;
				}
			}
			cout << ans / 2 + 1 << "\n";
		}
	}
	return 0;
}