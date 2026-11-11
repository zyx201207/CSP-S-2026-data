#include<bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n];
	int on[m + 1] = {0};
	queue<int> desk;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans[m + 1] = {0};
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; i++)
		{
			if (on[a[j]])
			{
				for (int k = 1; k < j; k++)
				{
					desk.pop();
				}
			}
			on[a[j]] = 1;
			desk.push(a[j]);
		}
		for (int j = 0; j < m; j++)
		{
			 ans[j] += on[j];
			 on[j] = 0;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
