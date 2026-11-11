#include <iostream>
#include <algorithm>

typedef long long ll;
const ll max_n = 5e5 + 10;
ll n, m;
ll a[max_n];
ll b[max_n];
ll ps[max_n];
ll s[max_n];
ll qwq(int l, int r)
{
	ll aa = ps[r];
//	std::cerr << "> "<< ps[r] << ' ' << ps[l] << ' ' << s[r] << ' ' << s[l]<< '\n';
	return (ps[r] - ps[l] - l * (s[r] - s[l]));
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
//	std::cout.tie(0);
	
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> a[i];
	}	
	std::sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++)
	{
		b[i] = a[i] - a[i - 1];
		ps[i] = ps[i - 1] + (b[i]) * (i);
		s[i] = s[i - 1] + b[i];
	}
	
//	for (int i = 1; i <= n; i++)
//	{
//		std::cerr << b[i] << ' ';
//	}
//	std::cerr << '\n';
//	for (int i = 1; i <= n; i++)
//	{
//		std::cerr << ps[i] << ' ';
//	}
//	std::cerr << '\n';
//	while (true)
//	{
//		int l, r;
//		std::cin >> l >> r;
//		std::cout << qwq(l, r) << '\n';
//	}

	int r = 1;
	int ans = 1;
	for (int l = 1; l <= n; l++)
	{
		while (qwq(l, r + 1) <= m && r <= n)
		{
			r++;
		}
		if (r <= n)
		{
//			std::cerr << "(" << l << ", " << r << ")\n";
			ans = std::max(ans, r - l + 1);
		}
		else 
		{
			break;
		}
	}
	std::cout << ans << '\n';
}
