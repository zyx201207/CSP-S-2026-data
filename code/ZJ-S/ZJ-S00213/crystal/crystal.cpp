#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, a[N], b[N];// b[i]= 把a[1] ~ a[i-1] 变成 a[i] 需要的步数 
bool check (int l, int r) {//m步能否把a[l] ~ a[r-1] 都变成a[r] 
	return (b[r] - b[l] - (l - 1) * (a[r] - a[l]) ) <= m;
}
//111111111111111100000000000000000
int solve (int st) {
	int l = st, r = n, mid = 0;
	while (l < r) {
		mid = (l + r + 1) / 2;
		if ( check(st, mid ) ) {
			l = mid;
		}
		else {
			r= mid - 1;
		}
	}
	return l;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	b[1] = 0; 
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a+i);
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		b[i] = b[i-1] + (i - 1) * (a[i] - a[i-1]);
//		cout << i << " : " << b[i] <<endl;
	}
	int max = -1;
	for (int i = 1; i <= n; i++) {
		int t = solve(i);
		if ( t - i + 1 > max) {
			max = t - i + 1;
		}
	}
	printf("%lld", max);
	return 0;
}
