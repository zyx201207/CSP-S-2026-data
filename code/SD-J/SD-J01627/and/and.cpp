#include <bits/stdc++.h>
using namespace std;
int n,m,a[200050];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i + 1;j <= n;j++)
		{
			if (a[i] < a[j])
			{
				a[j] = a[j] % a[i];
				cout << a[j];
				return 0;
			}
			else if (a[i] > a[j])
			{
				cout << a[j];
				return 0;
			}
			else
			{
				cout << a[j];
				return 0;
			}
		}
	}
	return 0; 
}
