#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e5 * 2 + 10;
ll a[N], pre; char c[N];
ll n, ans = 0, L;
char s_at(ll idx) {
	ll begin_ = 0;
	for (ll i = 1; i <= L; i++) {
		ll end_ = begin_ + a[i];
		if (begin_ <= idx && idx <= end_) {
			return c[i];
		}
		begin_ = end_;
	}
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		ll ai;
		char ci;
		
		cin >> ai >> ci;
		if (ci == c[idx] && i > 1) {
			a[idx] += ai;
			pre += ai;
		}
		else {
			++idx;
			a[idx] = ai;
			c[idx] = ci;
			pre = pre + ai;
		}
	}
	L = idx; // s.size();  
	ll sz = pre;
	for (ll i = 1, j = sz; i != j && j > i; i++, j--) {
		if (s_at(i) != s_at(j)) {
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
} 
