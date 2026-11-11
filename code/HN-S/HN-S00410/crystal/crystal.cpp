#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define ll long long
//#define ull unsigned long long
const int N = 5e5 + 10;
struct st {
	int val, cnt;
}ls[N];
int a[N], sum[N], ans[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, ix = 0, now = 0, maxx = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i - 1] || i == 1) {
			ls[++ix].val = a[i];
			ls[ix].cnt = 1;
		}
		else ls[ix].cnt++;
	}
	for (int i = 1; i <= ix; i++) {
		int w = 0, cnt1 = ls[i].cnt;
		for (int j = i - 1; j >= 1; j--) {
			w += (ls[i].val - ls[j].val) * ls[j].cnt;
			if (w > m) {
				w -= (ls[i].val - ls[j].val) * ls[j].cnt;
				cnt1 += (m - w) / (ls[i].val - ls[j].val);
				break;
			}
			cnt1 += ls[j].cnt;
		}
		ans[i] = cnt1;
	}
	for (int i = 1; i <= ix; i++) maxx = max(maxx, ans[i]);
	cout << maxx << "\n"; 
	return 0;
}
