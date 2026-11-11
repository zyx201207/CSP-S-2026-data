#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, m;
	ll c;
	bool f = 1, fff = 1, ff = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) f = 0;
		if (i == 2) c = a[i] - a[i - 1];
		if (i > 2 && c != a[i] - a[i - 1]) fff = 0;  
		if (a[i] != a[i - 1] && i != 1) ff = 0;
	}
	if (f) {
		ll sum = 1, shu = 0; 
		while (1) {
			shu++;
			m -= shu;
			if (m < 0) break;
			sum++;
		}
		cout << sum;
		return 0;
	}
	if (ff) {
		cout << n;
		return 0;
	}
	if (fff) {
		ll s = abs(a[2] - a[1]);
		ll ss = 0;
		ll sum = 1;
		while (1) {
			ss += s;
			m -= ss;
			if (m < 0) break;
			sum++;
		}
		cout << sum;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	ll maxx = 1;
	ll sum = 0, cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1]) continue;
		sum = 0;
		cnt = 1;
		for (int j = i - 1; j >= 1; j--) {
			sum += a[i] - a[j];
			if (sum > m) break;
			cnt++;
		}
//		cout << cnt << '\n';
		maxx = max(maxx, cnt);
	}
	cout << maxx;
	return 0;
}
/*
-1 -3 2 7
*/