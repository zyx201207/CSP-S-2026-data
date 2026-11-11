#include <bits/stdc++.h>
using namespace std;

int n,m,a[500010],ans[300010] = {};
bool b[300010] = {};

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int q = 1;q <= n;q++)
	{
		for(int i = q;i <= n;i++)
		{
			if(b[a[i]] != 0)
			{
				int j;
				for(j = i - 1;a[i] != a[j];j--)
					a[j] = 0;
				a[j] = 0;
			}
			else
				b[a[i]] = 1;
		}
		for(int i = 1;i <= n;i++)
		{
			if(a[i] != 0)
				ans[a[i]]++;
		}
		for(int i = 1;i <= m;i++)
			b[i] = 0;
	}
	for(int i = 1;i <= m;i++)
		cout << ans[i] << " ";
	return 0;
}
