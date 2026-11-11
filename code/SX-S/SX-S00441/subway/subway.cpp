#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long cccc, n, m, dd, q, w[N], k[502];
int a, b[N], ddd, p[502][502], num_edge, head[501], e, f, g, h, t[502][N];
vector<int> c[N], d[N];

struct edg {
	int next, to, dis;
} edge[200010];

void add_edge(int from, int to, int dis) {
	num_edge++;
	edge[num_edge].next = head[from];
	edge[num_edge].to = to;
	edge[num_edge].dis = dis;
	head[from] = num_edge;

	return;
}

int main() {
	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &cccc, &n, &m, &dd, &q);
//	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 1; i <= m; i++)
		scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &k[i]);
		for (int j = 1; j <= k[i]; j++) {
			scanf("%d%d", &a, &t[i][j]);

			b[a]++;
			c[a].push_back(i);
			d[a].push_back(j);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < b[i] - 1; j++) {
			for (int kd = j + 1; kd < b[i]; kd++) {
				e = c[a][j];
				f = d[a][j];
				g = c[a][kd];
				h = d[a][kd];
				ddd = t[e][f] + t[g][h];
				add_edge(j, kd,  ddd);
				add_edge(kd, j, ddd);
				cout << j << " " << kd << endl;
			}
		}
	}

	fclose(stdin);
//	fclose(stdout);
	return 0;
}
