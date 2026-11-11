#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
long long n, m, a[N], b[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	long long res = -1e18;
	for (int i = 2; i <= n; i++) {
		long long t = m;
		long long l = 1, r = n;
		while (l < r)
			b[l] = a[l], b[r] = a[r], l++, r--;
		if (n % 2)
			b[(n >> 1) + 1] = a[(n >> 1) + 1];
		long long cnt = 0;
		for (int j = 1; j < i; j++) {
			if (b[i] - b[j] <= t)
				t -= (b[i] - b[j]), b[j] += (b[i] - b[j]), cnt++;
			else
				break;
		}
		res = max(res, cnt + 1);
	}
	cout << res;
	return 0;
}