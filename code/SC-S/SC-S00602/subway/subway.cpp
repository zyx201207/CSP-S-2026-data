#include<bits/stdc++.h>
using namespace std;

const int N = 5e2 + 10, M = 2e4 + 10, K = 1e3 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q, k, x, t;

long long dis[K][K][25], w[M];
int wich[M][25];
int cnt[M];

struct station {
	int hao;
	long long tim;
};

struct sear {
	int hao, sta;
	long long tim;
};

bool operator < (sear a, sear b) {
	return a.tim > b.tim;
}

vector<pair<int, long long>> subwa[N];
vector<station> stt[M];

void bfs_all(int i) {
	priority_queue<sear> q;
	q.push({0, i, 0});
	while (!q.empty()) {
		int hao = q.top().hao;
		int sta = q.top().sta;
		long long tim = q.top().tim;

		q.pop();

		int now_hao = lower_bound(wich[sta], wich[sta] + cnt[sta] + 1, hao) - wich[sta];
		if (tim < dis[i][sta][now_hao]) {
			dis[i][sta][now_hao] = tim;
		} else continue;

		//控制地铁号数不变去走到其他站他
		for (auto [ne_sta, cost] : subwa[hao]) {
			int ne_hao = lower_bound(wich[ne_sta] + 1, wich[ne_sta] + cnt[ne_sta] + 1, hao) - wich[ne_sta];
			if (tim + cost < dis[i][ne_sta][ne_hao]) {
				q.push({hao, ne_sta, tim + cost});
			}
		}
		//控制站台不变让这个站台转去其他路线

		for (int ne_hao = 1; ne_hao <= cnt[sta]; ne_hao++) {
			long long cost = stt[sta][ne_hao - 1].tim;
			if (tim + cost < dis[i][sta][ne_hao]) {
				q.push({wich[sta][ne_hao], sta, tim + cost});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) cin >> w[i];

	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> x >> t;
			subwa[i].push_back({x, t});
			stt[x].push_back({i, t});
			cnt[x]++;
			wich[x][cnt[x]] = i;
		}
	}

	if (m <= 1000) {
		memset(dis, 0x3f, sizeof dis);
		for (int i = 1; i <= m; i++) bfs_all(i);
		while (q--) {
			int a, b;
			cin >> a >> b;
			long long minn = INF;
			for (int hao = 1; hao <= cnt[b]; hao++) {
				minn = min(minn, dis[a][b][hao]);
			}
			cout << w[a] + minn + w[b] << endl;
		}
	}
	return 0;
}