#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 5e5 + 5;
int n;
int ans = 0;
long long m;
long long a[maxn];
long long pre[maxn];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	pre[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = i, mid = 0;
		while(r > l)
		{
			mid = (l + r) >> 1;
			if (a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) <= m)
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << endl;
	return 0;
}