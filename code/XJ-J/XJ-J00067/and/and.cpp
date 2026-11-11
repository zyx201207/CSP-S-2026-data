#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<ll> q, p, ans;

ll lg[35];
void Init() {
	lg[0] = 1;
	for (int i = 1; i <= 30; i++) {
		lg[i] = lg[i-1] << 1;
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	Init();
	int n, m, mx = 0;
	ll ret;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		mx = max(int(upper_bound(lg, lg+31, x) - lg), mx);
		q.push(x);
	}
	
	while(mx--) { // 30
		while (!q.empty()) {
			ll x = q.front(); q.pop(); p.push(x);
			if ((x >> mx) & 1) ans.push(x);
		}
		if (ans.size() > m) {
			while (!ans.empty()) {
//				cout << mx << " " << ans.front() << '\n';
				q.push(ans.front()); ans.pop();
			}
		} else if (ans.size() == m) {
			ret = ans.front(); ans.pop();
			while (!ans.empty()) {
				ret &= ans.front(); ans.pop(); 
			}
			break;
		} else {
			while (!p.empty()) {
				ll x = p.front(); p.pop(); q.push(x);
			}
		}
		while (!p.empty()) p.pop();
		while (!ans.empty()) ans.pop();
	}

	if (mx == -1) {
		ret = q.front(); q.pop();
		while (!q.empty()) {
			ret &= q.front(); q.pop(); 
		}
	}
	
	cout << ret << '\n';

	return 0;
} 
