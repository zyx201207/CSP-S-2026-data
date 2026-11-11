// CSP RP++
// luv wsj
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 5e5;
int n, ans;
ll m, a[N + 5];

template<typename T>
inline void chmin(T& a, const T b){ a = min(a, b); }
template<typename T>
inline void chmax(T& a, const T b){ a = max(a, b); }

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) cin >> a[i];
	sort(a + 1, a + n + 1);
	int p = 1;
	ll s = 0;
	for(int i = 1; i <= n; ++ i){
		s += a[i];
		while((i - p + 1ll) * a[i] - s > m) s -= a[p ++];
		chmax(ans, i - p + 1);
	}
	cout << ans;
}

