#include <bits/stdc++.h>
#define int long long
void gtmn(int& r, int p) { r = std::min(r, p); }
void gtmx(int& r, int p) { r = std::max(r, p); }
const int MAXN = 5e3 + 20;
const int INF = 1e18;

// 西瓜瓜我喜欢你喵

int c, T;

int n, d;
int pos[MAXN];
int f[MAXN];
int ans = 0;

void init() {
	scanf("%lld %lld", &n, &d);
	for (int i = 1; i <= n; i++) scanf("%lld", &pos[i]);
	ans = 0;
}

std::queue<int> reach;
int app[MAXN], way[MAXN], waysum[MAXN];

void solve() {
	for (int p = n; p >= 1; p--) {
		for (int i = 0; i <= n; i++) f[i] = INF, app[i] = 0, way[i] = 0, waysum[i] = 0; f[p] = 0;
		while(!reach.empty()) reach.pop();
		
		reach.push(p); app[f[p]]++; way[p] = 1; waysum[0] = 1;
		for (int i = p - 1; i >= 1; i--) {
			/*维护队列*/
			while (!reach.empty() && pos[reach.front()] - pos[i] > d) {
				app[f[reach.front()]] -= way[reach.front()];
				waysum[f[reach.front()]] -= way[reach.front()];
				reach.pop();
			}
			if (reach.empty()) break;
			if (app[f[reach.front()]] == 2) ans++;
			f[i] = f[reach.front()] + 1;
			way[i] = waysum[f[reach.front()]];
			reach.push(i); app[f[i]] += way[i]; waysum[f[i]] += way[i];
		}
	}
	printf("%lld\n", ans);
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld %lld", &c, &T);
	while(T--) {
		init();
		solve();
	}
	
	return 0;
}

// 当初的愿望实现了吗, 事到如今只好祭奠吗