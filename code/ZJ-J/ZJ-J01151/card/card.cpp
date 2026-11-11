#include <bits/stdc++.h>
using namespace std;

int a[500005], cnt[300005], ans[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	bool f = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(i > 1 && a[i - 1] > a[i])f = 0;
	}
	
	if(f)
	{
		for(int i = n; i >= 1; i--)
		{
			if(a[i] == a[i + 1])continue;
			ans[a[i]] = i;
		}
		for(int i = 1; i <= m; i++)
			cout << ans[i] << " ";
		return 0;
	}
	if(n <= 500)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				cnt[j] = 0;
			for(int j = i; j <= n; j++)
			{
				if(cnt[a[j]] == 1)
				{
					int t = j - 1;
					while(a[t] != a[j])
					{
						cnt[a[t]] = 0;
						t--;
					}
				}
				else cnt[a[j]] = 1;
			}
			for(int j = 1;j <= m; j++)
				if(cnt[j])ans[j]++;
		}
		cout << ans[1];
		for(int i = 2; i <= m; i++)
			cout  << " " << ans[i];
		return 0;
	}
	if(m == 2)
	{
		bool f1 = 1;
		for(int i = 1; i <= n; i++)
		{
			if(i > 1 && a[i] != a[i - 1])f1 = 0;
		}
		if(f1)
		{
			if(a[1] == 1)cout << n << " " << 0;
			else cout << 0 << " " << n;
			return 0;
		}
		if(a[n] == 1)
		{
			ans[1] = n;
			for(int i = 1; i <= n; i++)
			{
				if(a[i] == 2)ans[2]++;
			}
		}
		else 
		{
			ans[2] = n;
			for(int i = 1; i <= n; i++)
				if(a[i] == 1)ans[1]++;
		}
		for(int i = 1; i <= m; i++)
			cout << ans[i] << " ";
		return 0;
	}
	if(m == 1)
	{
		cout << n;
		return 0;
	}
	return 0;
}
