#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn = 5e5 + 7; 

int n;
ll m, ans = 0;
vector<ll> a;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	a.resize(n + 2);
	vector<ll> sub(n + 2);
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	bool diff = true;
	for(int i = 1; i <= n; ++i) { 
		sub[i] = a[i] - a[i - 1];
		if(sub[i] > 1) {
			diff = false;
			break;
		}
	} 
	ll mid = n / 2 + 1, cnt = m;
	if(diff) {
		for(int i = n - 1; i >= 1; --i) {
			if(cnt > 0) ans++;
			cnt -= a[n] - a[i];
			if(cnt == 0) ans++;
		}
	}
//	dp[1] = 0;
//	for(int i = 1; i <= mid; ++i) {
//		int dis = a[mid] - a[i];
//		while(dis <= m) {
//			dp[i] = max(dp[i], a[i]);
//		}
//	}
	else {
		for(int i = mid - 1; i >= 1; --i) {
			if(cnt > 0) ans++;
			cnt -= a[mid] - a[i];
			if(cnt <= 0) ans++;
		}  
	}
	
	cout << ans << "\n";
	return 0;
} 
