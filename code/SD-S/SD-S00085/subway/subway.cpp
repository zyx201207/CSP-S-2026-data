#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ull unsigned ll
const int BUFSI = 1<<20;
static char buf[BUFSI], *bg = buf, *ed = buf;
inline int gc() {
	if(bg == ed) {
		bg = buf;
		ed = buf + fread(buf, 1, BUFSI, stdin);
	}
	if(bg == ed) return  EOF;
	return *bg++;
} 
template<typename T>
bool fr(T &x) {
	x = 0;
	int ch = gc(), sgn = 0;
	while(ch != EOF && !isdigit(ch)) {
		sgn |= ch == '-';
		ch = gc();
	}
	if(ch == EOF) return 0;
	while(ch != EOF && isdigit(ch)) {
		x = x*10 + ch - '0';
		ch = gc();
	}
	if(sgn) x = -x;
	return 1;
}
bool fr(string &x) {
	x.clear();
	int ch = gc();
	while(ch != EOF && isspace(ch)) ch = gc();
	if(ch == EOF) return 0;
	while(ch != EOF && !isspace(ch)) {
		x += ch;
		ch = gc();
	}
	return 1;
}
template<typename T, typename ...A>
bool fr(T &x, A &...a) {
	bool ok = 1;
	ok &= fr(x);
	ok &= fr(a...);
	return ok;
}

const int N = 1005;
int c, n, m, d, q;
ll w[N];
vector<pll> G[N];
ll dis[N][N];
#define fi first
#define se second
#define pb push_back


void floyd() {
	for(int k = 1; k <= m; k++) {
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= m; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	fr(c, n, m, d, q);
	for(int i = 1; i <= m; i++) fr(w[i]);
	for(int i = 1; i <= n; i++) {
		int k; fr(k);
		for(int j = 0; j < k; j++) {
			ll a, t;
			fr(a, t);
			G[i].push_back({a, t});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i<= m; i++) dis[i][i] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < (int)G[i].size(); j++) {
			pll xx = G[i][j];
			ll u = xx.fi;
			ll len1 = xx.se;
			for(int k = j+1; k < (int)G[i].size(); k++) {
				pll yy = G[i][k];
				ll v = yy.fi;
				ll len2 = yy.se;
				dis[u][v] = min(dis[u][v], len1 + len2);
				dis[v][u] = min(dis[v][u], len1 + len2);
			}
		}
	}
	floyd();
	for(int i = 1; i<= q; i++) {
		int x, y;
		fr(x, y);
		cout << dis[x][y] + w[x] + w[y] << '\n'; 
	}
	
}

