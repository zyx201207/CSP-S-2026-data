#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long m, n, a[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int t = a[2] - a[1];
	int d = m / t;
	int cnt = 0, sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cnt+= i * t;
		if(d < cnt)	break;
		sum++;
	}
	cout << sum + 1;
	return 0;
}
