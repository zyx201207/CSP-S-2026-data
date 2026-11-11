#include <bits/stdc++.h>
using namespace std;

long long n, m;
const long long N = 5e5 + 10;
long long a[N];
long long s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(long long i = 2; i <= n; i++) {
		for(long long j = 1; j < i; j++) {
			s[i] += (a[i] - a[j]);
		}
	}
	for(long long i = 1; i <= n; i++) {
		if(s[i] > m) {
			cout << i - 1 << endl;
			return 0;
		}
	}
	cout << n << endl;
	return 0;
}
