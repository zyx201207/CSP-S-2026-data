#include <cstdio>

int read() {
	int num = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = num * 10 + (c & 15), c = getchar();
	}
	return num;
}

int n, K, head[1000000], to[2000000], nxt[2000000], rt, height[1000000], hson[1000000][2], f[1000000];
int nhead[1000000], nto[2000000], nnxt[2000000], tot_edge, deg[1000000], w[1000000], D, tot, res, stk[1000000], len;

void addEdge(int id, int u, int v) {
	to[id] = v, nxt[id] = head[u], head[u] = id;
	return;
}

void nAddEdge(int u, int v) {
	nto[tot_edge] = v, nnxt[tot_edge] = nhead[u], nhead[u] = tot_edge ++;
	nto[tot_edge] = u, nnxt[tot_edge] = nhead[v], nhead[v] = tot_edge ++;
	deg[u] ++, deg[v] ++;
	return;
}

void dfsInit(int id, int fa) {
	hson[id][0] = hson[id][1] = -1;
	for (int i = head[id]; i; i = nxt[i]) {
		int son = to[i];
		if (son == fa) {
			continue;
		}
		dfsInit(son, id);
		if ((!~hson[id][0]) || height[son] > height[hson[id][0]]) {
			hson[id][1] = hson[id][0], hson[id][0] = son;
		} else if ((!~hson[id][1]) || height[son] > height[hson[id][1]]) {
			hson[id][1] = son;
		}
	}
	height[id] = ((~hson[id][0]) ? height[hson[id][0]] : 0) + 1;
	return;
}

void findRoot(int id, int oth) {
	if ((~hson[id][1]) && oth < height[hson[id][1]]) {
		oth = height[hson[id][1]];
	}
	++ oth;
	if (height[hson[id][0]] <= oth) {
		rt = id;
		return; 
	}
	findRoot(hson[id][0], oth);
	return;
}

void init() {
	n = read(), K = read();
	for (int i = 0; i < n; i ++) {
		head[i] = 0;
	}
	for (int i = 1; i < n; i ++) {
		int u = read() - 1, v = read() - 1;
		addEdge(i << 1, u, v), addEdge(i << 1 | 1, v, u);
	}
	if (n == 2) {
		return;
	}
	dfsInit(0, -1), findRoot(0, 0), dfsInit(rt, -1);
	return;
}

void dfsBuild(int id, int fa) {
	w[id] = 0, tot ++;
	for (int i = head[id]; i; i = nxt[i]) {
		if (to[i] == fa) {
			continue;
		}
		if (height[to[i]] > D) {
			nAddEdge(id, to[i]), dfsBuild(to[i], id);
		} else if (w[id] < height[to[i]]) {
			w[id] = height[to[i]];
		}
	}
	return;
}

void deal() {
	if (!len) {
		return;
	}
	for (int i = 0; i < len; i ++) {
		f[i] = len;
	}
	for (int i = 0; i < len; i ++) {
		if (i >= D - stk[i] && f[i - D + stk[i]] > i + D - stk[i]) {
			f[i - D + stk[i]] = i + D - stk[i];
		}
	}
	int now = len;
	for (int i = len - 1; ~i; i --) {
		if (res < now - i - 1) {
			res = now - i - 1;
		}
		if (now > f[i]) {
			now = f[i];
		}
	}
	if (res < now) {
		res = now;
	}
	len = 0;
	return;
}

void dfs(int id, int fa) {
	if (deg[id] == 2) {
		dfs(nto[(nto[nhead[id]] == fa) ? nnxt[nhead[id]] : nhead[id]], id), stk[len ++] = w[id];
		return;
	}
	for (int i = nhead[id]; ~i; i = nnxt[i]) {
		if (nto[i] ^ fa) {
			dfs(nto[i], id), deal();
		}
	}
	return;
}

bool check(int d) {
	D = d, tot_edge = 0, tot = 0, res = 0;
	for (int i = 0; i < n; i ++) {
		nhead[i] = -1, deg[i] = 0;
	}
	dfsBuild(rt, -1);
	int st = -1;
	for (int i = 0; i < n; i ++) {
		if (deg[i] == 1) {
			st = i;
			break;
		}
	}
	dfs(st, -1);
	return (tot - res <= K);
}

void calculate() {
	if (n == 2) {
		printf("0\n");
		return;
	}
	int l = 0, r = height[hson[rt][1]];
	while (l ^ r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	printf("%d\n", l);
	return;
}

void solve() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	read();
	int T = read();
	while (T --) {
		init(), calculate();
	}
	return;
}

int main() {
	solve();
	return 0;
}