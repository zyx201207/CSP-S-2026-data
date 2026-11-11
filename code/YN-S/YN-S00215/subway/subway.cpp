#include<bits/stdc++.h>
using namespace std;
const int N = 505, M = 5e5+10, D = 25;
#define ll long long
struct node {
	int v;
	ll val;
};
struct nodeb {
	int belid;
	ll ti;
};
struct nodec {
	int num;
	ll day;
	bool operator<(const nodec &t) const {
		return t.day < day;
	}
};
int c, n, m, d, q, k, id, xx, yy;
ll ans[N][N], w[M], tif[M], tid, updo[M];
bool p[N][N], pp[N];
vector<node> a[N];
vector<int> tar[N];
vector<nodeb> bel[M];
priority_queue<nodec> pq;
void distr(int s) {
	while (!pq.empty())
		pq.pop();
	ans[s][s] = 0, p[s][s] = 1;
	int si = a[s].size() - 1;
	for (int i = 0; i <= si; i++)
		pq.push({a[s][i].v, a[s][i].val});
	while (!pq.empty()) {
		if (p[s][pq.top().num]) {
			pq.pop();
			continue;
		}
		ans[s][pq.top().num] = pq.top().day;
		p[s][pq.top().num] = 1;
		int sic = a[pq.top().num].size() - 1;
		int numnum = pq.top().num;
		pq.pop();
		for (int i = 0; i <= sic; i++)
			if (!p[s][a[numnum][i].v])
				pq.push({a[numnum][i].v, a[numnum][i].val + ans[s][numnum]});
	}
	return ;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> updo[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> id >> tid;
			bel[id].push_back({i, tid});
			w[id] = tid;
			tar[i].push_back(id);
		}
	}
	for (int i = 1; i <= n; i++) {
		int si = tar[i].size() - 1;
		for (int j = 0; j <= si; j++) {
			int jsi = bel[tar[i][j]].size() - 1;
			ll st = 0;
			for (int o = 0; o <= jsi; o++) {
				if (bel[tar[i][j]][o].belid == i) {
					st = bel[tar[i][j]][o].ti;
					break;
				}
			}
			for (int o = 0; o <= jsi; o++) {
				if (bel[tar[i][j]][o].belid == i)
					continue;
				a[i].push_back({bel[tar[i][j]][o].belid, st + bel[tar[i][j]][o].ti});
			}
		}
	}

	while (q--) {
		cin >> xx >> yy;
		int xsi = bel[xx].size() - 1, ysi = bel[yy].size() - 1;
		ll out = 1e18;
		for (int i = 0; i <= xsi; i++) {
			for (int j = 0; j <= ysi; j++) {
				if (pp[bel[xx][i].belid])
					out = min(out, bel[xx][i].ti + ans[bel[xx][i].belid][bel[yy][j].belid] + bel[yy][j].ti);
				else {
					pp[bel[xx][i].belid] = 1;
					distr(bel[xx][i].belid);
					out = min(out, bel[xx][i].ti + ans[bel[xx][i].belid][bel[yy][j].belid] + bel[yy][j].ti);
				}
			}
		}
		cout << out + updo[xx] + updo[yy] << "\n";
	}
	return 0;
}
