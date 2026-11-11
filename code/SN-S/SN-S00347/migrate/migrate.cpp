//SN-S00347 王欣甜 西安市铁一中学
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6 + 5;
int n;
ll d, x[maxn];
void solve1() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	if(n == 1) {
		cout << 0 << endl;
		return;
	}
	ll base = d / (x[2] - x[1]);
	if(base == 0 || base == 1) {
		cout << 0 << endl;
		return;
	}
	ll res = 2 * base - 1, r = 0;
	cout << max(r, n - res) << endl;
}
void solve() {
	
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	if(c == 11 || c == 12) {
		while(t--) {
			solve1();
		}
	}else {
		while(t--) {
			solve();
		}
	}
}
