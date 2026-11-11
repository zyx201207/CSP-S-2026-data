//SN-S00518 李承欢 西安市铁一中学 
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500100;
int n, m, a[N]; 

signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int sum = 0, now = 1, maxn = -1;
	for (int i = 1; i <= n; i++) {
		sum += (a[i] - a[i - 1]) * (i - now);
		if (sum <= m) {
			maxn = max(maxn, i - now + 1);
		} else {
			while (sum > m) {
				sum -= a[i] - a[now];
				now++;
			}
		}
	}
	cout << maxn;
	return 0;
}
