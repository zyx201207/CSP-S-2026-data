//zhoujingzhi 西安交通大学附属中学 SN-J00676 
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	int maxn = -1e9, mans;
	
	for (int i = 0; i < n; ++i) 
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
	}
	
	if (n <= 20)
	{
		int ans = -1e9;
		
		for (int i = (1 << n); i >= 1; --i)
		{
			int cnt = 0, now = 0;
			
			int flag = true;
			
			for (int j = 0; j < n; ++j)
			{
				if ((i & (1 << j)))
				{
					if (flag)
					{
						now = a[j];
						flag = false;
					}
					else
					{
						now = (now & a[j]);
					}
					
					++cnt;
				}
			}

			if (cnt == m) ans = max(ans, now);
		}
		
		cout << ans << endl;
	}
	else if (20 < n <= 2000)
	{
		mans = a[0];
		
		for (int i = 1; i < n; ++i)
		{
			mans = (mans & a[i]);
		}
		
		int t;
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == j) continue;
				
				t = (a[i] & a[j]);
			}
		}
		
		cout << max(mans, max(t, maxn)) << endl;
	}
	else
	{	
		sort(a, a + n);
		
		int ans = a[n - 1];
		
		for (int i = n - 2; i > n + 1 - m; --i)
		{
			ans = (ans & a[i]);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}

