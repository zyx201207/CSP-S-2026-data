#include <bits/stdc++.h>
using namespace std;

long long a[1000001];
long long ai[1000001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	map<long long, long long> M;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		M[a[i]] = 0;
	}
	for (long long i = 1; i <= n; ++i) {
		long long k = 0;
		map<long long, long long> m;
		for (int j = i; j <= n; j++) {
			if (!m.count(a[j])) {
				k++;
				ai[k] = a[j];
				m[a[j]] = k;

			} else {
				int K = k;
				k = m[a[j]];
				for (int l = k + 1; l <= K; l++) {
					m.erase(ai[l]);
				}
			}
		}
		for (auto x : m) {
			M[x.first] ++;
		}
	}
	for (auto x : M) {
		cout << x.second << " ";
	}
	return 0;
}