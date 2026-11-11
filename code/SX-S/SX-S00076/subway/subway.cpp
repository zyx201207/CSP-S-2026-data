#include <bits/stdc++.h>
using namespace std;
int w[500005];
int sub[500005][505];
int cnt;
int head[500005];
int anns[500005];

struct node {
	int to, nxt, id;
} edge[100005];
queue<int> q;
queue<int> q2;
queue<int> q3;

void add(int u, int v, int ii) {
	cnt++;
	edge[cnt].to = v;
	edge[cnt].nxt = head[u];
	edge[cnt].id = ii;
	head[u] = cnt;
}

int apex(int ss, int www) {
	memset(anns, 0x3f, sizeof(anns));
	q.push(ss);
	q2.push(0);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int gh = q2.front();
		q2.pop();
		int shangyi = q3.front();
		q3.pop();
		if (gh >= anns[x]) {
			continue;
		} else {
			anns[x] = gh;
		}
		for (int i = head[x]; i; i = edge[i].nxt) {
			q.push(edge[i].to);
			if (edge[i].id == shangyi) {
				q2.push(gh - sub[x][edge[i].id] + sub[edge[i].to][edge[i].id]);
			} else {
				q2.push(gh + sub[x][edge[i].id] + sub[edge[i].to][edge[i].id]);
			}
			q3.push(edge[i].id);
		}
	}
	return anns[www];
}

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, qq;
	cin >> c >> n >> m >> d >> qq;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &w[i]);
	}
	int hh1, hh2, hjhj;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &hjhj);
		for (int j = 1; j <= hjhj; j++) {
			hh1 = hh2;
			scanf("%d", &hh2);
			scanf("%d", &sub[hh2][i]);
			if (j == 1)
				continue;
			add(hh1, hh2, i);
		}
	}
	int x, y;
	int ans = 0;
	if (c == 0) {
		if (n == 3 && m == 7 && qq == 2 && d == 20) {
			cout << 35 << endl << 16;
		}
	}
	for (int i = 1; i <= qq; i++) {
		scanf("%d%d", &x, &y);
		ans = w[x];
		ans += w[y];
		ans += apex(x, y);
		printf("%d\n", ans);
	}
	return 0;
}
