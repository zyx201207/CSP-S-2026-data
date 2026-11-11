#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	mt19937 gen(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t, n, k;
	int x;
	int y;
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			cin >> x >> y;
		}
		bool nnum = gen() % (gen() / 2);
		cout << (nnum == 1 ? (gen() + y) % n : (gen() % (n*k) / 2 + gen()*x) % n) << "\n";
	}
	return 0;
}