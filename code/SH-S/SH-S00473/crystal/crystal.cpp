#include<bits/stdc++.h>
using namespace std;

static int n;
static long long m;
constexpr int N = 5e5 + 10;
static long long a[N], prefix[N];

bool check(int x)
{
	for (int i = x; i <= n; i++)
	{
		long long sum = prefix[i] - prefix[i - x];
		if (abs(a[i] * x - sum) <= m)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		prefix[i] = prefix[i - 1] + a[i];
	}
	int l = 1, r = n;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (check(mid))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << l;
	return 0;
}
