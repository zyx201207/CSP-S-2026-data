#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+10;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x*f;
}
int c, T;
ll d, a[N], dc[N];
bool dis(int x, int y) {
	return abs(a[x] - a[y]) <= d;
}
bool check(int u, int v) {
	int cnt = 0;
	for (int i = u + 1; i < v; i++) {
		if (dis(u, i) && dis(i, v))cnt++;
	}
	return cnt == 2;
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), T = read();
	while (T--) {
		int n = read();
		memset(dc, 0, sizeof(dc));
		scanf("%lld", &d);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			if (i != 1)dc[i] = a[i] - a[i - 1];
		}
		bool flag = 1;
		for (int i = 2; i < n; i++)
			if (dc[i] != dc[i + 1]) {
				flag = 0;
				break;
			}
		if (flag == 0) {
			int ans = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= i; j++)
					if (check(j, i) && !dis(j, i))ans++;
			cout << ans << endl;
		} else {
			if (d <= dc[2] + 1) {
				cout << 0 << endl;
				continue;
			} else if (d >= dc[2] * 2 && d < dc[2] * 3) {
				int ans = 0;
				cout << n - 3 << endl;
				continue;
			} else if (d >= a[n] - a[1]) {
				cout << 0 << endl;
			} else {
				int k = d / dc[2];
				cout << n - 2 * k + 1 << endl;
				continue;
			}
		}
	}
	return 0;
}