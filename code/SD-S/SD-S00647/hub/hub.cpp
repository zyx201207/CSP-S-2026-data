#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int n,k;
int deg[N];

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,__;cin >> c >> __;
	while (__ --) {
		cin >> n >> k;
		for (int i = 1;i < n;i ++) {
			int u,v;cin >> u >> v;
			deg[u] ++,deg[v] ++;
		}
		if (c == 1) {
			if (n == 2) {
				if (k == 1) cout << 1 << '\n';
				else cout << 0 << '\n';
			}else if (n == 3) {
				if (k == 1 || k == 2) cout << 1 << '\n';
				else cout << 0 << '\n';
			}else if (n == 4) {
				bool f = 0;
				for (int i = 1;i <= n;i ++) if (deg[i] == 3) {
					f = 1;
					break;
				}
				if (f) {
					if (k == 4) cout << 0 << '\n';
					else cout << 1 << '\n';
				}else {
					if (k == 1) cout << 2 << '\n';
					else if (k == 4) cout << 0 << '\n';
					else cout << 1 << '\n';
				}
			}else {
				int mx = 0;
				for (int i = 1;i <= n;i ++) mx = max(mx,deg[i]);
				if (mx == 2 || mx == 3) {
					if (k == 1) cout << 2 << '\n';
					else if (k == 5) cout << 0 << '\n';
					else cout << 1 << '\n';
				}else {
					if (k == 5) cout << 0 << '\n';
					else cout << 1 << '\n';
				}
			}
		}else {
			if (k == n) cout << 0 << '\n';
			else {
				int mx = 0;
				for (int i = 1;i <= n;i ++) mx = max(mx,deg[i]);
				if (mx == n-1) cout << 1 << '\n';
				else cout << n/2 << '\n';
			}
		}
		for (int i = 1;i <= n;i ++) deg[i] = 0;
	}
	return 0;
}

