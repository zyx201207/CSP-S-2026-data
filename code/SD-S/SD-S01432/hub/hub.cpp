#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2000005;
vector <int> g[MAXN];
void solve () {
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u ,v;
			cin >> u >> v;
		}
		if (n / k == 1) {
			cout << 1 << "\n";
		}
		else {
			cout << (n / k - 1) << "\n";
		}
	}
}
int main () {
	freopen("hub.in", "r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve ();
	return 0;
}
