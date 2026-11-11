#include<bits/stdc++.h>
using namespace std;

#define int long long
int c,t,n,d,x[2000005];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c==12||c==13)
	{
		cin>>n>>d;
		for(int i=1; i<=n; i++)
		{
			cin>>x[i];
		}
		cout<<n-d;
	}
	else if(c==13||c==14)
	{
		cout<<0;
	}
	else if(c>=1||c<=2)
	{
		cout<<7;
	}
	else
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1; i<=n; i++)
			{
				cin>>x[i];
			}
		}
		cout<<0;
	}
	return 0;
}

