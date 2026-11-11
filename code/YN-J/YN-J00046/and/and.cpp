#include <bits/stdc++.h>
using namespace std;

bool bmp(int l, int r) {
	return l > r;
}
int n, m, a[200005], Max;

void dp(int u, int k, int G) {
	if (G < Max) {
		return ;
	}
	if ( k == m) {
		Max = G;
		return ;
	}
	for (int i = u; i <= n - m + k + 1; i++) {
		dp(i + 1, k + 1, (G & a[i]));
	}
	return ;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, bmp);
	dp(1, 0, 0x7fffffff);
	cout << Max;
	return 0;
}