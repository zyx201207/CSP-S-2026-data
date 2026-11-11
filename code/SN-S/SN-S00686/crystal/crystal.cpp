#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 10;
int n;
ll m;
int a[N], def[N], sum[N];


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	int flag = 1;
	ll cha;
	for (int i = 1; i <= n; i++) {
		ll x, last = 0;
		scanf("%lld", &x);
		if (x > 10000005) {
			cha = x-last;
			last = x;
			flag = 0;
		} else {
			a[i] = (int)x;
		}
	}
	if (flag == 0) {
		ll pos = m / cha;
		int ret = 1;
		for (ll i = 1; i <= n; i++) {
			ll op = i * (i-1) / 2, op1 = (i+1) * i / 2;
			if (op <= pos && op1 > pos) {
				ret = i;
			}
		}
		printf("%d\n", ret);
		return 0;
	}
	
	sort(a+1, a+n+1);
	def[1] = 0;
	for (int i = 2; i <= n; i++) {
		def[i] = a[i] - a[i-1];
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + def[i] * (i-1);
	}
	int l = 1, r = n, ret = 1;
	while (l <= r) {
		int mid = (l+r)/2;
		if (1LL*sum[mid] > m) {
			r = mid - 1;
		} else if (1LL * sum[mid] < m) {
			l = mid + 1;
		} else {
			ret = mid;
			l = mid + 1;
		}
	}
	printf("%d\n", ret);
	return 0;
}


/*
5 8
-1 2 2 -3 7
*/
