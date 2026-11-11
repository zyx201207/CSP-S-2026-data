#include <bits/stdc++.h>
#define qwq ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
//#define int long long
using namespace std;
const int N = 0;
int c, t;
int Rand(int n) {
	return (long long)rand() * rand() % n; 
} 
signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	qwq;
	srand((unsigned)time(0));
	cin >> c >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++) int u, v; cin >> u >> v;
		cout << Rand(n) << "\n";
	}
	return 0;
}
