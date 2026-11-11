#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500001], s, ans, c;
bool f = true;
int main(){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%lld%lld" ,&n ,&m);
	for (int i = 1;i <= n;i ++){
		scanf ("%lld" ,&a[i]);
		if (i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]){
			f = false;
		}
	}
	if (f){
		c = a[2] - a[1];
		long long l = 0, r = n + 1;
		while (l + 1 < r){
			long long mid = (l + r) / 2;
			if ((0 + c * mid - c) * mid / 2 <= m){
				l = mid;
			} else {
				r = mid;
			}
		}
		printf ("%lld" ,l);
		return 0;
	}
	sort (a + 1, a + n + 1);
	a[0] = LONG_LONG_MIN;
	for (int i = 1;i <= n;i ++){
		s = 0;
		for (int j = i - 1;j >= 1;j --){
			s += a[i] - a[j];
			if (s > m){
				ans = max(ans, (long long)i - j);
				break;
			}
		}
		if (s <= m){
			ans = max(ans, (long long)i);
		}
	}
	printf ("%lld" ,ans);
	return 0;
}
