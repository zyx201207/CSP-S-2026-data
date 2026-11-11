#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+50; 
int a[maxn];
long long cnt = 0, ans = 0;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		for (int j = 1; j <= m; ++j) {
			a[i] = a[i] + 1;
			cnt++;
			a[i] = a[i + 1];
			m = m - cnt;
			break;
		}
	
	for (int i = 1; i <= n; ++i) {
		if (a[i] == a[i + 1]) {
			ans++;
		}
	}
	printf("%lld", ans);
	return 0;
}