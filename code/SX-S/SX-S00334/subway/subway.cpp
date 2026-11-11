#include <bits/stdc++.h>
#define re register
#define l long long
#define rl re l
using namespace std;
l c, n, m, d, q, w[500006], k[506];
vector<l> vm[500006], va[506], va2[506], vm2[500006];
bool b[500006];
l dis[500006];
priority_queue<pair<l, l> > p;

l dij(l x, l y) {
	for (l i = 1; i <= m; i++) {
		dis[i] = 1e12;
		b[i] = 0;
	}
	dis[x] = 0;
	p.push(make_pair(0, x));
	while (!p.empty()) {
		l ll = p.top().second;
		if (ll == y) {
			while (!p.empty())
				p.pop();
			return dis[y] + w[x] + w[y];
		}
		p.pop();
		if (b[ll])
			continue;
		b[ll] = 1;
		for (l i = 0; i < vm[ll].size(); i++) {
			l dt = vm[ll][i], kk = vm2[ll][i];
			for (l j = 0; j < va[dt].size(); j++) {
				l rr = va[dt][j];
				if (b[rr])
					continue;
				if (dis[rr] > dis[ll] + va2[dt][j] + va2[dt][kk]) {
					dis[rr] = dis[ll] + va2[dt][j] + va2[dt][kk];
					p.push(make_pair(-dis[rr], rr));
				}
			}
		}
	}
	while (!p.empty())
		p.pop();
	return dis[y] + w[x] + w[y];
}

void mian() {
	cin >> c >> n >> m >> d >> q;
	for (l i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (l i = 1; i <= n; i++) {
		cin >> k[i];
		for (l j = 1; j <= k[i]; j++) {
			l x, tt;
			cin >> x >> tt;
			va[i].push_back(x);
			va2[i].push_back(tt);
			vm[x].push_back(i);
			vm2[x].push_back(j - 1);
		}
	}
	while (q--) {
		l x, y;
		cin >> x >> y;
		printf("%lld\n", dij(x, y));
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	mian();
	return 0;
}
