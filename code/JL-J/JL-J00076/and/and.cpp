#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N];
//任何数与上0都是0 数字与上它本身还是他本身
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	if(m == n)
	{
		int sum = a[0];
		for(int i = 1; i < n; i++)
		{
			sum = sum & a[i];
		}
		printf("%d\n", sum);
	}
	if(m == 1)
	{
		sort(a, a + n);
		printf("%d", a[n]);
	}
	if(m == 2)
	{
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				//cout << a[i] << ' ' << a[j] << ':';
				b[j] = a[i] & a[j];
				//cout << b[j] << '\n';
			}
			sort(b + i + 1, b + n + i + 1);
			ans = max(ans, b[n]);
			//cout << b[n] << '\n';
		}
		printf("%d", ans);
	}
	return 0;
}
 
