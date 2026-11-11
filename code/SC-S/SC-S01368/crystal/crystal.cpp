#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
vector<ll> a, p;
ll f(int idx, int len){
	return a[idx] * len - (p[idx] - p[max(idx - len, 0)]);
}
ll solve(int i){
	int l = 1, r = i, mid, len = 1;
	while (l <= r){
		mid = (l + r) / 2;
		if (f(i, mid) > m) r = mid - 1;
		else len = max(len, mid), l = mid + 1;
//		cout << "stuck";
	}
	return len;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	a.assign(n + 1, 0); p.assign(n + 1, 0);
	for (int i = 1;i <= n;i ++) cin >> a[i];
	sort(begin(a) + 1, end(a));
	for (int i = 1;i <= n;i ++) p[i] = p[i - 1] + a[i]; // 前缀和 
	ll ans = 0;
	for (int i = 1;i <= n;i ++){
		ans = max(solve(i), ans);
	}
	cout << ans;
	return 0;
} 