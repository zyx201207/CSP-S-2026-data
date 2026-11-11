#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	int a[105]; 
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	} 
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (a[i] == j)
			{
				cout << i;
			}
		}
	}
	return 0;
}
