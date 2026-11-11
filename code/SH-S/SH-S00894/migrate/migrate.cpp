#include <fstream>
#include <queue>
using namespace std;
ifstream fin("migrate.in");
ofstream fout("migrate.out");
using i64 = long long;
constexpr int MAXN = 305;
int n;
i64 d, x[MAXN];
int cnt[MAXN];
bool mem[MAXN][8];
int cache[MAXN][8];
queue<pair<int, int> > q;
void bfs(int st, int ed) {
	++cnt[st];
	mem[st][1] = 1;
	cache[st][1] = 0;
	q.push({st, 0});
	while (!q.empty()) {
		pair<int, int> x_ = q.front();
		q.pop();
		int u = x_.first, step = x_.second;
		if (u == ed) {
			if (cnt[ed] >= 3) continue;
			++cnt[ed];
			mem[ed][cnt[ed]] = 1;
			cache[ed][cnt[ed]] = step;
			continue;
		}
		if (cnt[u] >= 3) continue;
		++cnt[u];
		mem[u][cnt[u]] = 1;
		cache[u][cnt[u]] = step;
		for (int v = u - 1; v >= 1; --v) {
			if (x[u] - x[v] > d) break;
			if (cnt[v] >= 3) continue;
			q.push({v, step + 1});
		}
		for (int v = u + 1; v <= n; ++v) {
			if (x[v] - x[u] > d) break;
			if (cnt[v] >= 3) continue;
			q.push({v, step + 1});
		}
	}
	return ;
}
int main() {
	int c, t;
	fin >> c >> t;
	while (t--) {
		fin >> n >> d;
		for (int i = 1; i <= n; ++i) fin >> x[i];
		i64 ans = 0;
		for (int st = 1; st < n; ++st)
			for (int ed = st + 1; ed <= n; ++ed) {
				for (int u = 1; u <= n; ++u) {
					cnt[u] = 0;
					fill(mem[u], mem[u] + 5, 0);
					fill(cache[u], cache[u] + 5, 0);
				}
				bfs(st, ed);
				if (!mem[ed][2]) continue;
				if (mem[ed][3] && (cache[ed][2] == cache[ed][3])) continue;
				if (cache[ed][1] != cache[ed][2]) continue;
				++ans;
			}
		fout << ans << '\n';
	}
	return 0;
}
