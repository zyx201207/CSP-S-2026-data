#include <bits/stdc++.h>
#include <cstdio>
#define OI ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int MAXN = 2 * 1e5 + 10;
long long a[MAXN];
long long ans;
int n, m;

void dfs(int i, int k, long long date) {
	if (k >= m) {
		//	cout << date << " ";
		ans = max(ans, date);
		return;
	}
	if (i + 1 <= n)
		dfs(i + 1, k + 1, date & a[i + 1]);
	if (i + 1 <= n)
		dfs(i + 1, k, date);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	OI
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		dfs(i, 1, a[i]);
	}
	cout << ans;

	return 0;
}
/*
4 2
2 3 15 12 12

5 3
31 3 1 15 7
*/