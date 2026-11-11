#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 5e5 + 5;

int n;
long long m, a[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	int lst = 1, ans = 1;
	long long sum = 0;
	for (int i = 2; i <= n; i++) {
		sum += (a[i] - a[i - 1]) * (i - lst);
		while (sum > m) {
			sum -= a[i] - a[lst++];
		}
		ans = max(ans, i - lst + 1);
	}
	cout << ans << endl;

	return 0;
}