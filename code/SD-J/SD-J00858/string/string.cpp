#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[200010];
	char c[1000000001];
	int sum = 0;
	for (int i = 0;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	for (int i = 0;i <= n;i++)
	{
		for (int j = 0;j <= n;j++)
		{
			c[i]++;
		}
		sum ++;
	}
	cout << sum;
	return 0;
}
