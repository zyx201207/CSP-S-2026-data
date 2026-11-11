#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[500009];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		bool v=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i+2]-a[i]<d)
			{
				v=0;
				break;
			}
		}
		if(v==1)
		{
			cout<<0;
		}
	}
	return 0;
}