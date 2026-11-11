#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[500005];
ll d[500005];
ll di[500005];
ll sumdi[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a + 1, a + 1 + n);
	
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
		di[i] = ll(i) * d[i];
		sumdi[i] = di[i] + sumdi[i - 1];
	}
	
	int res = 1;
	for (int i = 1; i < n; i++) {
		ll cost = 0;
		// cost = sumdi[j] - sumdi[i] - i * (a[j] - a[i])
//		for (int j = i + 1; j <= n; j++) {
//			
//			cost += d[j] * ll(j - i);
//			if (cost > m) break;
//			res = max(res, j - i + 1);
//		}

		int l = i + 1, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			ll cost = sumdi[mid] - sumdi[i] - i * (a[mid] - a[i]);
			if (cost > m) r = mid;
			else l = mid + 1;
		}
		
		res = max(res, l - i);
	}
	
	cout << res;
} 
