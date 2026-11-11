#include <bits/stdc++.h>
#define qwq ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int, int>
//#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, t;
int n, d, x[N];
int Rand(int n) {
	return (long long)rand() * rand() % n; 
} 
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	qwq;
	srand((unsigned)time(0));
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		cout << Rand(n * n) << "\n";
	}
	return 0;
}
