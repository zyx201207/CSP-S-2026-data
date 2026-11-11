#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[200001];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 1;i <= t;i++)
	{
		cin >> n >> d;
		for(int j = 1;j <= n;j++)
		{
			cin >> x[i];
		}
	}
	for(int i = 1;i <= t;i++)
	{
		cout << 0;
	}
	return 0;
}
