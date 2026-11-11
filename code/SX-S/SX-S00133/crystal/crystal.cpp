#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n, m;
long long a[500010], b[200010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);

	long long l = 2, r = n - 1;
	long long dl = a[2] - a[1], dr = a[n] - a[n - 1];
	while (l != r) {
		if (dl > dr) {
			r--;
			dr += (a[r + 1] - a[r]);
		} else {
			l++;
			dl += (a[l] - a[l - 1]);
		}
	}

	for (int i = 1; i <= n; i++) {
		b[i] = abs(a[i] - a[l]);
	}

	sort(b + 1, b + 1 + n);
	int sum = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (sum + b[i] < m) {
			sum += b[i], ans++;
		} else if (sum + b[i] == m) {
			ans++;
			break;
		} else
			break;
	}
	cout << ans;
	return 0;
}