#include <bits/stdc++.h>
using namespace std;

typedef int ll;
const int INF = 0x3f3f3f3f, maxN = 5e5 + 5;
ll n, m, cnt;
ll re[maxN];

map <int, int> mmp;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;

	for (ll i = 1; i <= n; i++) {
		cin >> re[i];

		if (mmp.find(re[i]) == mmp.end()) {
			cnt++;
			mmp[cnt] = re[i];
		} else {
			mmp.clear();
		}
	}

	for (ll i = 1; i <= m; i++) {
		cout << n - mmp[i];
	}

	return 0;
}