#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;

ll n, chars, ans;
ll lt, rt, ls, rs;
ll a[maxn];
ll cs[maxn];
char c[maxn];

ll llmin(ll a, ll b);

int main()
{
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	memset(a, 0, sizeof(a));
	memset(cs, 0, sizeof(cs));
	cin >> n;
	chars = 0;
	for(ll i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		chars += a[i];
		cs[i] = chars;
	}
	lt = 1;
	rt = chars;
	ls = 1;
	rs = n;
	ans = 0;
	while(ls < rs)
	{
		if(c[ls] != c[rs])
		{
			ans += llmin(cs[ls] - lt + 1, a[rs] - cs[rs] + rt);
		}
		if(cs[ls] - lt + 1 < a[rs] - cs[rs] + rt)
		{
			lt += cs[ls] - lt + 1;
			rt -= cs[ls] - lt + 1;
			ls++;
		}
		else if(cs[ls] - lt + 1 > a[rs] - cs[rs] + rt)
		{
			lt += a[rs] - cs[rs] + rt;
			rt -= a[rs] - cs[rs] + rt;
			rs--;
		}
		else
		{
			lt += a[rs] - cs[rs] + rt;
			rt -= a[rs] - cs[rs] + rt;
			ls++;
			rs--;
		}
	}
	cout << ans;
	return 0;
}

ll llmin(ll a, ll b)
{
	if(a >= b) return b;
	return a;
}
