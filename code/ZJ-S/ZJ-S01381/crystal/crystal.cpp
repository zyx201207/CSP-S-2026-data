#include <bits/stdc++.h>

using namespace std;

#define ll long long 

const int N = 5e5 + 5; 
int n, ans; ll a[N], s[N], m;

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

int main()
{
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout); 
	read(n); read(m); for (int i = 1; i <= n; ++i) { read(a[i]); }
	sort(a + 1, a + n + 1); 
	for (int i = 1; i <= n; ++i) 
	{ 
		s[i] = s[i - 1] + a[i]; 
		if (i < n && a[i] == a[i + 1]) { continue; }
		int l = 1, r = i, mid;
		while (l < r) 
		{
			mid = (l + r) / 2;
			ll ned = a[i] * (i - mid + 1) - (s[i] - s[mid - 1]); 
			if (ned > m) { l = mid + 1; }
			else { r = mid; }
		}
		ans = max(ans, i - r + 1);
	}
	write(ans);
	return 0; 
}
