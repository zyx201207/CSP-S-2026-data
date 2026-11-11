#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
 
int n;
int res = 1;
ll m;
ll a[MAXN];
 
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
//	for (int i = 1; i <= n; i++) {
//		ll cost = 0;
//		int ans = 1;
//		for (int j = i + 1; j <= n; j++) {
//			if (cost + 1ll * (a[j] - a[j - 1]) * (j - i) <= m) {
//				cost += 1ll * (a[j] - a[j - 1]) * (j - i);
//				ans++;
//			} else break;
//		}
//		
//		res = max(res, ans);
//	}
	
	ll cost = 0;
	{
		int i = 1, j = 1;
		while (i < n && j < n) {
			if (i == j) {
				if (a[j + 1] - a[j] > m) {
					i++;
					j++;
					continue;
				}
			}
			
			if (cost + 1ll * (a[j + 1] - a[j]) * (j - i + 1) <= m) {
				cost += 1ll * (a[j + 1] - a[j]) * (j - i + 1);
				j++;
			} else {
				cost -= (a[j] - a[i]);
				i++;
			}
			
			res = max(res, j - i + 1);
		}
	}
	
	cout << res << '\n';
	return 0;
} 
