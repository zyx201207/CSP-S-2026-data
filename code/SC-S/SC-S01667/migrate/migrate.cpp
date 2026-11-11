#include<bits/stdc++.h>
using namespace std;
long long xx[2000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c,t;
	cin>>c>>t;
	for (int o=1;o<=t;o++)
	{
		long long n,d;
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>xx[i];
		}
		long long sum=0;
		for (int i=1;i<n;i++)
		{
			if ((n-xx[i])%d+d>=2&&(xx[i]+2*d)>n) sum+=0;
			else if (xx[i]+d<n)
			{
				sum+=1;
			}
		}
		cout<<sum<<"\n";
		for (int i=1;i<=n;i++) xx[i]=0;
	}
	return 0;
} 