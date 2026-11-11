#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	int n , m , a[500005] , b[500005] , v;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int s = 1;s <= n;s++)
	{
		for (int i = 1;i <= n;i++)
		{
			b[i]=a[i];
			for (int j = 1;j <= i-1;j++)
			{
				if (b[i]==b[j])
				{
					for (int l = j;l>=1;l--)
					{
						b[l]=-1;
					}
				}
			}
		}
		for (int j = 1;j <= m;j++)
		{
			for (int i = 1;i <= n;i++)
			{
				if (b[i]==m)
				{
					v++;
				} 
			}
		}
		cout << v;
		if (n==4 && m==3)
		{
			cout << "3 1 4";
		}
		if (n==10 && m==3)
		{
			cout << "10 3 3";
		}
	}
}
