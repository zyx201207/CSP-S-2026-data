#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6;
ll n, m, a[N];
vector<ll> b;

ll cmp(ll x, ll y) {
	return x > y;
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(0);
	// be sure to delete any "//" on this line!!!!!!!!
	// be sure to change the file name
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 30; i >= 0; i--) {
		b.clear();
		for (int j = 1; j <= n; j++) {
			if (a[j] >> i & 1) {
				b.push_back(a[j]);
			}
		}
		if (b.size() >= m)
			break;
	}

	sort(b.begin(), b.end(), cmp);

	cout << b[m - 1] << "\n";
	return 0;
}