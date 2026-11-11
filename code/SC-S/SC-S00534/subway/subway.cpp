#include <bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define ll long long
using namespace std;

template <typename T>
void read(T& x)
{
	int f = x = 0, v = getchar();
	while((v != '-') && (v < '0' || v > '9')) v = getchar();
	if(v == '-') f = 1, v = getchar();
	while(v >= '0' && v <= '9') x = (x << 3) + (x << 1) + (v & 15), v = getchar();
	if(f) x = -x;
}
template <typename T>
void write(T x)
{
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x | 48);
	else write(x / 10), putchar((x % 10) | 48);
}
const int maxn = 500;
const int maxm = 5e5;

int cid, n, m, d, q, len, x, y;
ll ans;
int w[maxm + 5];
vector<pii> g[maxm + 5];
ll f[maxn + 5][maxn + 5];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read(cid), read(n), read(m), read(d), read(q);
	for(int i = 1; i <= m; ++i)
		read(w[i]);
	for(int i = 1; i <= n; ++i)
	{
		read(len);
		for(int j = 1; j <= len; ++j)
			read(x), read(y), g[x].emplace_back(i, y);
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			if(i != j)
				f[i][j] = 1e18;
		}
	for(int i = 1; i <= m; ++i)
	{
		for(pii j : g[i])
			for(pii k : g[i])
			{
				f[j.fir][k.fir] = min(f[j.fir][k.fir], 0ll + j.sec + k.sec);
			}
	}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
			{
				if(i == j || i == k || j == k) continue;
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
	while(q--)
	{
		read(x), read(y);
		ans = 1e18;
		for(pii i : g[x]) 
			for(pii j : g[y])
				ans = min(ans, f[i.fir][j.fir] + i.sec + j.sec);
		ans += w[x] + w[y];
		write(ans), putchar('\n');
	} 
	return 0;
}

//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

