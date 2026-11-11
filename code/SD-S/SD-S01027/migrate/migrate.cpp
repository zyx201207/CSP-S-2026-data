#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i];
		}
		if(n<=3)cout << 0;
		else
		{
			if(a[4]-a[1]<=m)cout << 0;
			else cout << n-3;
		}
		cout << "\n";
	}
	return 0;
}
