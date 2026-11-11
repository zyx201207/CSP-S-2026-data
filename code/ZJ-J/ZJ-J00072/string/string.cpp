#include <algorithm>
#include <cstdio>
#include <string>

typedef long long int ll;
constexpr int N = 2e5 + 5;

struct String
{
	ll l, r;
	char c;
};

ll merge(ll l1, ll r1, ll l2, ll r2);
char find(ll x);

ll n, m, ans, mid, l, r, ls, rs;
String str[N];

int main(void)
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%lld", &n);
	
	for (int i = 1; i <= n; i++)
	{
		ll len;
		scanf("%lld %c", &len, &str[i].c);
		
		str[i].l = m + 1;
		str[i].r = m + len;
		
		m += len;
	}

	if (m % 2 == 1)
	{
		m--;
		mid = m / 2;
		
		for (int i = 1; i <= n; i++)
		{
			if (str[i].l > mid + 1) str[i].l--;
			if (str[i].r > mid + 1) str[i].r--;
		}
	}
	else mid = m / 2;

	l = mid;
	r = mid + 1;

	for (int i = 1; i <= n; i++)
	{
		if (str[i].l <= l && l <= str[i].r) ls = i;
		if (str[i].l <= r && r <= str[i].r) rs = i;
	}
	
	while (l > 0 || r < m + 1)
	{
		if (mid - l < r - mid - 1)
		{
			if (find(str[ls].l) != find(r - 1) && find(l) != find(r - 1)) ans += merge(str[ls].l, l, std::max(str[rs - 1].l, mid + 1), r - 1);
			
			l = str[ls].l - 1;
			ls--;
		}
		else
		{
			if (find(l + 1) != find(str[rs].r) && find(l + 1) != find(r)) ans += merge(l + 1, std::min(str[ls + 1].r, mid), r, str[rs].r);
			
			r = str[rs].r + 1;
			rs++;
		}
	}
	
	printf("%lld", ans);
	
	#define _ 0
	return ~~(0^_^0);
	#undef _
}

ll merge(ll l1, ll r1, ll l2, ll r2)
{
	l1 = m - l1 + 1;
	r1 = m - r1 + 1;
	
	std::swap(l1, r1);
	
	if (r1 < l2) return 0;
	else if (l1 <= l2 && r2 <= r1) return r2 - l2 + 1;
	else if (l2 <= l1 && r1 <= r2) return r1 - l1 + 1;
	else if (l1 <= l2 && r1 <= r2) return r1 - l2 + 1;
	else if (l2 <= l1 && r2 <= r1) return r2 - l1 + 1;
	else return 0;
}

char find(ll x)
{
	ll l = 1, r = n;
	
	while (l < r)
	{
		ll mid = (l + r) >> 1;
		
		if (str[mid].l <= x && x <= str[mid].r) return str[mid].c;
		else if (str[mid].l > x) r = mid - 1;
		else if (str[mid].r < x) l = mid + 1;
	}
	
	return str[l].c;
}

