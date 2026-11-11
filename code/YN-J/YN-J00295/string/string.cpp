#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200001];
char c[200001];

struct li {
	int aa, cc;
};
queue<li>s1;
queue<li>s2;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int sum = 0;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> c[i];
		sum += a[i];
	}

	int sum2 = 0;
	int k = sum / 2;

	for (int i = 1; i <= n; i++) {

		sum2 += a[i];

		if (sum2 > k) {
			s1.push({a[i] - sum2 + k, c[i]});
			break;
		}

		s1.push({a[i], c[i]});
	}

	sum2 = 0;

	for (int i = n; i >= 1; i--) {

		sum2 += a[i];

		if (sum2 > k) {
			s2.push({a[i] - sum2 + k, c[i]});
			break;
		}

		s2.push({a[i], c[i]});
	}

	int ans = 0;

	while (!s1.empty() && !s2.empty()) {
		while (!s1.empty() && s1.front().aa == 0) {
			s1.pop();
		}

		while (!s2.empty() && s2.front().aa == 0) {
			s2.pop();
		}

		int mid = min(s1.front().aa, s2.front().aa);

		if (s1.front().cc != s2.front().cc) {
			ans += mid;
		}

		s1.front().aa -= mid;
		s2.front().aa -= mid;
	}

	cout << ans;
	return 0;
}