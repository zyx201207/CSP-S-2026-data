#include <bits/stdc++.h>
using namespace std;
int n,cnt,c[30];
long long a[200050];
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for (int j = 1;j <= 26;j++)
		{
			cin >> c[j];
		}
	}
	
	for (int i = 1;i <= n;i++)
	{
		for (int j = i + 1;j <= n;j++)
		{
			if (a[i] != a[j])
			{
				cnt++;
			}
		}
	}
	cout << n - cnt * 2;
	return 0; 
}
