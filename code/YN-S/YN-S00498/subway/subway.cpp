#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxN = 500;
const int maxM = 5e5;

ll c, n, m, d, q;	//n地铁线路数、m地铁站数、每个地铁站最多被几条线路经过，q以及出行计划数
ll w[maxM + 5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;

	for (ll i = 1; i <= m; i++) {
		cin >> w[i];
	}

	return 0;
}