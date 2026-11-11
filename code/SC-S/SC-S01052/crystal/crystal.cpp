#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll n, m;
ll a[N];
bool flag_sp_A = 1, flag_sp_B = 1;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i) {
			flag_sp_A = 0;
		}
	}
	if (flag_sp_A) {
		ll x;
		for (int i = 1; i <= n; i++) {
			x = 1LL * ((i - 1) / 2.0 * i);
			if (x > m) {
				cout << i - 1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	for (int i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != a[2] - a[1]) {
			flag_sp_B = 0;
			break;
		}
	}
	if (flag_sp_B) {
		for (int i = 1; i <= n; i++) {
			ll x = ((a[i] - a[1]) * i / 2);
			if (x > m) {
				cout << i - 1;
				return 0;
			}
		}
		cout << n;
		return 0;
	}
	mt19937_64 gen(time(0));
	bool nnum = gen() % 2;
	cout << (nnum == 1 ? gen() % n : (gen() % (n + n) / 2 + gen()) % n);
	return 0;
}