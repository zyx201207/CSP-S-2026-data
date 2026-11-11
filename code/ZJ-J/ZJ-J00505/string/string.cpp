#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long

const int N = 2e5 + 5;
int n;
ll ans , a[N] , pre[N] , suf[N];
string s;
vector <ll> v;

inline int solve1(ll x) {
	int L = 0 , R = n + 1;
	while (L + 1 != R) {
		int mid = (L + R) >> 1;
		if (pre[mid] < x) L = mid;
		else R = mid;
	}
	return R;
}

inline int solve2(ll x) {
	int L = 0 , R = n + 1;
	while (L + 1 != R) {
		int mid = (L + R) >> 1;
		if (suf[mid] < x) R = mid;
		else L = mid;
	}
	return L;
}

int main () {
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	s.resize(n + 5);
	for (int i = 1;i <= n;i++) cin >> a[i] >> s[i];
	for (int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
	for (int i = n;i >= 1;i--) suf[i] = suf[i + 1] + a[i];
	ll sum = 0;
	for (int i = 1;i <= n;i++) sum += a[i];
	for (int i = 1;i <= n;i++) if (pre[i] <= sum / 2) v.push_back(pre[i]);
	for (int i = 1;i <= n;i++) if (suf[i] <= sum / 2) v.push_back(suf[i]);
	v.push_back(0);
	sort (v.begin() , v.end());
	v.erase(unique(v.begin() , v.end()) , v.end());
	int sz = v.size();
	for (int i = 0;i < sz - 1;i++) {
		ll l = v[i] + 1 , r = v[i + 1];
		int p1 = solve1(l) , p2 = solve2(l);
		if (s[p1] != s[p2]) ans += (r - l + 1);
	}
	cout << ans << endl;
}