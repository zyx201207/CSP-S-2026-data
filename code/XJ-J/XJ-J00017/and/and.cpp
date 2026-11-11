#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAXN = 2 * 1e5 + 3;
int a[MAXN], dp[MAXN], st[MAXN], ans = 1;
bool cmp(int a, int b){
	return a > b;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n, cmp);
	ans = a[1];
	for (int i = 1; i <= m; i++){
		ans = (ans & a[i]);
	}
	cout << ans;
	return 0;
}
