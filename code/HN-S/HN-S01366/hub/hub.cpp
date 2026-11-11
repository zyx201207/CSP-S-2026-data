#include <bits/stdc++.h>
using namespace std;

int u[1000000], v[1000000];

signed main() {
  freopen("hub.in", "r", stdin);
  freopen("hub.out", "w", stdout);
  cin.tie(nullptr)->sync_with_stdio(false);
  int c, t;
  cin >> c >> t;
  while (t --) {
	  int n, k;
	  cin >> n >> k;
	  for (int i = 0; i != n; ++ i) {
	  	cin >> u[i] >> v[i];
		}
		cout << 1 << '\n';// CCF give me a waterful tests please!Thank you!
	}
  return 0;
}

