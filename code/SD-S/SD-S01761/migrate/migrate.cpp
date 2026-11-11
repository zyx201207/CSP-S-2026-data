#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 2000006;
const ll inf = 2e18;

int c, T;
int n;
ll d, x[N]; 

struct SOLVE1 {
	ll f[N], ans;
	int cnt[N], pos[N];
	void solve() {
		for(int i = 1; i <= n; i++)
			pos[i] = lower_bound(x + 1, x + 1 + n, x[i] - d) - x;
		for(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++)
				cnt[j] = 0;
			f[i] = 0;
			cnt[i] = 1;
			for(int j = i + 1; j <= n; j++) {
				int p = max(pos[j], i);
				ll mn = f[p];
				f[j] = f[p] + 1;
				for(int k = p; k < min(p + 4, j); k++)
					if(f[k] == mn)
						cnt[j] += cnt[k];
			}
			for(int j = i + 1; j <= n; j++)
				if(cnt[j] == 2) ans++;
		}
		cout << ans << endl;
	}
};
struct SOLVE2 {
	void solve() {
		ll diff = x[2] - x[1];
		ll num = d / diff;
		if(num <= 1) cout << 0 << endl;
		else cout << max(0LL, n - num * 2 + 1) << endl;
	}
};
void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	if(c <= 10) {
		(new SOLVE1()) -> solve();
	} else if(11 <= c && c <= 12) {
		(new SOLVE2()) -> solve();
	} else {
		(new SOLVE1()) -> solve();
	}
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> c >> T;
	while(T--) {
		solve(); 
	}
    return 0;
}
