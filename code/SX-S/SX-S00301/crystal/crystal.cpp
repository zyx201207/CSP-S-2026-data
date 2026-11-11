#include <bits/stdc++.h>
using namespace std;
long long n, m, a[2010], sum, ma = INT_MIN;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	priority_queue<long long> q;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (long long i = 1; i <= n; i++) {
		long long k = m;
		sum = 1;
		for (long long j = 1; j <= n; j++) {
			if (i == j)
				continue;
			long long p = a[i] - a[j];
			p = abs(p);
			if (k - p >= 0) {
				q.push(p);
				k -= p;
				sum++;
			} else if (q.top() > p) {
				k += q.top();
				k -= p;
				q.pop();
				q.push(p);
			}
		}
		ma = max(ma, sum);
	}
	cout << ma;
}