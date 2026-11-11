#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], mmax = INT_MIN, num, cnt = 1, p;
queue<long long> q;

int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	stable_sort(a + 1, a + n + 1);
	q.push(a[1]);
	for (long long i = 2; i <= n; i++) {
		if (num + cnt * (a[i] - a[i - 1]) <= m) {
			num += cnt * (a[i] - a[i - 1]);
			cnt++;
		} else {
			mmax = max(mmax, cnt);
			while (!q.empty() && num + cnt * (a[i] - a[i - 1]) > m) {
				num -= a[i - 1] - q.front();
				cnt--;
				q.pop();
			}
			num += cnt * (a[i] - a[i - 1]);
			cnt++;
		}
		q.push(a[i]);
	}
	mmax = max(mmax, cnt);
	cout << mmax;

	return 0;
}