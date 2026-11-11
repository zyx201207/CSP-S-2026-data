#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define pil pair<int, ll>
#define pb push_back
#define edl cout <<'\n';
#define debug cout << '*';
#define fi first
#define se second
const int N = 2e6+10;
void solve() {
	int n, k;
	cin >> n >> k;
	rep(i, 1, n-1) {
		int u, v;
		cin >> u >> v;
	}
	if (n==k) cout << 0 << '\n';
	else cout << 1 << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t --) {
		solve();
	} 
}
