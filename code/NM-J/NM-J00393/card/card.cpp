#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int ans[300005];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		ans[a[i]]++;
	}
	for(int i = 1;i <= m;i++)
	{
		ans[i] *= n; 
	}
	for(int i = 1;i <= n;i++)
	{
		if(i >= 2)
		{
			for(int j = 1;j <= i;j++)
			{
				ans[a[j]]--;
			}
		}
		for(int j = n - 1;j >= i;j--)
		{
			if(a[j] == a[n])
			{
				for(int k = j;k <= n;k++)
				{
					ans[a[k]]--;
				}
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
