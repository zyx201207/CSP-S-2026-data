#include <cstdio>
#include <vector>

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

void write(long long x) {
	char buf[20], len = 0;
	while (x) {
		buf[len ++] = x % 10, x = x / 10;
	}
	while (len --) {
		putchar(buf[len] | 48); 
	}
	putchar('\n');
	return;
}

const long long inf = 1000000000000000000;
int n, m, a[500000], q;
long long dis[500][500];
std::vector<std::pair<int, int>> V[500000];

long long min(long long x, long long y) {
	return ((x < y) ? x : y);
}

void init() {
	read(), n = read(), m = read(), read(), q = read();
	for (int i = 0; i < m; i ++) {
		a[i] = read();
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			dis[i][j] = inf;
		}
		dis[i][i] = 0;
	}
	for (int i = 0; i < n; i ++) {
		int K = read();
		while (K --) {
			int p = read() - 1, t = read();
			V[p].push_back({i, t});
		}
	}
	for (int i = 0; i < m; i ++) {
		for (std::pair<int, int> u: V[i]) {
			for (std::pair<int, int> v: V[i]) {
				dis[u.first][v.first] = min(dis[u.first][v.first], u.second + v.second);
			}
		}
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			for (int k = 0; k < n; k ++) {
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
			}
		}
	}
	return;
}

void calculate() {
	while (q --) {
		long long ans = inf;
		int s = read() - 1, t = read() - 1;
		for (std::pair<int, int> u: V[s]) {
			for (std::pair<int, int> v: V[t]) {
				ans = min(ans, dis[u.first][v.first] + u.second + v.second);
			}
		}
		write(ans += a[s] + a[t]);
	}
	return;
}

void solve() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	init(), calculate();
	return;
}

int main() {
	solve();
	return 0;
}