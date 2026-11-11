#include <bits/stdc++.h>
using namespace std;

int z, n, m, d, q;
int mw[500010];
int xu, xv, xw;
int cnt;
int st, en;

struct Edge {
//	int to,w,nxt;
	int u, v, w;
} e[500010];

struct Bian {
	int to, w, nxt;
} b[500010];
int s;

int c, cc;
int head[510], fa[510];
long long ans;

void add(int u, int v, int w) {
	s++;//边数
	b[s].to = v;
	b[s].w = w;
	b[s].nxt = head[u];
	head[u] = s;
}

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

int find(int a) {
	if (a == fa[a])
		return a;
	else
		return fa[a] = find(fa[a]) ;
}

void kruskal() {
	sort(e + 1, e + c + 1, cmp);
	for (int i = 1; i <= c; i++) {
		int uu = find(e[i].u);
		int vv = find(e[i].v);
		if (uu == vv)
			continue;
		fa[vv] = uu;
		add(e[i].u, e[i].v, e[i].w);
		add(e[i].v, e[i].u, e[i].w);
		cc++;
		if (cc == n + m - 1)
			break;
	}
}

long long lu(int start) {
	return head[start];
}

int main() {

//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> z >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> mw[i];
	}
	memset(head, -1, sizeof head);
	for (int i = 1; i <= n; i++) {
		cin >> xu; //u为地铁站台
		cnt = xu;
		fa[i] = i;
		while (cnt--) {
			c++;
			cin >> xv >> xw; //v为厅站
			e[c].u = xu;
			e[c].v = xv;
			e[c].w = xw;
//			add(xu,xv,xw);
//			add(xv,xu,xw);
		}
	}
	kruskal();
	for (int i = 1; i <= q; i++) {
		cin >> st >> en;
		ans = long(mw[st] + mw[en]);
//		dijstra(st,en);//v到u到v,一定没有直连边
		ans += lu(st);
		cout << ans << "\n";
	}

	return 0;
}
