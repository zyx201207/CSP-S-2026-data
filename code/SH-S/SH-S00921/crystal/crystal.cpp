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
const int N = 5e5 + 10;
int n,m,a[N],s[N];
inline int sum(int l,int r) { return s[r] - s[l - 1]; }
inline int cost(int l,int r) { return a[r] * (r - l + 1) - sum(l,r); }
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(); m = read();
	for(int i = 1;i <= n;i++)	a[i] = read();
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)	s[i] = s[i - 1] + a[i];
	int ans = 1;
	for(int l = 1,r = 1;l <= n && r <= n;l++)
	{
		if(l > r)	r = l;
		while(cost(l,r + 1) <= m && r < n)	r++;
		ans = max(ans,r - l + 1);
	}
	writeln(ans);
	return 0;
}
/*


5 5
1 2 4 8 9

3

*/
