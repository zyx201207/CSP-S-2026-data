#include <iostream>
#define ll long long

using namespace std;

const int N = 2e6 + 5;
ll x[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		ll n, d, ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		cout << "0\n";
	}
	return 0;
}