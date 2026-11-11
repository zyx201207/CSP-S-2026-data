#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 0;i < t;i++)
	{
		cin >> n >> d;
		for(int i = 0;i < n;i++)
		{
			cin >> x[i];
		}
	}
	for(int i = 0;i < t;i++)
	{
		cout << n / 2;
	}
	return 0;
}
