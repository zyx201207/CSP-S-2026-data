#include <bits/stdc++.h>
using namespace std;
const long long N = 12e5 + 5;\
long long a[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, b,c, d, e;
	long long m;
	cin >> n >> m;
	for (int i= 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
		if(a[i +1] - a[i] == a[i + 2] - a[i + 1])
		{
			b  = a[n]- a[n- 1];	
			c = n / 2 + 1;
			for (int j = 1;  j<= c; j++)
			{
				d = b * 2;
			}
		}
	cout << m / d + 1;
	return 0;
}
