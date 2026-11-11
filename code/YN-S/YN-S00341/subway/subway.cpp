#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 5e5 + 8;
const int INF = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q; //测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数
int w[MAXN];

struct shod {
	int p[1005], sl, t[1005];
} a[505]; //其中 ai,j 表示第 i 条线路经过的第 j 个地铁站，ti,j 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间。

struct chod {
	int id, jl;
};

struct whod {
	int w, k = 0;
	chod a[20];
} pp[MAXN];
int qi, zi, ans;
bool ppp[505], p[MAXN];

void dfs(int zha, int dj) {
	if (zha == zi) {

		ans = min(ans, dj);
		return;
	}

	cout << dj << endl;
	p[zha] = false;

	for (int i = 1; i <= pp[zha].k; i++) {

		if (ppp[pp[zha].a[i].id]) {
			ppp[pp[zha].a[i].id] = false;

			for (int j = 1; j <= a[pp[zha].a[i].id].sl; j++) {

				if (p[a[pp[zha].a[i].id].p[j]] == true) {
					p[a[pp[zha].a[i].id].p[j]] = false;
					dfs(a[pp[zha].a[i].id].p[j], dj + a[pp[zha].a[i].id].t[j] + pp[zha].a[i].jl);
					p[a[pp[zha].a[i].id].p[j]] = true;
				}
			}

			ppp[pp[zha].a[i].id] = true;
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		pp[i].w = w[i];
		cin >> w[i];
	}

	bool s2 = true;

	for (int i = 1; i <= n; i++) {

		cin >> a[i].sl;

		if (a[i].sl != 2) {
			s2 = false;
		}

		for (int j = 1; j <= a[i].sl; j++) {

			cin >> a[i].p[j] >> a[i].t[j];
			pp[a[i].p[j]].k++;
			pp[a[i].p[j]].a[pp[a[i].p[j]].k].id = i;
			pp[a[i].p[j]].a[pp[a[i].p[j]].k].jl = a[i].t[j];
		}
	}

	while (q--) {
		cin >> qi >> zi;
		ans = INF;
		dfs(qi, 0);
		//cout << ans << endl;
		ans += w[qi];
		ans += w[zi];

		cout << ans << endl;
	}


	return 0;
}
