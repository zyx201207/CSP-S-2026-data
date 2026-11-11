#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, x;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> x;
	n += x;
	cin >> x;
	n += x;
	cin >> x;
	n += x;
	cin >> x;
	n += x;
	cin >> x;
	mt19937_64 gen(time(0));
	for (ll i = 1; i <= x; i++) {
		bool nnum = gen() % (gen() / 2);
		cout << (nnum == 1 ? gen() % n : (gen() % (n*i) / 2 + gen()*i) % n) << "\n";
	}
	return 0;
}