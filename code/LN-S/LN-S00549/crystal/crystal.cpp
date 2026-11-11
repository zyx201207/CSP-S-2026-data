#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int maxn = 5e5+10;
long long a[maxn], sum[maxn];
long long getd(int i, int num) {
	return a[i + num - 1] * num - (sum[i + num - 1] - sum[i - 1]);
}
bool check(int num) {
	for (int i = 1; i + num - 1 <= n; i++) {
		if (getd(i,num) <= m) return 1;
	}
	return 0;
}
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n ,&m);
	for (int i = 1; i <= n; i++) 
		scanf("%lld", a + i);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + a[i];
	}
	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
