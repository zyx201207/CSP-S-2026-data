#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005], sum[500005], num;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		long long v = 0, numa = 0;
		for(int j = i - 1; j >= 1; j--)
		{
			v += a[i] - a[j];
			if(v > m)
			{ 
			   break;
			}
			numa++;
		}
		num = max(numa, num);
	}
	cout << num + 1;
	return 0;
}