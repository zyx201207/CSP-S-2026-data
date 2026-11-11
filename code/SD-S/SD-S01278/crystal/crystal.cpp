//track in time
//Yh0326 448917 in Luogu
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l;i <= r;++ i)
#define per(i, r, l) for(int i = r;i >= l;-- i)
using namespace std;
typedef long long ll;
inline ll read()
{
	ll s = 0, w = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-'){w = -1;}ch = getchar();}
	while(isdigit(ch)) s = s * 10 + ch - 48, ch = getchar();
	return s * w;
}
const int mod = 998244353;
inline int ksm(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1) ans = (ll)ans * a % mod;
		a = (ll)a * a % mod;
		n >>= 1;
	}
	return ans;
}
int n;
ll m;
ll a[500004];
ll s[500004];
int ans = 1;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	rep(i, 1, n) a[i] = read();
	sort(a + 1, a + n + 1);
	s[0] = 0;
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	int l, r, mid;
	rep(i, 2, n)
	{
		l = 1, r = i - 1;
		while(l <= r)
		{
			mid = (l + r) >> 1;
			if(s[i - 1] - s[mid - 1] + m >= a[i] * (i - mid)) r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - r);
	}
	cout << ans << '\n';
	return 0;
}

