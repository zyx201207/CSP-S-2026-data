#include <bits/stdc++.h>
using namespace std;

const long long N = 5e5;
long long a[N + 5], b[N + 5], last[N + 5], flag[N + 5];
bool part[N + 5], no[N + 5];

int main()
{
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	long long n, m;
	scanf ("%lld%lld", &n, &m);
	if (n <= 500) {
		for (long long i = 1; i <= n; i++) scanf ("%lld", &a[i]); 
		for (long long day = 1; day <= n; day++) {
			for (long long i = 1; i <= 3000; i++) {
				b[i] = 0, part[i] = false;
			}
			long long nb = 0;
			for (long long i = day; i <= n; i++) b[++nb] = a[i];
			for (long long i = 1; i <= nb; i++) {
				for (long long j = 1; j < i; j++) {
					if (b[j] == b[i]) {
						for (long long k = j; k <= i - 1; k++) b[k] = -1;
						break;
					}
				}
			}
			for (long long i = 1; i <= nb; i++) {
				if (b[i] == -1) continue;
				part[b[i]] = true;
			}
			for (long long i = 1; i <= m; i++) {
				if (part[i]) flag[i]++;
			}
		}
		for (long long i = 1; i <= m; i++) printf ("%lld ", flag[i]);
		printf ("\n");
	}
	else {
		for (long long day = 1; day <= n; day++) {
			for (long long i = 1; i <= 3000; i++) {
				b[i] = 0, part[i] = false;
			}
			long long nb = 0;
			for (long long i = day; i <= n; i++) b[++nb] = a[i];
			for (int i = 1; i <= n; i++) {
				part[b[i]] = true;
			}
			for (long long i = 1; i <= m; i++) {
				if (part[i]) flag[i]++;
			}
		}
		for (long long i = 1; i <= m; i++) printf ("%lld ", flag[i]);
		printf ("\n");
	}
	return 0;
} 
