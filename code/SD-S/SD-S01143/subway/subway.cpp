#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

#define pli std::pair<long long, int>
#define mkp std::make_pair

const int Maxn = 5e5 + 5, Maxq = 1e5 + 5;
const long long INF = 2e18;

long long min(long long x, long long y) {
	return x < y ? x : y;
}

void Read(int &num) {
	num = 0;
	char ch = getchar();
	int lve = 1;
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

void Write(long long num) {
	if (num < 0) {
		putchar('-');
		num = -num;
	}
	if (num > 9)
		Write(num / 10);
	putchar(48 + num % 10);
}

int c, n, m, d, q;
int w[Maxn], k, a, t, x[Maxq], y[Maxq];

std::vector<pli> edge[Maxn + 500];
int id[Maxn + 500];

long long dis[505][Maxq << 1], tmp[Maxn + 500];
bool vis[Maxn + 500];
std::priority_queue<pli, std::vector<pli >, std::greater<pli > > que;

void Dijkstra(int s) {
	for (int i = 1; i <= m + n; ++i) {
		tmp[i] = INF;
		vis[i] = false;
	}
	tmp[s] = 0;
	que.push(mkp(0, s));
	while (que.size()) {
		pli t = que.top();
		que.pop();
		if (id[t.second])
			dis[s - m][id[t.second]] = t.first;
		if (vis[t.second])
			continue;
		vis[t.second] = true;
		for (pli v : edge[t.second])
			if (tmp[v.second] > t.first + v.first) {
				tmp[v.second] = t.first + v.first;
				que.push(mkp(tmp[v.second], v.second));
			}
	}
}

long long ans;

int main(void) {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	Read(c);
	Read(n);
	Read(m);
	Read(d);
	Read(q);
	for (int i = 1; i <= m; ++i)
		Read(w[i]);
	for (int i = 1; i <= n; ++i) {
		Read(k);
		for (int j = 1; j <= k; ++j) {
			Read(a);
			Read(t);
			edge[m + i].push_back(mkp(t, a));
			edge[a].push_back(mkp(t, m + i));
		}
	}
	for (int i = 1; i <= q; ++i) {
		Read(x[i]);
		Read(y[i]);
		if (!id[x[i]])
			id[x[i]] = i;
		if (!id[y[i]])
			id[y[i]] = i + q;
	}
	for (int i = 1; i <= n; ++i)
		Dijkstra(m + i);
	for (int i = 1; i <= q; ++i) {
		ans = INF;
		for (int j = 1; j <= n; ++j)
			ans = min(ans, dis[j][id[x[i]]] + dis[j][id[y[i]]]);
		ans = ans + w[x[i]] + w[y[i]];
		Write(ans);
		putchar('\n');
	}
	return 0;
}
