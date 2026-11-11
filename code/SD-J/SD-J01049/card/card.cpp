#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[500005],p[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int t = 1;
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			for (int k = 1;k < t;k++)
			{
				if (f[k] == a[j])
				{
					t = k;
					break;
				}
			}
			f[t] = a[j];
			t++;
		}
		for (int j = 1;j < t;j++)
		{
			p[f[j]]++;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << p[i] << " ";
	}
	return 0;
}

