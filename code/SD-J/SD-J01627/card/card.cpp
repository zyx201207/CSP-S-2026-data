#include <bits/stdc++.h>
using namespace std;
int n,m,a[500000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i + 1;j <= n;i++)
		{
			if (a[i] == a[j])
			{
				
			}
		}
	}
	return 0; 
}
