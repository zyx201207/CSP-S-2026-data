#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
const int N = 5e5 + 10;
typedef long long ll;

ll a[N];
int cnt[N];
ll rl[N];
int c[N];
ll sum[N];
std::vector<ll> vec;

template<typename T>
void rd(T &x)
{
	x = 0;
	int f = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if (c == '-')
			f = -f;
		c = getchar();
	}
	while (isdigit(c))
	{
		x = (x << 1) + (x << 3) - '0' + c;
		c = getchar();
	}
	x *= f;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	rd(n), rd(m);
	for (int i = 1; i <= n; ++i)
		rd(a[i]), vec.push_back(a[i]);
	std::sort(vec.begin(), vec.end());
	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
	int tot = vec.size();
	for (int i = 1; i <= n; ++i)
	{
		int t = std::lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
		cnt[t]++;
		rl[t] = a[i];
	}
	int ans = 0;
	for (int i = 1; i <= tot; ++i)
	{
		c[i] = c[i - 1] + cnt[i];
		sum[i] = sum[i - 1] + rl[i] * cnt[i];
	}
	for (int r = 1, l = 1; r <= tot; ++r)
	{
		while (l <= r && rl[r] * (c[r] - c[l - 1]) - (sum[r] - sum[l - 1]) > m)
			l++;
		if (l - 1 > 0)
		{
			ll dis = rl[r] - rl[l - 1];
			ans = std::max(ans, c[r] - c[l - 1] + (int)((m - (rl[r] * (c[r] - c[l - 1]) - (sum[r] - sum[l - 1]))) / dis));
		}
		else
			ans = std::max(ans, c[r] - c[l - 1]);
	}
	cout << ans << '\n';
	return 0;
}
