#include <cstdio>
#include <algorithm>
namespace FastIn
{
	const int S = 4e6 + 7;
	char *p1, *p2, buf[S];
	#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, S, stdin), p1 == p2) ? EOF : *p1++)
	template <typename _T>
	inline void read(_T &x)
	{
		x = 0;
		char c = gc();
		bool isneg = false;
		for (; c < '0' || c > '9'; c = gc())
			isneg |= c == '-';
		for (; c >= '0' && c <= '9'; c = gc())
			x = (x << 3) + (x << 1) + (c & 15);
		isneg && (x = -x);
	}
	#undef gc
}
using FastIn::read;
const int MAXN = 5e5 + 7;
int n;
long long m, a[MAXN], s[MAXN];
inline bool chk(const int k)
{
	for (int i = k; i <= n; ++i)
		if (k * a[i] - (s[i] - s[i - k]) <= m)
			return true;
	return false;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	int l = 1, r = n, mid;
	while (l < r)
		if (chk(mid = (l + r + 1) >> 1))
			l = mid;
		else
			r = mid - 1;
	printf("%d", l);
	fclose(stdin), fclose(stdout);
	return 0;
}