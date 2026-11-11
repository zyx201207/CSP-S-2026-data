#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, ans;
int a[N];
//bool op = false;
bool cmp(int a, int b) {
	return a, b;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i <= n; i++) {
		cin >> a[i];
//		if(a[i] >= 4) op = false;
		sort(a + 1, a + n - 1, cmp);
		if(n == 1) {
		cin >> a[i];
		return 0;
	} else if (n == 2) {
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				ans = max(ans, a[i] & a[j]);
				
			}
		}
	}
}
	cout << ans;
	return 0;
}
