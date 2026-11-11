#include <iostream>
using namespace std;
const int maxn = 2000005;
int n, d, x[maxn];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; ++i)
			cin >> x[i];
	}
	return 0;
}
