#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, m;
	cin >> n >> m;
	long long maxn = -1000000000005;
	long long minn = 1000000000005;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long ans = 0;
	for (int i = 2; i <= n; i++) {
		long long dis = 0, cnt = 0;
		for (int j = i; j >= 1; j--) {
			if (dis + abs(a[i] - a[j]) > m)
				break;
			else {
				dis += abs(a[i] - a[j]);
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}