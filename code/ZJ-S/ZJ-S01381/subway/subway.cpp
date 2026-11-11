#include <bits/stdc++.h>

using namespace std;

#define ll long long 

namespace IO
{
#define gc getchar
#define pc putchar
	template<typename T> inline void read(T& x)
	{
		x = 0; char ch = gc(); int w = 1; 
		while (!isdigit(ch)) { if (ch == 0x2d) { w = 0; } ch = gc(); }
		while (isdigit(ch)) { x = x * 0xa + ch - 0x30; ch = gc(); }
		x = w ? x : -x; 
	}
	template<typename T> inline void write(T x)
	{
		if (x < 0) { pc(0x2d); x = -x; }
		if (x > 9) { write(x / 0xa); }
		pc(x % 0xa + 0x30);
	}
} using namespace IO;

const int N = 505, M = 5e5 + 5; 
const ll INF = 1e15;
int c, n, m, d, q; ll w[M];
vector<int> a[N]; vector<ll> t[N]; int k[N];
vector<pair<int, int> > b[M];
ll f[N][N];

int main()
{
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	read(c); read(n); read(m); read(d); read(q); for (int i = 1; i <= m; ++i) { cin >> w[i]; }
	for (int i = 1; i <= n; ++i)
	{
		read(k[i]); a[i].resize(k[i] + 2); t[i].resize(k[i] + 2);
		for (int j = 1; j <= k[i]; ++j) { read(a[i][j]); read(t[i][j]); b[a[i][j]].push_back(make_pair(i, j)); }
	}
	for (int i = 1; i <= n; ++i) { for (int j = i + 1; j <= n; ++j) { f[i][j] = f[j][i] = INF; } f[i][i] = 0; }
	for (int i = 1; i <= n; ++i) 
	{
		for (int j = 1, p; j <= k[i]; ++j)
		{
			p = a[i][j]; int o = b[p].size(); 
			for (int oo = 0; oo < o; ++oo)
			{
				int ii = b[p][oo].first, jj = b[p][oo].second;
				if (i != ii) { f[i][ii] = min(f[i][ii], t[i][j] + t[ii][jj]); }
			}
		}
	}
// ---
	for (int kk = 2; kk <= n; ++kk) { for (int ii = 1; ii < kk; ++ii) { for (int jj = 1; jj <= n; ++jj) { f[jj][ii] = f[ii][jj] = min(f[ii][jj], f[ii][kk] + f[kk][jj]); } } }
// ---
	ll ans;
	for (int i = 1, x, y; i <= q; ++i)
	{
		read(x); read(y); ans = INF; int o1 = b[x].size(), o2 = b[y].size(), p1, p2;
		for (int oo1 = 0; oo1 < o1; ++oo1) 
		{ 
			p1 = b[x][oo1].first; 
			for (int oo2 = 0; oo2 < o2; ++oo2) 
			{ 
				p2 = b[y][oo2].first; 
				ans = min(ans, f[p1][p2] + t[p1][b[x][oo1].second] + t[p2][b[y][oo2].second]); 
		} }
		ans+= w[x] + w[y]; write(ans); putchar(0xa);
	}
	return 0; 
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
