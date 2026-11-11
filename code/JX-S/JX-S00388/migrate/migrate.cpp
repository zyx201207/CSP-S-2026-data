#include<bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	for(int o=1;o<=t;o++)
	{
		int n;
		long long d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			s[i]=x[i]-x[1];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(s[j]-s[i]<=d) e[i].push_back(j);
			}
		}
	}
	cout<<0;
	return 0;
}
