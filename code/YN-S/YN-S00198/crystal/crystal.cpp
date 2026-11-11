#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 5e5 + 5;
#define ll long long
ll n, m;
ll a[N];
/*问题:不是最多,是最优,想要在check里面可以直接计算最优*/
bool check(int x)
{
	ll pos = 0;/*右端*/
	ll minn = 1e18;
	for (int i = x; i <= n; i++)
	{
		if (a[i] - a[i - x + 1] < minn)
		{
			minn = a[i] - a[i - x + 1];
			pos = i;
		}
	}
	ll sum = 0;
	for (int i = 0; i < x; i++)
	{
		sum += a[pos] - a[pos - i];
	}
		cout<<sum<<'\t';
	if (sum <= m)
	{
		cout<<"true\n";
		return true;
	}
	cout<<"false\n";
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1;
	int r = n;
	int ans;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
