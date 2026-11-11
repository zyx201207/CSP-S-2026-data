#include <iostream>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], vis[N], k;
long long ans;
int main() {
	freopen("and.in", "r", stdin); 
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int j = 30; j >= 0; j--) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (((1 << j) & a[i]) && vis[i] >= k) {
				cnt++;
				vis[i]++;
			}
		} 
		if (cnt >= m) ans += (1LL << j), k++; 
	}
	cout << ans << '\n'; 
	return 0;
} 
