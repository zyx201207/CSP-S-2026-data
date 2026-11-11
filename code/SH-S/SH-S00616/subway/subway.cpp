#include<bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
const int N = 505, M = 500005;
const ll inf = 0x3f3f3f3f3f3f3f3f;

namespace IO {

ll read() {
	ll ret = 0;
	int tag = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') tag = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		ret = ret*10 + ch - 48;
		ch = getchar();
	}
	ret *= tag;
	return ret;
}

void print(ll x) {
	if(!x) {
		putchar(48);
		return;
	}
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	int stk[25], top = 0;
	for(; x; x /= 10) stk[++top] = x % 10;
	for(; top; --top) putchar(stk[top] + 48);
}

}

using IO::read;
using IO::print;

int c, n, m, d, q;
ll w[M], e[N][N];
vector<pii> plt[M];

void floyd() {
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int k = 1; k <= n; ++k) {
				e[j][k] = min(e[j][k], e[j][i] + e[i][k]);
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for(int i = 1; i <= m; ++i) w[i] = read();
	for(int i = 1; i <= n; ++i) {
		int k = read();
		for(int j = 1; j <= k; ++j) {
			int a;
			ll t;
			a = read();
			t = read();
			plt[a].pb(mp(i, t));
		}
	}
	memset(e, inf, sizeof(e));
	for(int i = 1; i <= n; ++i) e[i][i] = 0;
	for(int i = 1; i <= m; ++i) {
		for(pii t1 : plt[i]) {
			for(pii t2 : plt[i]) {
				int u = t1.fi, v = t2.fi;
				ll w = t1.se + t2.se;
				if(u == v) continue;
				e[u][v] = w;
			}
		}
	}
	floyd();
	for(int i = 1; i <= q; ++i) {
		int x, y;
		ll ans = inf;
		x = read();
		y = read();
		for(pii t1 : plt[x]) {
			for(pii t2 : plt[y]) ans = min(ans, e[t1.fi][t2.fi] + t1.se + t2.se + w[x] + w[y]);
		}
		print(ans);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
