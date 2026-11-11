#include <bits/stdc++.h>
using namespace std;
long long n , m , a[100005] , maxn , sy , num;
int main()
{
	freopen("crystal.in" , "r" ,stdin);
	freopen("crystal.out" , "w" ,stdout);
	cin >> n >> m;
	maxn = -10000;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n);
	for (int i = n;i > 0;i--)
	{
		num = 1;
		sy = m;
		for (int j = i - 1;j > 0;j--)
		{
			if (a[i] - a[j] > sy)
			{
				break;
			}
			sy -= a[i] - a[j];
			num++;
		}
		maxn = max(maxn , num);
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
