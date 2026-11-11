#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for ( long long i = 1 ; i <= n ; i++ ) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long ma = -1;
	for ( long long i = n ; i >= 1 ; i-- ) {
		long long ans = 0;
		long long cnt = 0;
		for ( long long j = i - 1 ; j >= 1 ; j-- ) {
			ans += a[i] - a[j];
			cnt++;
			if ( ans > m ) {
				cnt--;
				break;
			}
		}
		ma = max(ma, cnt + 1);
	}
	cout << ma;

	return 0;
}
