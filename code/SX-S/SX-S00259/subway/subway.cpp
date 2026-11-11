#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int wm[500005], tl[20005][500];
int dis[500005];
int v[30005];
const int MAX = 200000000;

//int fa[20005];
struct edge {
	int v, w, nxt;
} e[500005];
int head[505], cnt = 1;

void add(int u, int v, int w) {
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].nxt = head[u];
	head[u] = cnt++;
}

int main() {
	memset(head, -1, sizeof head);
	memset(tl, 0x3f3f3f3f, sizeof tl);
	memset(dis, 0x3f3f3f3f, sizeof dis);
	//freopen("subway.in", "r", stdin);
	//freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	int zong = m + n;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &wm[i]);
		//fa[m] = m;
	}
	for (int i = 1; i <= n; i++) {
		int ki;
		scanf("%d", &ki);
		int kk = 0, tt = 0;
		for (int j = 1; j <= ki; j++) {
			scanf("%d", &kk, &tt);
			add(i, kk, tt);
			add(kk, i, tt);
			//fa[kk] = i;
			//tl[kk][i] = tt;
		}
	}
	for (int jj = 1; jj <= q; jj++) {
		int st, nd;
		dis[st] = 0;
		v[st] = 1;
		scanf("%d%d", &st, &nd);
		for (int i = head[st]; i; i = e[i].nxt) {
			dis[e[i].v = e[i].w;
		}
		for (int ji = 1; ji <= zong - 1; ji++) {
			int vv = st;
			int MIN = MAX;
			for (int i = 1; i <= zong; i++) {
				if (dis[i] < MIN) {
					MIN = dis[i];
					vv = i;
				}
			}
			for (int i = head[vv]; i; i = e[i].nxt) {
				if (dis[e[i].v] > dis[vv] + e[i].w)
					dis[e[i].v] = dis[vv] + e[i].w;
			}
		}
		cout << dis[nd] << endl;
	}
	return 0;
}