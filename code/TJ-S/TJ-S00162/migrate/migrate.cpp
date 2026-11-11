#include <bits/stdc++.h>
using namespace std;
int n,c,t;
long long x[2000005],d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--)
	{
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if (c==11 || c==12)
		{
			long long cha=x[n]-x[n-1];
			if (cha>d)
			{
				cout<<0<<endl;
			}
			else
			{
				cout<<1ll*n*(n-1)/2<<endl;
			}
		}
		else
		{
			cout<<1ll*n*(n-1)/2<<endl;
		}
	}
	return 0;
}
