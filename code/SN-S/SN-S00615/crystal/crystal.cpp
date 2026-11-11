#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500010];

int f(int mid) {
	if (mid <= 0) return 0;
	int x = m, y = 0;
	for (int i = mid; i >= 1 &&  (a[i] >= 0 ?(x - a[mid] + a[i]) : (x - mid + a[i])) >= 0 ; i --) {
		int p = a[mid] - a[i];
		if (a[i] > 0) {
			x -= p;
		}else {
			x -= p;
		}
		if (x >= 0)y ++;else break;
	}
	for (int i = mid; i <= n; i ++) {
		if (a[i] == a[mid]) y ++;
	}
	return y;
}
int ans = 0;
int kdwddjdkd(int mid,int ans) {
	for (int i = 1; i <= n; i ++) {
		if (a[mid] == a[i]) ans ++;
	}
	return ans;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	if (m == 0) {
		
		for (int i = 1; i <= n ; i++) {
			ans = max(ans, kdwddjdkd(i, 0));
		}
		printf("%d\n", ans);
		return 0;
	}
	
	for (int i = 1; i <= n; i ++) {
		ans = max(ans, f(i));
	}
	
	printf("%d\n", ans);
	return 0;
}
