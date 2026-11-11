#include <cstdio>
#include <queue>
#include <cstring>

int c,n,m,d,q;
int w[500005];
int x[500005], y[500005];
int edge[1000005], next[1000005], to[1000005], head[1000005], len;
long long dp[100005][505];
long long dis[500005];
bool vis[500005], cal[500005];
long long Ans, Y;

int in() {
	char x = getchar();
	int ans = 0;
	while (x <= '9' && x >= '0') {
		ans = ans * 10 + x - '0';
		x = getchar();
	}
	return ans;
}

void print(long long x) {
	if (!x) return;
	print(x / 10);
	putchar(x % 10 + '0');
}

void add_edge(int u, int v, int w) {
	next[++len] = head[u];
	head[u] = len;
	to[len] = v;
	edge[len] = w;
}

bool calc(int x) {
	if (cal[x]) return false;
	memset(dis, 0x3f, sizeof(dis));
	std::queue<int> q;
	q.push(x);
	dis[x] = 0;
	while (q.size()) {
		int now = q.front();
		q.pop();
		vis[now] = true;
		for (int i = head[now]; i; i = next[i]) {
			int Y = to[i];
			if (dis[now] + edge[i] < dis[Y]) {
				dis[Y] = dis[now] + edge[i];
				if (!vis[Y]) {
					q.push(Y);
					vis[Y] = true;
				}
			}
		}
		vis[now] = false;
	}
	cal[x] = true;
	for (int i = m + 1; i <= m + n; ++i) {
		dp[x][i - m] = dis[i];
	}
	Ans = dis[Y];
	return true;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	//scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	c = in();
	n = in();
	m = in();
	d = in();
	q = in();
	for (int i = 1; i <= m; ++i)
		w[i] = in();
		//scanf("%d", &w[i]);
	for (int i = 1, k; i <= n; ++i){
		k = in();
		//scanf("%d", &k);
		for (int j = 1, a, t; j <= k; ++j) {
			a = in();
			t = in();
			//scanf("%d%d", &a, &t);
			add_edge(a, m + i, t);
			add_edge(m + i, a, t);
		}	
	}
	for (int i = 1; i <= q; ++i) {
		x[i] = in();
		y[i] = in();
		//scanf("%d%d", &x[i], &y[i]);
		Y = y[i];
		if (calc(x[i])){
			print(Ans + w[x[i]] + w[y[i]]);
			putchar('\n');
			//printf("%lld\n", Ans + w[x[i]] + w[y[i]]);
			continue;
		}
		Y = x[i];
		if (calc(y[i])){
			print(Ans + w[x[i]] + w[y[i]]);
			putchar('\n');
			//printf("%lld\n", Ans + w[x[i]] + w[y[i]]);
			continue;
		}
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (int j = 1; j <= n; ++j) {
			if (dp[x[i]][j] + dp[y[i]][j] < ans)
				ans = dp[x[i]][j] + dp[y[i]][j];
		}
		print(ans + w[x[i]] + w[y[i]]);
		putchar('\n');
		//printf("%lld\n", ans + w[x[i]] + w[y[i]]);
	}
	return 0;
}
