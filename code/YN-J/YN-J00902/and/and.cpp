#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n, m, minn = 1e9;
const int N = 2e5 + 10;
int a[N];

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
//	ios::sync_tith_stdio(false);
//	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= m; i++) {
		minn = min(a[i], minn);
	}
	cout << minn << endl;
	return 0;
}