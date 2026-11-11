#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
constexpr int N = 2e6 + 10;
ll n, d, x[N], cnt;
int main() {
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	
	int c, T;
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		cnt = 0;
		for (int i = 4; i <= n; ++i) {
			if (x[i] - x[i-2] <= d && x[i-1] - x[i-3] <= d && x[i] - x[i-3] > d) {
				++cnt;
			}
		} 
		cout << cnt << "\n";
	}
	return 0;
} 
