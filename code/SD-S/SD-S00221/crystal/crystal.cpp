#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int n;
ll m, a[500010];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll gc = a[2] - a[1];
	bool ok = 1;
	for (int i = 2; i < n && ok; i++)
		if (a[i + 1] - a[i] != gc)
			ok = 0;
	if (ok) {
		if (gc == 0)
			cout << n << '\n';
		ll ma = 0;
		if (gc > 0) {
			for (int i = 2; i <= n; i++)
				if (((i - 1) / 2 + 1) * gc <= m)
					ma = max(ma, (ll)i);
			cout << ma << '\n';
		}
		if (gc < 0) {
			gc = -gc;
			for (int i = n; i > 1; i--)
				if (((i - 1) / 2 + 1) * gc <= m)
					ma = max(ma, (ll)i);
			cout << ma << '\n';
		}
		return 0;
	}
	sort(a + 1, a + n + 1);
	ll ma = 0;
	for (int i = 1; i <= n; i++) {
		ll sum = 0;
		bool jihao = 1;
		for (int j = i; j && jihao; j--) {
			if (sum + (a[i] - a[j]) > m) {ma = max(ma, (ll) (i - j + 1)); jihao = 0;break;}
			else sum += (a[i] - a[j]);
		}
		if (jihao)
			ma = max(ma, (ll)i);
	}
	cout << ma << '\n';
//	cout << sizeof(a) / 1024. / 1024. << '\n';
	return 0;
}
