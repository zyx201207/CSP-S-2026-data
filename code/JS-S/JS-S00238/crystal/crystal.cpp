#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 9;
int a[N], n, m, ans = 0;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	if(n > 5000) {
		if(n * (n - 1) / 2 >= m) {
			for(int i = sqrt(2 * m) - 1; i <= sqrt(2 * m) + 1; ++i) {
				if(i * (i + 1) / 2 <= m && (i + 1) * (i + 2) / 2 > m) {
					cout << i + 1;
					break;
				}
			}
		}
		else cout << n;
	}
	else {
		for(int i = 1, add = 0; i <= n - 1; ++i, ++add) {
			int xh = 0, cnt1 = i, num = 1;
			while(1) {
				if(xh + (cnt1 - add) * (a[cnt1 + 1] - a[cnt1]) > m || cnt1 == n) break;
				else xh += (cnt1 - add) * (a[cnt1 + 1] - a[cnt1]), cnt1++, num++;
			}
			ans = max(ans, num);
		}
		cout << ans;
	}	
	return 0;
}
