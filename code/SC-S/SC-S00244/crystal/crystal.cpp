#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	
	bool is_sort = true;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (i > 0) {
			if (a[i] < a[i - 1]) {
				is_sort = false;
			}
		}	
	}
	if (!is_sort) sort (a.begin(), a.end());
	
	ll l, r, mid;
	r = a[n - 1];
	l = a[0];
	
	while (l < r){
		mid = (l + r + 1) / 2;
		
		bool flag = true;
		ll sum = 0;
		for (int i = 0; i < (int)a.size(); i ++) {
			if (a[i] >= mid) break;
			else sum += (mid - a[i]);
			if (sum > m) flag = false;
		}
		
		if (flag) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	
	ll cnt = 0;
	for (int i = 0; i < n; i ++) {
		if (a[i] <= r) cnt ++;
		else break;
	}
	
	cout << cnt;
	return 0;
}