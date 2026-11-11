#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 10;
int n, m, a[maxn], ans = -1;
map <int, int> mp;
int check(int x) {
	int cnt = 0, nowm = m;
	for(int i = 1; i <= n; i ++) {
		if(x > a[i]) {
			nowm -= (x - a[i]);
			if(nowm >= 0) {
				cnt ++;
			}
			else {
				return cnt;
			}
		}
		else if(x == a[i]) {
			cnt ++;
		}
		else {
			return cnt;
		}
	}
}

signed main() {
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		mp[a[i]] ++;
	}
	
	sort(a + 1, a + 1 + n);
	for(int tar = a[1]; tar <= a[n]; tar ++) {
		ans = max(ans, check(tar));
	}
	
	cout << ans;
	
	return 0;
}
