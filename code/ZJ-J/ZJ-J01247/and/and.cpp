#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, m, a[N], mx, s = 2147483647, mmmx;

bool cmp(int a, int b){return a > b;}

void dfs(int x, int st, int ss) {
	if (ss < mmmx) return ;
	if (st == m) {
		mmmx = max(mmmx, ss);
		return ;
	}
	for (int i = x;i <= n;i++) dfs(i + 1, st + 1, ss & a[i]);
}

void solve1() {
	dfs(1, 0, 2147483647);
	cout << mmmx;
}

void solve2() {
	int mmx = 0;
	for (int i = 1;i < n;i++) 
		for (int j = i + 1;j <= n;j++) 
			mmx = max(mmx, a[i] & a[j]);
	cout << mmx;
}

void solve3() {
	vector<int> c(5);
	for (int i = 1;i <= n;i++) c[a[i]]++;
	if (c[4] >= m) cout << 4;
	else if (c[3] >= m) cout << 3;
	else if (c[2] + c[3] >= m) cout << 2;
	else if (c[1] + c[3] >= m) cout << 1;
	else cout << 0;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		s &= a[i];
	}
	
	if (n <= 20) solve1();
	else if (m == 1) cout << mx;
	else if (m == n) cout << s;
	else if (m == 2) solve2();
	else if (mx <= 4) solve3();
	else {
		sort(a + 1, a + n + 1, cmp);
		int ans = a[1];
		for (int i = 2;i <= m;i++) ans &= a[i];
		cout << ans;
	}
}