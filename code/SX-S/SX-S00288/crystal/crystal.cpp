#include <bits/stdc++.h>
using namespace std;

long long a[500100];
long long s[500100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	long long n;
	unsigned long long m = 0;
	unsigned long long ans = 1;
	queue<long long> qu;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (long long i = 1; i <= n; i++) {
		s[i] = a[i] + s[i - 1];
	}


	for (long long i = 1; i <= n; i++) {
		qu.push(i);
		if (qu.size() >= 2) {
			while (a[qu.back()] * (qu.size() - 1) - (s[qu.back() - 1] - s[qu.front() - 1]) > m) {
				qu.pop();
			}
		}

		ans = max(ans, (unsigned long long)qu.size());



	}

	cout << ans;

	return 0;
}
