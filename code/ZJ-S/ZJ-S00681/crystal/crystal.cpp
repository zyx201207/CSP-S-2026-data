#include <bits/stdc++.h>

using namespace std;

long long a[500010];
long long dq[500010];
long long l = 1, r = 0;

int main( ) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	long long n, m, sum = 0, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
//	deque<long long> dq;
//	for (int i = 1; i <= n; ++i) {
//		while (!dq.empty() && sum + dq.size() * (a[i] - dq.back()) > m) {
//			// cout << dq.front() << " " << dq.back() << "  " << sum << '\n';
//			ans = max(ans, (long long)dq.size());
//			sum -= (dq.back() - dq.front());
//			dq.pop_front();
//		}
//		if (!dq.empty()) sum += dq.size() * (a[i] - dq.back());
//		dq.push_back(a[i]);
//	}
//	cout << max(ans, (long long)dq.size());
	for (int i = 1; i <= n; ++i) {
		while (l <= r && sum + (r - l + 1) * (a[i] - dq[r]) > m) {
			ans = max(ans, r - l + 1);
			sum -= (dq[r] - dq[l]);
			l++;
		}
		if (l <= r) sum += (r - l + 1) * (a[i] - dq[r]);
		dq[++r] = a[i];
	}
	cout << max(ans, r - l + 1);
	return 0;
}