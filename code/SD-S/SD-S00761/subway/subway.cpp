#include <bits/stdc++.h>
#define ll long long
#define mid ((l + r) >> 1)
#define lowbit(x) ((x) & -(x))

using namespace std;

namespace Fread {
	static constexpr int SIZE = 1 << 20;
	char buf[SIZE], *S, *T;
	inline char getchar() {
		if (S == T) {
			T = (S = buf) + fread(buf, 1, SIZE, stdin);
			if (S == T) return '\n';
		}
		return *S++;
	}
} // namespace Fread
namespace Fwrite {
	static constexpr int SIZE = 1 << 20;
	char buf[SIZE], *S = buf, *T = buf + SIZE;
	inline void flush() {
		fwrite(buf, 1, S - buf, stdout);
		S = buf;
	}
	inline void putchar(char c) {
		*S++ = c;
		if (S == T) flush();
	}
	struct Flush {
		~Flush() { flush(); }
	} f;
} // namespace Fwrite
#define getchar Fread::getchar
#define putchar Fwrite::putchar

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c - '0');
		c = getchar();
	}
	return x * f;
}

void write(int x) {
	if (x == 0) { putchar('0'); return; }
	if (x < 0) { putchar('-'); x = -x; }
	static int sta[45];
	int top = 0;
	while (x) { sta[++top] = x % 10; x /= 10; }
	while (top) { putchar(sta[top--] + '0'); }
}

constexpr int N = 505, M = 5e5 + 5;

int C, n, m, d, q;
int w[M], len[N];
ll dis[N][N];
vector<int> a[N], t[N];
vector<array<int, 2>> vec[M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	
	C = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; ++i) {
		w[i] = read();
	}
	for  (int i = 1; i <= n; ++i) {
		len[i] = read();
		a[i].resize(len[i] + 1);
		t[i].resize(len[i] + 1);
		for (int j = 1; j <= len[i]; ++j) {
			a[i][j] = read(), t[i][j] = read();
			vec[a[i][j]].push_back({i, t[i][j]});
		}
	}
	
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; ++i) {
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		int sz = vec[i].size();
		for (int j = 0; j < sz; ++j) {
			for (int k = j + 1; k < sz; ++k) {
				int u = vec[i][j][0], v = vec[i][k][0], w = vec[i][j][1] + vec[i][k][1];
				dis[u][v] = min(dis[u][v], (ll)w);
				dis[v][u] = min(dis[v][u], (ll)w);
			}
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[j][k]);
			}
		}
	}
	// ???
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dis[i][j] = min(dis[i][j], dis[j][i]);
		}
	}	
	
	while (q--) {
		int x = read(), y = read();
		
		ll ans = LONG_LONG_MAX;
		for (auto i : vec[x]) {
			for (auto j : vec[y]) {
				ans = min(ans, dis[i[0]][j[0]] + i[1] + j[1]);
			}
		}
		ans += w[x] + w[y];
		
		cout << ans << '\n';
	}
	
	cerr << "time: " << (double)clock() / CLOCKS_PER_SEC << '\n';
	
	return 0;
}
