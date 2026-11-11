#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005], cnt = 1, maxn = -1, b[500005];

bool cmp(long long x, long long y) {
	return x >= y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		b[i + 1] = a[1] - a[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		if (i != 1 && a[i] == a[i - 1]) {
			i++;
			continue;
		}
		cnt = 1;
		int c = 0;
		for (int j = i + 1; j <= n; j++) {
			c += b[j] - b[i];
			if (c > m) {
				maxn = max(cnt, maxn);
				break;
			} else if (c == m) {
				maxn = max(cnt + 1, maxn);
				break;
			}
			cnt++;
		}
	}
	cout << maxn;
	return 0;
}
