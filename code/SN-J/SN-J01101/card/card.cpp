#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= m;i++)
	{
		cnt = 0;
		for(int j = 1;j <= n;j++)
		{
			if (a[j] == j)
			{
				cnt++;
			}
		}
		cout << cnt << " ";
	}
	return 0;
}
