#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,f=1,m=0,n,d;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		f=1;
		cin>>n>>d;
		long long x[n+5],s[n+5];
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
			s[j-1]=x[j]-x[j-1];
		
		}
		for(int j=1;j<=n-2;j++)
		{
			if(s[j]!=s[j+1])
			{
				f=0;
			}
		}
		if(f=1)
		{
			d/=s[1];
			if(d>s[1])
				m=n-1-d;
		}
		cout<<m<<endl;
	}
	return 0;
}
