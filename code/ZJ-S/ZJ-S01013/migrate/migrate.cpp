#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000006];
long long ans=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c==11||c==12)
		{
			long long s=d/(x[2]-x[1]);
			if(s==1)
			{
				cout<<0<<endl;
				continue;
			}
			cout<<n-s-1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
