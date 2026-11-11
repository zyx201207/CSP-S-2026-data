#include <bits/stdc++.h>
using namespace std;

int n, ans = 1;
long long m;

bool cmp(int t, int y) {
	return t < y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long a[n + 10] = {};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		long long x = m;
		int cnt = 1, num = 1, news = a[i];
		for (int j = i + 1; x >= 0; j++) {
			if (a[j] != a[j - 1]) {
				x -= (a[j] - news ) * num;
				news = a[j];
				num++;
			} else if (x - (a[j] - news ) * num >= 0) {
				num++;
			} else {
				cnt += num + 1;
				break;
			}
			if (x >= 0) {
				cnt++;
			}
			if (i + cnt > n) {
				break;
			}
		}
		ans = max(cnt, ans);
	}
	cout << ans;
	return 0;
}
