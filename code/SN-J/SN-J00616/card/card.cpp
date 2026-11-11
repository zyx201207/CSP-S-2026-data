#include <bits/stdc++.h>
using namespace std;
const long long N = 1e18;
unsigned long long cnt2, ll = N, rr = -N, n, m, a[500000], b[500000], l[500000], r[500000], cnt;
bool f[300000];
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int x = 0; x < n; x++) {
		for (int i = x; i < n; i++) {
			if (f[a[i]]) l[a[i]] = b[a[i]], r[a[i]] = cnt+i-x;
			f[a[i]] = 1;
			b[a[i]] = cnt+i-x+1;
		}
		cnt += n-x;
    }
    for (int i = 0; i < n; i++) {
    	if (rr < r[a[i]]) rr = r[a[i]];
    	if (ll > l[a[i]]) ll = l[a[i]];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (ll < cnt2 && cnt2 < rr) continue;
			else cout << a[i] << ' ';
			cnt2++;
		}
		cnt2 += n-i;
	}
	return 0;
}
/*
if (f[a[i]) l = b[a[i]], r = i-1;
f[a[i]] = 1;
b[a[i]] = i;
*/
