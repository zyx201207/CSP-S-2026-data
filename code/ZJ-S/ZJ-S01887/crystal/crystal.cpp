#include <bits/stdc++.h>
using namespace std;
long long n,a[500006],m,sum[500006],l = 1,ll;
int main () {
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
		cin >> a[i];
	sort (a + 1,a + n + 1);
	for (int i = 1;i <= n;i ++)
		sum[i] = sum[i - 1] + a[i];
	l = 1;
	for (int i = 2;i <= n;i ++) {
		if (a[i] != a[i - 1])ll = max (ll,l),l = 0;
		l ++;
	}
	for (long long i = n;i > 0;i --) {
		long long need = a[i] * i - sum[i];
		if (need <= m) {
			cout << max (i,ll);
			return 0;
		}
	}
	cout << max (1ll,ll);
	return 0;
}
