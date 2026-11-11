#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 5;

int n;
ll m;

ll a[N];
ll sum1[N], sum2[N];

ll sum(int l, int r)
{
	l--, r--;
	return sum2[r] - sum2[l] - l * (sum1[r] - sum1[l]);
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n; i++)
	{
		sum1[i] = sum1[i - 1] + (a[i + 1] - a[i]);
		sum2[i] = sum2[i - 1] + (a[i + 1] - a[i]) * i;
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = i, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (sum(i, mid) <= m)
				l = mid + 1;
			else
				r = mid;
		}
		
		ans = max(ans, l - i);
	}
	
	cout << ans;
	
	return 0;
}