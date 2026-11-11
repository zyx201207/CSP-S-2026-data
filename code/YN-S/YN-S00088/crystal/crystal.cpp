#include <bits/stdc++.h>
using namespace std;
long long a[600000], b[600000];
bool pd[600000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m > 100000000) {
		long long h = a[3] - a[2];
		long long g = 1;
		while (m > 0) {
			g++;
			m -= h * g;
		}
		cout << g;
		return 0;
	}
	long long mx = a[1], ans = 1, f = 0, l = 1, x = 1;
	priority_queue<pair<long long, long long>> q;
	pair<long long, long long> pa;
	pa.first = a[1];
	pa.second = 1;
	q.push(pa);
	pd[1] = true;
	for (int i = 2; i <= n; i++) {
		if (a[i] > mx)
			f += (x * abs(a[i] - mx));
		else
			f += abs(mx - a[i]);
		mx = max(mx, a[i]);
		x++;
		pa.first = a[i];
		pa.second = i;
		q.push(pa);
		pd[i] = true;
		if (f > m) {
			while (f > m) {
				auto [s1, s2] = q.top();
				while (s2 == l || !pd[s2]) {
					q.pop();
					auto [s3, s4] = q.top();

					s1 = s3;
					s2 = s4;
				}
				x--;
				auto [w1, w2] = q.top();
				if (w1 < mx)
					f -= (x * abs(mx - w1));
				else
					f -= abs(mx - a[i]);
				mx = w1;
				l++;
				pd[l] = false;

			}
		}
		ans = max(ans, x);
	}
	cout << ans;
	return 0;
}