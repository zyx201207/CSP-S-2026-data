// Íõ¿¬ä¿ SN-J00810 
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500004],b[300003],desk[300004],tong[300004];
bool having[300003];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;long long k = -1;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if (!having[a[j]])
				having[a[j]] = false;
		}
		for(int j = i;j <= n;j++)
		{
			if (!having[a[j]])
			{
				having[a[j]] = true;
				desk[a[j]] = j;
			}
			else
			{
				
				for(int k = desk[a[j]] + 1;k < j;k++)
				{
					having[a[k]] = false;
				}
				desk[a[j]] = j;
			}
		}
		for(int j = 1;j <= m;j++)
		{
			if (having[j])
				tong[j]++;
		}
	}
	for(int i = 1;i <= m;i++)
		cout << tong[i] << ' ';
	return 0;
}
