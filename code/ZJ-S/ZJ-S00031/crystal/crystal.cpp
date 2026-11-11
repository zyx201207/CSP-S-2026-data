#include <bits/stdc++.h>
using namespace std;

long long a[500010];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n, m, sum = 0, result = 0, cnt = 0;
	cin >> n >> m;
	for (long long i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (long long i = 0; i < n; i++)
	{
		sum += (a[i + 1] - a[i]) * (i + 1);
		long long suma = sum + (a[i + 2] - a[i+1]) * (i + 2);
		if (sum == m || suma > m)
		{
			long long jia = 2;
			for (long long j = i + 2; j < n; j++)
			{
				if (a[j] == a[i + 1]) jia++;
			}
			result = i + jia;
			break;
		}
	}
	cout << result << endl;
	
	return 0;
}
