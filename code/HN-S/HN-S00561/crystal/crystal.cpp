#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;

int n, m;
int a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0)->sync_with_stdio(false);
	cin >> n >> m;
	int maxx = 1;
	for (int i = 1; i <= n; i++) {cin >> a[i];} 
	sort(a + 1, a + 1 + n);
	int cnt = 0, ans = 0, l = 1;
	for (int i = 1; i <= n; i++) {
		ans += (i - l) * (a[i] - a[i - 1]); 
		cnt++;
		while (ans > m && l < i) {
			ans -= (a[i] - a[l]);
			l++, cnt--;
		}
		maxx = max(maxx, cnt);
	}
	cout << maxx;
	return 0;
}
/*
45min AC

hai shi tai cai le
*/

