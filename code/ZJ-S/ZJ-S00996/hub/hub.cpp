#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

ll c, t, n, k, u, v;
vector <ll> vec[N];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld %lld", &c, &t);
	while (t--) {
		scanf("%lld %lld", &n, &k);
		for (ll i = 1; i < n; i++) {
			scanf("%lld %lld", &u, &v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
	}
	return 0;
}
//Oct31==Dec25?
