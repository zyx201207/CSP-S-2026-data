#include <bits/stdc++.h>
using namespace std;

long long a[500010];
long long m, sum;
int n, l, r, maxl;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	l = 1;
	r = 1;
	
	while(r <= n || sum > m)
	{
		if (sum > m)
		{
			sum -= a[r]-a[l];
			l++;
		}
		else 
		{
			if (maxl < r-l+1) maxl = r-l+1;
			r++;
			sum += (a[r]-a[r-1])*(r-l);
		}
	}
	
	cout << maxl;
	
	return 0;
}
