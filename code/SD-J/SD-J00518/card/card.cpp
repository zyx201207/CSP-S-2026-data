#include<bits/stdc++.h>
using namespace std;
int a[500005];   
int b[500005] = {-1};
int ans[500005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j < i) continue;
			bool las = 0;
			for(int k = 1; k <= n; k++)
			{
				if(b[k] == a[j])
				{
					for(int t = k; t <= n; t++)
					{
						b[t] = -1;
						las = 1;
					}
				}
			}
			b[j] = a[j];
		}
		for(int j = 1; j <= n; j++)
		{
			bool b[1005] = {0};
			for(int k = 1; k <= m; k++)
			{
				if(b[j] == k && b[k] != 1)
				{
					ans[k]++;
					b[k] = 1; 
				}
			}
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
