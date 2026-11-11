#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10; 
ll n, m, a [N], s [N];
ll sum (int i, int j) {return s [j] - s [i - 1];}
bool check (int len) {
	for (int h = 1; h <= n - len + 1; h ++) {
		int t = h +	len - 1;
		ll ans = a [t] * len - sum (h, t);
		if (ans <= m) return true;
	}
	return false;
}
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i ++) 
		scanf ("%lld", a + i);
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++)
		s [i] = s [i - 1] + a [i];
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check (mid)) l = mid;
		else r = mid - 1; 
	}
	printf ("%d\n", l);
} 
