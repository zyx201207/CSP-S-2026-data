#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, first[1500005], cnt, t, k, ta[1500005];
bool vst[1500005];
long long dis[1500005];

struct node {
	long long u, to, w, nxt;
} edge[1500005];

struct node2 {
	long long step, u;
	bool operator <(const node2 &other)const {
		return step > other.step;
	}
};

inline void add(long long u, long long v, long long w) {
	edge[++cnt].u = u;
	edge[cnt].w = w;
	edge[cnt].to = v;
	edge[cnt].nxt = first[u];
	first[u] = cnt;
}

priority_queue<node2> que;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m ; i++) {
		cin >> t;
		add(i, m + i, t);
		add(m + i, i, t);
	}
	for (int i = 1 ; i <= n ; i++) {
		cin >> k;
		for (int j = 1 ; j <= k ; j++) {
			long long a1, t1;
			cin >> a1 >> t1;
			ta[j] = a1 + (2 + i - 1) * m;
			if (j > 1) {
				add(ta[j], ta[j - 1], 0);
				add(ta[j - 1], ta[j], 0);
			}
			add(a1 + (2 + i - 1) * m, m + a1, t1);
			add(m + a1, a1 + (2 + i - 1) * m, t1);
		}
	}

	//return 0;
	while (q--) {


		for (int i = 1; i <= 1500008 ; i++) {
			dis[i] = 0x3f3f3f3f;
			vst[i] = 0;
		}
		long long st, sd;
		cin >> st >> sd;
		dis[st] = 0;
		//vst[st] = 1;
		que.push(node2{0, st});
		while (!que.empty()) {
			long long u = que.top().u;
			que.pop();
			for (int i = first[u]; i; i = edge[i].nxt) {
				//cout << edge[i].u << "->" << edge[i].to << " " << "w:" << edge[i].w << "\n";
				if (vst[i] == 1)
					continue;
				vst[i] = 1;
				long long v = edge[i].to;
				if (dis[v] > dis[u] + edge[i].w) {
					dis[v] = dis[u] + edge[i].w;
					//cout << v << ":" << dis[v] << "\n";
					que.push({dis[v], v});
				}


			}

		}
		cout << dis[sd] << "\n";
	}


	return 0;
}
