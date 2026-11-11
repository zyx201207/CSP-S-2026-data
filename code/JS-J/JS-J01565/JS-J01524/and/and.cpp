#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5;

int a[N + 5];
int dp[N + 5];

int n, m;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	cout << a[n - m + 1];
	return 0;
}
