#include <bits/stdc++.h>
#define int long long
#define gc getchar()
#define pc putchar
using namespace std;
inline int read()
{
	int x = 0,p = 1;
	char c = gc;
	while(c > '9' || c < '0')	p = c == '-' ? -1 : 1,c = gc;
	while(c >= '0' && c <= '9')	x = (x << 1) + (x << 3) + (c ^ 48),c = gc;
	return p * x;
}
inline void write(char c) { pc(c); }
template<typename T> inline void _write(T x) { if(x > 9) _write(x / 10); pc(x % 10 | 48); }
template<typename T> inline void write(T x) { if(x < 0) x = -x,pc('-'); _write(x); }
template<typename T> inline void writeln(T x) { write(x); puts(""); }
template<typename... Argc> inline void write(Argc... argc) { int tmp[] = {(write(argc),0)...}; }
template<typename... Argc> inline void writeln(Argc... argc) { int tmp[] = {(write(argc),0)...}; puts(""); }
const int N = 2e6 + 10;
int c,T,n,d,a[N]; 
inline void solve()
{
	n = read(); d = read();
	for(int i = 1;i <= n;i++)	a[i] = read();
	if(c == 11 || c == 12)
	{
		int b = a[2] - a[1];
		int t = d / b;
		if(t <= 1)	return puts("0"),void();
		writeln(max(0ll,n - t * 2 + 1));
		return;
	}
	int ans = 0;
	for(int st = 1;st <= n;st++)
	{
		vector<vector<int> > dp(n + 1,vector<int>(n + 1));
		dp[st][0] = 1;
		for(int ed = st + 1;ed <= n;ed++)
			for(int lst = ed - 1;lst >= st;lst--)
			{
				if(a[ed] - a[lst] > d)	break;
				for(int len = 1;len <= ed - st;len++)
				{
					if(dp[lst][len - 1] == -1)	break;
					dp[ed][len] += dp[lst][len - 1];
				}
				for(int len = 1;len <= ed - st;len++)
					if(dp[ed][len] >= 3)	dp[ed][len] = -1;
			}
		for(int ed = st + 1;ed <= n;ed++)
			for(int len = 1;len <= ed - st;len++)
				if(dp[ed][len] != 0) { ans += dp[ed][len] == 2; break; }
	}
	writeln(ans);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(); T = read();
	while(T--)	solve();
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2


*/
