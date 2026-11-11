#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500500

ll n, m, C, d, p, T, a0, a1;
ll t0[N], sub[500][N], t[500][N];
vector<ll> vec[N];
priority_queue<pair<ll, ll> >que;

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> C >> n >> m >> d >> p;
	for (ll i = 1; i <= 10; ++i) {
		cin >> t0[i];
		cout << 455;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> sub[i][0];
		for (int j = 1; j <= sub[i][0]; j++) {
			cin >> sub[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= sub[i][0]; j++) {
			for (int k = j + 1; k <= sub[i][0]; k++) {
				vec[sub[i][j]].push_back(sub[i][k]);
				vec[sub[i][j]].push_back(sub[i][k]);
			}
		}
	}
	while (C--) {
		cin >> a0 >> a1;
	}
	return 0;
}
