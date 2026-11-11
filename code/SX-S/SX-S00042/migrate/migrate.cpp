#include <bits/stdc++.h>
#define int long long
using namespace std;
int h[20000010];
int n, d;

int dfs(int st, int end, int s) {
	for (int i = st + 1; i < end; i++) {
		if (h[i] - h[st] <= d && h[end] - h[i] <= d) {
			s++;
		}
	}
	return s;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> h[j];
		}
		int s = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + d + 1; j <= n; j++) {
				int a = dfs(i, j, 0);
				if (a == 2) {
					s++;
				}
			}
		}
		cout << s << endl;
	}
	return 0;
}
