#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int M = 5e5 + 10;
int n, ans;
LL m, a[M], c[M];
bool check(int len) {
	for (int i = len; i <= n; i++) {
		if (a[i] * len - c[i] + c[i - len] <= m) return true;
	} 
	return false;
} 
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		c[i] = c[i - 1] + a[i];
	}
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}

