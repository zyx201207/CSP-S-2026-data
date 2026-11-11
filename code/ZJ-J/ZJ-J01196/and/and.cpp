#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],x[200001][41],ans;
bool used[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		int p = a[i];
		int cnt = 0;
		while (p > 0)
		{
			x[i][cnt++] = p%2;
			p/=2;
		}
	}
	for (int i=32;i>=0;i--)
	{
		int cnt = 0;
		for (int j=1;j<=n;j++)
		{
			if (used[j] == 1)
			{
				continue;
			}
			cnt+=x[j][i];
		}
		if (cnt >= m)
		{
			for (int j=1;j<=n;j++)
			{
				if (x[j][i] == 0)
				{
					used[j] = 1;
				}
			}
			ans+=pow(2,i);
		}
	}
	cout << ans;
	return 0;
}