#include <iostream>

const int N = 2e5+5;
int n, a[N], i, j;
long long ans;
char c[N], b;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	std::cin >> n;
	for(int i=1; i<=n; i++)
	{
		std::cin >> a[i];
		std::cin >> c[i];
	}
	i = 1, j = n;
	while(j > i)
	{
		if(c[i] != c[j])
		{
			if(a[i] > a[j])
			{
				ans += a[j];
				a[i] -= a[j];
				j --;
			}
			else
			{
				ans += a[i];
				a[j] -= a[i];
				i ++;
				if(a[j] == 0)
					j --;
			}
		}
		else
		{
			if(a[i] > a[j])
			{
				a[i] -= a[j];
				j --;
			}
			else
			{
				a[j] -= a[i];
				i ++;
				if(a[j] == 0)
					j --;
			}
		}
	}
	std::cout << ans << '\n';
	
	return 0;
}
