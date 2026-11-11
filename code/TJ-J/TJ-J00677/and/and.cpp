#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	int a[100005] , n , m , c;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	c=a[1]&a[2];
	for (int i = 1;i <= m-1;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			for (int l = j+1;l <= n;l++)
			{
				if(a[j]^a[l]>=c)
				{
					c=a[j]&a[l];
				}
			}
		}
	}
	cout << c;
} 
