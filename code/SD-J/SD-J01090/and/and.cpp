#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int INF = 0x3f3f3f3f;
const ll INF2 = 0x3f3f3f3f3f3f3f3f;

ll n, m;
const int N = 2e5 + 10;
ll a[N];

ll ans;
void check(int mask) {
	ll sum = (1<<30)-1;
	for (int i = 1; i <= n; i++) {
		if (mask & (1 << (i-1))) {
			sum &= a[i];
		}
	}
	ans = max(ans, sum);
}
void solve1() {
	for (int mask = 0; mask < (1 << n); mask++) {
		if ((ll)bitset<30>(mask).count() == m)check(mask);
	}
	cout << ans;
}
void solve2() {
	sort(a+1, a+n+1, greater<ll>());
	ans = INF2;
	for (int i = 1; i <= m; i++) {
		ans = min(ans, a[i]);
	}
	cout << ans; 
}
void solve3() {
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			ans = max(ans, a[i]&a[j]);
		}
	}
	cout << ans;
}
void solve4() {
	ans = a[1];
	for (int i = 2; i <= n; i++) {
		ans &= a[i];
	}
	cout << ans;
}
bool vis[N];
void solve5() {
	int cnt = 0;
	for (int i = 30; i >= 0; i--) {
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (vis[j]) continue;
			
			if (a[j] & (1 << i)) {
				cnt++;
			}
		}
		
		if (cnt >= m) {
			ans |= (1 << i);
			for (int j = 1; j <= n; j++) {
				if (vis[j]) continue;
				
				if (a[j] & (1 << i)) {
				} else {
					vis[j] = 1;
				}
			}
		}
	}
	cout << ans;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(), cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		
	}
	
	if (n <= 20) {
		solve1();
	} else if (n <= 2000 && m == 1) {
		solve2();
	} else if (n <= 2000 && m == 2) {
		solve3();
	} else if (n <= 2000 && m == n) {
		solve4();
	} else {
		solve5();
	}
	
	return 0;
}
