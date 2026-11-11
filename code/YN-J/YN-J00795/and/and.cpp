#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
const int N = 2 * 1e5 + 5;
int rec[N];
int a[N];
int maxx = LLONG_MIN;

void dfs(int pos, int start) {
	if (pos > m) {
		int sum = rec[1];
		for (int i = 1; i < pos; i ++) {
			sum &= rec[i];
		}
		maxx = max(maxx, sum);
		return ;
	}
	for (int i = start; i <= n; i ++) {
		rec[pos] = a[i];
		dfs(pos + 1, i + 1);
		rec[pos] = 0;
	}
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	dfs(1, 1);
	cout << maxx ;

	return 0;
}