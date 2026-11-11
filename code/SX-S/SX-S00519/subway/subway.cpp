#include <bits/stdc++.h>
using namespace std;
int dtz[500010];
long long sum = 0;

struct node {
	int a;
	int t;
};
node xl[510];
vector<int>sa[600010];
vector<int>st[600010];
vector<int>pd[600010];

void dfs(int qd, int zd, long long sj, int sz) {
	if (qd == zd) {
		sum = max(sum, sj);
		return;
	}
	for (auto i = sa[qd].begin(), i2 = st[qd].begin(), i3 = pd[qd].begin(), i4 = pd[*i].begin(); i != sa[qd].end();
	        i++, i2++, i3++, i4++) {
		if (*i3 == sz) {
			*i3 = abs(sz - 1);
			*i4 = abs(sz - 1);
			dfs(*i, zd, sj + *i2, sz);
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		int w;
		cin >> w;
		dtz[i] = w;
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++ ) {
			cin >> xl[j].a >> xl[j].t;
			sa[j].push_back(xl[j].a + n);
			st[j].push_back(xl[j].t );
			sa[xl[j].a + n].push_back(j);
			st[xl[j].a + n].push_back(xl[j].t);
			pd[j].push_back(1);
			pd[xl[j].a + n].push_back(1);
		}
	}
//	auto i = sa[2].begin();
//	for (; i != sa[2].end(); i++)
//		cout << endl << *i;
//	cout << sa[2].size();
	for (int i = 1; i <= q; i++) {
		int qd, zd;
		cin >> qd >> zd;
		qd += n;
		zd += n;
		sum = 0;
		int sz = i % 2;
		dfs(qd, zd, 0, sz);
		qd -= n;
		zd -= n;
		cout << sum + dtz[qd] + dtz[zd] << endl;
	}
	return 0;
}