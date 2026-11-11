#include <bits/stdc++.h>
#define int long long
using namespace std;

int len(int x)
{
	int res = 0;
	
	while(x != 0)
	{
		res++;
		x = x >> 1;
	}
	
	return res;
}

bool cmp(int x, int y)
{
	if(len(x) == len(y))
	{
		vector<int> a(len(x), 0);
		vector<int> b(len(y), 0);
		int idx1 = 0;
		int idx2 = 0;
		
		while(x != 0)
		{
			if(x & 1 == 1)
			{
				a[idx1] = 1;
			}
			
			idx1++;
			x = x >> 1;
		}
		
		while(y != 0)
		{
			if(y & 1 == 1)
			{
				a[idx2] = 1;
			}
			
			idx2++;
			y = x >> 1;
		}
		
		for(int i = idx1 - 1; i >= 0; i--)
		{
			if(a[i] != b[i])
			{
				return a[i] > b[i];
			}
		}
	}
	
	return len(x) > len(y);
}

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	
	cin >> n >> m;
	
	vector<int> a(n);
	int sum = 0;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		
		sum = sum + a[i];
	}
	
	if(m == 1)
	{
		int maxx = 0;
		
		for(int i = 0; i < n; i++)
		{
			maxx = max(maxx, a[i]);
		}
		
		cout << maxx;
		
		return 0;
	}
	
	if(m == 2 and n <= 2000)
	{
		int maxx = 0;
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i == j)
				{
					continue;
				}
				
				maxx = max(maxx, (a[i] & a[j]));
			}
		}
		
		cout << maxx;
		
		return 0;
	}
	
	if(m == n)
	{
		int ans = a[0];
		
		for(int i = 1; i < n; i++)
		{
			ans = ans & a[i];
		}
		
		cout << ans;
		
		return 0;
	}
	
	if(n <= 20)
	{
		sort(a.begin(), a.end(), cmp);
		
		int ans = a[0];
		
		for(int i = 1; i < m; i++)
		{
			ans = ans & a[i];
		}
		
		return 0;
	}
	
	if(m == n - 1)
	{
		sort(a.begin(), a.end(), cmp);
		
		int ans = a[0];
		
		for(int i = 1; i < m - 1; i++)
		{
			ans = ans & a[i];
		}
		
		return 0;
	}
	
	sort(a.rbegin(), a.rend());
	
	int ans = a[0];
	
	for(int i = 1; i < m; i++)
	{
		ans = ans & a[i];
	}
	
	cout << ans;
	
	return 0;
}
