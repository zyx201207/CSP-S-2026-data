#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int flag = 1;
	int n, m;
	
	cin >> n >> m;
	
	if(n == 1)
	{
		cout << "1";
	}
	
	vector<int> a(n);
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	int c = a[1] - a[0];
	
	for(int i = 2; i < n; i++)
	{
		if(a[i] - a[i - 1] != c)
		{
			flag = 0;
		}
	}
	
	if(flag == 1)
	{
		sort(a.rbegin(), a.rend());
		
		int ans = 1;
		
		for(int i = 1; i < n; i++)
		{
			if(m - c * i >= 0)
			{
				ans++;
				m = m - c * i;
			}
			else
			{
				cout << ans;
				
				return 0;
			}
		}
		
		cout << ans;
		
		return 0;
	}
	
	int ans = 0;
	
	for(int i = a[0]; i <= a[n - 1]; i++)
	{
		int num = 0;
		int mm = m;
		
		for(int j = n - 1; j >= 0; j--)
		{
			if(a[j] <= i)
			{
				if(mm - (i - a[j]) >= 0)
				{
					num++;
					mm = mm - (i - a[j]);
				}
			}
		}
		
		ans = max(ans, num);
	}
	
	cout << ans;
	
	return 0;
}
