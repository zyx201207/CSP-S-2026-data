#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5, M = 30;
long long a[N + 5], cnt[M + 5];
pair <long long, long long> w[N + 5];

int main()
{
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout); 
	long long n, m;
	scanf ("%lld%lld", &n, &m);
	for (long long i = 1; i <= n; i++) {
		scanf ("%lld", &a[i]);
		w[i].second = i;
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = 0; j <= 30; j++) {
			if ((a[i] >> j) & 1) cnt[j]++;
		}
	}
	for (long long i = 30; i >= 0; i--) {
		if (cnt[i] < m) continue;
		for (long long j = 1; j <= n; j++) {
			if ((a[j] >> i) & 1) {
				w[j].first += (1LL << i);
			}
		}
	}
	sort (w + 1, w + n + 1);
	long long ans = a[w[n].second];
	for (long long i = n - 1; i >= n - m + 1; i--) {
		ans = ans & a[w[i].second];
	}
	printf ("%lld\n", ans);
	return 0;
}
