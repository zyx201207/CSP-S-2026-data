#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

#define pii std::pair<int, int>
#define mkp std::make_pair

const int Maxn = 2e6 + 5;
const int INF = 2e9;

void Read(long long &num) {
	num = 0;
	char ch = getchar();
	long long lve = 1;
	while (ch < 48 || ch > 57) {
		if (ch == '-')
			lve = -1;
		ch = getchar();
	}
	while (ch >= 48 && ch <= 57) {
		num = (num << 3) + (num << 1) + (ch ^ 48);
		ch = getchar();
	}
	num *= lve;
}

int c, t;
int n;
long long d, x[Maxn];

std::vector<int> edge[Maxn];
int dis[Maxn], num[Maxn];
bool vis[Maxn];
std::priority_queue<pii, std::vector<pii >, std::greater<pii > > que;

void Dijkstra(int s) {
	for (int i = 1; i <= n; ++i) {
		dis[i] = INF;
		vis[i] = false;
		num[i] = 0;
	}
	dis[s] = 0;
	num[s] = 1;
	que.push(mkp(0, s));
	while (que.size()) {
		pii t = que.top();
		que.pop();
		if (vis[t.second])
			continue;
		vis[t.second] = true;
		for (int v : edge[t.second])
			if (dis[v] > t.first + 1) {
				dis[v] = t.first + 1;
				num[v] = num[t.second];
				que.push(mkp(dis[v], v));
			} else if (dis[v] == t.first + 1)
				num[v] += num[t.second];
	}
}

long long cnt;

void WorkN() {
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (x[j] - x[i] <= d)
				edge[i].push_back(j);
	cnt = 0;
	for (int i = 1; i <= n; ++i) {
		Dijkstra(i);
		for (int j = 1; j <= n; ++j)
			if (num[j] == 2)
				++cnt;
	}
	printf("%lld\n", cnt);
	for (int i = 1; i <= n; ++i)
		edge[i].clear();
}

int max(int x, int y) {
	return x > y ? x : y;
}

int lst, p[Maxn], V, cc[Maxn];

void WorkA() {
	if (x[2] - x[1] > d) {
		printf("0\n");
		return;
	}
	V = lst = 1;
	x[n + 1] = x[n] + x[n] - x[n - 1];
	for (int i = 1; i <= n + 1; ++i)
		if (x[i] - x[lst] <= d) {
			p[i] = p[i - 1] + 1;
			++cc[p[i]];
		} else {
			lst = i - 1;
			V = max(V, p[lst] - 1);
			--cc[p[lst]];
			p[lst] = 1;
			++cc[1];
			p[i] = 2;
			++cc[2];
		}
	--cc[p[n + 1]];
	cnt = 0;
	for (int i = 1; i < V; ++i)
		cnt = cnt + ((long long)cc[i] * (cc[i + 1] - 1) >> 1);
	if (p[n] != V)
		cnt += (cc[p[n]] >> 1);
	for (int i = 1; i <= V; ++i)
		cc[i] = 0;
	printf("%lld\n", cnt);
}

int main(void) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t --) {
		scanf("%d", &n);
		Read(d);
		for (int i = 1; i <= n; ++i)
			Read(x[i]);
		if (n < 4) {
			printf("0\n");
			continue;
		}
		if (n <= 5000)
			WorkN();
		else if (c == 11 || c == 12)
			WorkA();
	}
	return 0;
}
