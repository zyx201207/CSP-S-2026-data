#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, x;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	mt19937_64 gen(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t, n, d;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x;
		}
		bool nnum = gen() % (gen() / 3);
		cout << (nnum == 1 ? gen() % n : (gen() % (n*x) / 2 + gen()*x) % n) << "\n";
	}
	return 0;
}