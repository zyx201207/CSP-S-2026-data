#include <bits/stdc++.h>
using namespace std;
// v2 
using ll = long long;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n; cin >> n;
	ll m; cin >> m;
	vector <ll> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());
	
	vector <ll> b(n);
	for (int i = 1; i < n; i ++){
		b[i] = a[i] - a[i - 1];
	}
	vector <ll> sumb(n);
	for (int i = 1; i < n; i ++){
		sumb[i] = sumb[i - 1] + b[i];
	}
	
	ll pre = 0; int ans = 0;
	for (int p1 = 1, p2 = 1; p1 <= p2 && p2 < n; p1 ++){
		int len = p2 - p1 + 1;
		ll cost = pre;
		while (cost <= m && p2 < n){
			++ p2, ++ len;
			cost += len * b[p2];
		}
		ans = max(ans, len);
//		cout << pre << ' ' << cost << ' ' << p1 << ' ' << p2 << ' ';
		cost -= sumb[p2] - sumb[p1];
		pre = cost;
//		cout << ans << '\n';
	}
	cout << ans;

	return 0;
}
/*
5 8
-3 -1 2 2 7
*/ 
