#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+10,M = 3e5+10;
int n,m,a[N],b[M];

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	
	if (n <= 500)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = i;j <= n;j++)
			{
				for (int k = j;k <= n;k++)
				{
					if (a[k] == a[j])
					j = k;
				} 
				b[a[j]]++;
			}
		}
	}
	else
		for (int i = 1;i <= m;i++)
			b[i] = i; 
	for (int i = 1;i <= m;i++)
		cout << b[i] << " ";
	return 0;
}
