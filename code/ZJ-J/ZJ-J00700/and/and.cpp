#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, a[N], b[N], m, ans;
void dfs(long long step, long long sum) {
	if (step == m) {
		ans = max(ans, sum);
	}
	for (int i = 1; i <= n; i++) {
		if (!b[i]) {
			b[i] = 1;
			dfs(step+1, (int)(sum & a[i]));
			b[i] = 0;
		}
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == m) {
		long long ans = a[1];
		for (int i = 2; i <= n; i++) {
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	} else if (m == 1) {
		long long hhh = 0;
		for (int i = 1; i <= n; i++) {
			hhh = max(hhh, a[i]);
		}
		cout << hhh;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		b[i] = 1;
		dfs(1, a[i]);
		b[i] = 0;
	}
	cout << ans << endl;
}
