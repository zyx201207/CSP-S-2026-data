#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define pii pair<long long, char>
#define int long long

long long n;
long long a[N];
char c[N];
long long sum = 0;
pii l[N], r[N];
int topl, topr;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		sum += a[i];
	}
	long long lcnt = 0, rcnt = 0;
	if (sum % 2 == 0) {
		int i = 1;
		long long mid = sum / 2;
		while (true) {
			lcnt += a[i];
			if (lcnt == mid) {
				l[++topl] = {a[i], c[i]};
				break;
			}
			if (lcnt > mid) {
				l[++topl] = {mid - lcnt, c[i]};
				a[i] -= mid - lcnt;
				break;
			}
			l[++topl] = {a[i], c[i]};
			i++;
		}
		i = n;
		while (true) {
			rcnt += a[i];
			r[++topr] = {a[i], c[i]};
			if (rcnt == mid) break;
			i--;
		}
	} else {
		int mid = sum / 2;
		int i = 1;
		while (true) {
			lcnt += a[i]; 
			if (lcnt == mid) {
				l[++topl] = {a[i], c[i]};
				break;
			}
			if (lcnt > mid) {
				lcnt -= a[i];
				l[++topl] = {mid - lcnt, c[i]};
				a[i] -= (mid - lcnt);
				lcnt += mid - lcnt;
				break;
			}
			l[++topl] = {a[i], c[i]};
			i++;
		}
		i = n;
		while (true) {
			rcnt += a[i];
			if (rcnt > mid) {
				rcnt -= a[i];
				r[++topr] = {a[i] - 1, c[i]};
				rcnt += mid - rcnt;
				break;
			}
			r[++topr] = {a[i], c[i]};
			i--;
		}
	}
	
	
	long long answer = 0;
	while (topl && topr) {
		if (l[topl].first == 0) topl--;
		if (r[topr].first == 0) topr--;
		if (l[topl].second == r[topr].second) {
			l[topl].first -= min(l[topl].first, r[topr].first);
			r[topr].first -= min(l[topl].first, r[topr].first);
		} else {
			answer += min(l[topl].first, r[topr].first);
			l[topl].first -= min(l[topl].first, r[topr].first);
			r[topr].first -= min(l[topl].first, r[topr].first);
		}
	}
	
	cout << answer << '\n';
	return 0;
}
