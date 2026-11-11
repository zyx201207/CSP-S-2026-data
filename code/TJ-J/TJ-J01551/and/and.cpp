#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(a[i], maxx);
	}
	sort(a + 1, a + n + 1);
	long long ans = 0;
	vector<int>ansn;
	int cnt = 0;
	for (int i = 30; i >= 0; i--) {
		ansn.clear();
		cnt = 0;
		//cout << (a[n] & (1 << i));
		for (int k = n; k >= 1; k--) {
			if ((a[k] & (1 << i)) != 0) {
				ansn.push_back(a[k]);
				cnt++;
			}
			if (cnt == m)
				break;
		}
		if (cnt == m) {
			//cout << i;
			break;
		}
	}
	if (cnt == m) {
		ans = ansn[0];
		for (int i = 1; i <= m - 1; i++) {
			ans = (ans & ansn[i]);
		}
	}
	cout << ans;
	//xym
	return 0;
}