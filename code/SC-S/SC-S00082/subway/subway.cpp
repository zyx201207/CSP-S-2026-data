#include <cstdio>
#include <algorithm>
#include <cctype>
typedef long long ll;
constexpr int N = 505, M = 500005, P = M * 20;
constexpr ll INF = 100000000000000000;
int test_case;
namespace fin {
	constexpr int FINBUFSIZ = 10000000;
	char inp_buf[FINBUFSIZ], *inp = inp_buf + FINBUFSIZ;
	const char& nxtchar() {
		if(inp == inp_buf + FINBUFSIZ)
			fread(inp = inp_buf, 1, FINBUFSIZ, stdin);
		return *inp++;
	}
	int read() {
		int val = 0;
		char c = nxtchar();
		while(!isdigit(c))
			c = nxtchar();
		while(isdigit(c)) {
			val = val * 10 + (c - 48);
			c = nxtchar();
		}
		return val;
	}
}
using fin::read;
int n, m, d, q;
ll get_out[M]; // M!
ll w[N], f[N][N]; // N as line-cnt
struct sv_Edge {
	int u, v, w;
};
sv_Edge e[M << 1];
int ecnt, deg[M], re_deg[M]; // M!
int h[N]; // N as line-cnt
struct Edge {
	int ver, w;
};
Edge G[P];
int main() {
	//qwq rp++!
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	test_case = read();
	n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++)
		get_out[i] = read();
	for(int p = 1, k; p <= n; p++) {
		k = read();
		for(int i = 1, zh, w; i <= k; i++) { // zh stands for which station(Ting)
			zh = read(), w = read();
			deg[zh]++;
			e[++ecnt] = {zh, p, w};
		}
	}
	for(int i = 1; i <= m; i++) {
		re_deg[i] = deg[i - 1] + 1;
		deg[i] += deg[i - 1];
	}
	for(int i = 1; i <= ecnt; i++)
		G[re_deg[e[i].u]++] = {e[i].v, e[i].w};
	for(int u = 1; u <= n; u++) {
		for(int v = 1; v <= n; v++)
			f[u][v] = INF;
		f[u][u] = 0;
	}
	for(int p = 1; p <= m; p++) {
		int cnt = 0;
		for(int i = deg[p - 1] + 1; i <= deg[p]; i++)
			w[++cnt] = G[i].w, h[cnt] = G[i].ver;
		for(int i = 1; i <= cnt; i++)
			for(int j = i + 1; j <= cnt; j++) {
				const int& u = h[i], &v = h[j];
				f[u][v] = f[v][u] = std::min(f[u][v], w[i] + w[j]);
			}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
	for(int rep = 1, x, y; rep <= q; rep++) {
		x = read(), y = read();
		ll ans = get_out[x] + get_out[y];
		ll dist = INF;
		for(int i = deg[x - 1] + 1; i <= deg[x]; i++)
			for(int j = deg[y - 1] + 1; j <= deg[y]; j++)
				dist = std::min(dist, f[G[i].ver][G[j].ver] + G[i].w + G[j].w);
		printf("%lld\n", ans + dist);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}