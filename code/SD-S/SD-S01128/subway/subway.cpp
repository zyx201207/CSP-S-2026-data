#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using pli = pair<ll, int>;

const int N = 510, M = 5e5 + 5, SMK = 1.5e6 + 5;

int tstcntc, n, m, d, q;
ll w[M], dis[N];
vector<pli> g[SMK];
priority_queue<pli, vector<pli>, greater<pli>> h;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> tstcntc >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		g[i].emplace_back(w[i], m + i);
		g[m + i].emplace_back(w[i], i);
	}
	ll sumk = 0, ndcnt = 0;
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		sumk += k;
		for (ll j = 1, pa = -1, a, t; j <= k; j++) {
			cin >> a >> t;
			ndcnt++;
			g[m + m + ndcnt].emplace_back(t, m + a);
			g[m + a].emplace_back(t, m + m + ndcnt);
			if (pa != -1) {
				g[m + m + ndcnt - 1].emplace_back(0, m + m + ndcnt);
				g[m + m + ndcnt].emplace_back(0, m + m + ndcnt - 1);
			}
			pa = a;
		}
	}
	int smk = m + m + sumk;
//	for (int i = 1; i <= smk; i++) {
//		cout << i << ":";
//		for (pli j : g[i]) {
//			cout << '(' << j.second << ',' << j.first << ") ";
//		}
//		cout << '\n';
//	}
	for (int i = 1, x, y; i <= q; i++) {
		cin >> x >> y;
		for (int i = 1; i <= smk; i++) {
			dis[i] = -1;
		}
		for (; h.size();) h.pop();
		for (h.emplace(0, x); h.size();) {
			pli p = h.top();
			h.pop();
			if (dis[p.second] == -1) {
				dis[p.second] = p.first;
				for (pli i : g[p.second]) {
					h.emplace(p.first + i.first, i.second);
				}
			}
		}
		cout << dis[y] << '\n';
	}
	return 0;
}

