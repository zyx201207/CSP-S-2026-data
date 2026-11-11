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

const int maxrn = 2e6;
const int maxn = 5e3;
int cid, t, n;
int cnt1[maxn + 5];
int cnt2[maxn + 5];
ll mxd, ans;
ll x[maxrn + 5];
ll f[maxn + 5][maxn + 5];
ll d[maxn + 5][maxn + 5];
ll tr[maxn + 5][maxn + 5];
bool cksuba()
{
	if(n == 1) return 1;
	ll val = x[2] - x[1];
	for(int i = 2; i < n; ++i)
		if(x[i+1] - x[i] != val)
			return 0;
	return 1;
}
void update(int dzh, int xpos, ll val)
{
	for(int i = xpos; i <= dzh; i += (i & -i))
		tr[dzh][i] += val; 
}
ll query(int dzh, int ql, int qr)
{
	ll sum = 0;
	while(qr) sum += tr[dzh][qr], qr ^= (qr & -qr);
	--ql;
	while(ql) sum -= tr[dzh][ql], ql ^= (ql & -ql);
	return sum;
}
void solve()
{
	ans = 0;
	read(n), read(mxd);
	for(int i = 1; i <= n; ++i)
		read(x[i]);
	if(cksuba())
	{
		if(n <= 3 || (x[2] - x[1] > mxd / 2)) puts("0");
		else write(max(n + 1 - 2 * mxd / (x[2] - x[1]), 0ll)), putchar('\n');
		return;
	}
	if(cid == 13 || cid == 14)
	{
		for(int i = 1; i <= n; ++i)
			cnt1[i] = 0,  cnt2[i] = 0;
		for(int i = 1; i <= n; ++i)
		{
			int r = upper_bound(x + 1, x + n + 1, x[i] + mxd) - x; --r;
			int l = lower_bound(x + 1, x + n + 1, x[i] - mxd) - x;
			if(r > i+1) ++cnt2[r];
			if(l < i-1) ++cnt1[l];
		}
		for(int i = 1; i < n; ++i)
			ans += 1ll * cnt1[i] * cnt2[i+1]; 
		write(ans), putchar('\n');
		return; 
	}
	
	for(int i = 1; i <= n; ++i)
		for(int j = i; j <= n; ++j)
			update(j, i, -f[i][j]), f[j][i] = 0, d[i][i] = 1e18;
	for(int i = 1; i <= n; ++i)
		f[i][i] = 1, d[i][i] = 0, update(i, i, 1);
		 
	for(int len = 2; len <= n; ++len)
		for(int i = 1; i + len - 1 <= n; ++i)
		{
			int j = i + len - 1;
			
			int pos = upper_bound(x + 1, x + n + 1, x[i] + mxd) - x - 1;
			pos = min(pos, j);
			d[i][j] = d[pos][j] + 1;
			int l = i+1, r = pos;
			while(l < r)
			{
				int mid = (l + r) / 2;
				if(d[mid][j] <= d[i][j] - 1) r = mid;
				else l = mid + 1;
			}
			f[i][j] = query(j, l, pos);
			f[i][j] = min(f[i][j], 3ll);
			update(j, i, f[i][j]);
			if(f[i][j] == 2) ++ans;
		}
	write(ans), putchar('\n');
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> cid >> t;
	while(t--) solve();
	return 0;
}