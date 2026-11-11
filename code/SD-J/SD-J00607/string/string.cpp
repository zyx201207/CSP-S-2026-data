#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200005;
int n;
int a[N];
char c[N];
long long cnt = 0;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	
	int i = 1, j = n;
	while (i < j)
	{
		if (a[i] == 0)
		{
			i++;
			continue;
		}
		if (a[j] == 0)
		{
			j--;
			continue;
		}
		
		if (c[i] == c[j])
		{
			if (a[i] > a[j])
			{
				a[i] -= a[j];
				j--;
			}
			else
			{
				a[j] -= a[i];
				i++;
			}
		}
		else
		{
			cnt += min(a[i], a[j]);
			if (a[i] > a[j])
			{
				a[i] -= a[j];
				j--;
			}
			else
			{
				a[j] -= a[i];
				i++;
			}
		}
	}
	cout << cnt;
	return 0;
}
