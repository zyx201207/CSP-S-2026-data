#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[100005];
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= m;i++)
	{
		int ans = 0;
		for (int j = 1;j <= n;j++)
		{
			if(a[j] == i)
			{
				ans++;
				a[j]++;
			}
			else
			{
				cout << ans << " ";
				break;
			}
		}
	}
	return 0;
}
