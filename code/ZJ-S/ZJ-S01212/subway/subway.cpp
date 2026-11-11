#include <iostream>
#include <cstring>
using namespace std;
typedef long long Int;

const Int N = 501;
const Int M = 500001;
const Int D = 21;
const Int INF = 1145141919810;
const Int MMAX = 4557430888798830399;
Int c, n, m, d, q;
Int w[N], k[N], a[N][D], t[N][D];
Int we0[M][D], ogcnt[M], ogt[M][D];
Int g[N][N], dis[N][N];
Int dis1[N][N], dis2[N][N], cnt;
Int x, y, ans, f1, f2;

void floyd();
void input_data();
void build_subway();
void appreciate();
void wanna_ask();

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	input_data();
	build_subway();
	floyd();
	
	while (q--) wanna_ask();
	return 0;
}

void input_data() {
	cin >> c >> n >> m >> d >> q;
	for (Int i = 1; i <= m; i++) cin >> w[i];
	for (Int i = 1; i <= n; i++) {
		cin >> k[i];
		for (Int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			we0[ a[i][j] ][ ++ogcnt[ a[i][j] ] ] = t[i][j];
			ogt[ a[i][j] ][   ogcnt[ a[i][j] ] ] = i;
		}
	}
}

void build_subway() {
	memset(g, 0x3f, sizeof(g));
	
	for (Int i = 1; i <= m; i++)
		for (Int u = 1; u <= ogcnt[i]; u++) 
			for (Int v = 1; v < u; v++)
				g[ ogt[i][u] ][ ogt[i][v] ] 
			  = g[ ogt[i][v] ][ ogt[i][u] ]
			  = min(g[ ogt[i][u] ][ ogt[i][v] ], 
			  		we0[i][v] + we0[i][u]);		
}

void floyd() {
	memset(dis1, 0x3f, sizeof(dis1));
	memset(dis2, 0x3f, sizeof(dis2));
	
	auto d1 = dis1, d2 = dis2;
	
	for (Int i = 1; i <= n; i++)
		for (Int j = 1; j <= n; j++)
			if (g[i][j] != 0) d1[i][j] = g[i][j];
	
	for (Int k = 1; k <= n; k++) {
		for (Int i = 1; i <= n; i++)
			for (Int j = 1; j <= n; j++)
				d2[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
		swap(d1, d2); cnt++;
	}
	
	for (Int i = 1; i <= n; i++)
		for (Int j = 1; j <= n; j++)
			dis[i][j] = (i == j ? INF : (cnt%2?d1[i][j]:d2[i][j]));
}

void wanna_ask() {
	cin >> x >> y;
	
	ans = INF;

	for (Int c = 1; c <= n; c++) {
		f1 = 0;
		for (Int i = 1; i <= ogcnt[x]; i++)
			if (ogt[x][i] == c) {
				f1 = i; break;
			}
		if (!f1) continue;
		
		f2 = 0;
		for (Int i = 1; i <= ogcnt[y]; i++)
			if (ogt[y][i] == c) {
				f2 = i; break;
			}
		if (!f2) continue;
		ans = min(ans, we0[x][f1] + we0[y][f2]);
	}
	
	for (Int c1 = 1; c1 <= n; c1++) {
		f1 = 0;
		for (Int i = 1; i <= ogcnt[x]; i++)
			if (ogt[x][i] == c1) {
				f1 = i; break;
			}
		if (!f1) continue;
		
		for (Int c2 = 1; c2 <= n; c2++) {
			if (c1 == c2) continue;
			f2 = 0;
			for (Int i = 1; i <= ogcnt[y]; i++)
				if (ogt[y][i] == c2) {
					f2 = i; break;
				}
			if (!f2) continue;
			ans = min(ans, we0[x][f1] + we0[y][f2] + dis[c1][c2]);
		}
	}
	
	cout << ans + w[x] + w[y] << endl;	
}

// god promise data water
// maybe only hangshida computer slow
// O(nd^2) with an enormous constant


