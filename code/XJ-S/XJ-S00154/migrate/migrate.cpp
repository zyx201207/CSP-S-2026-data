#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],ans[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	bool flag=false;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		if(d%2!=0)
		{
			ans[i]=0;	
			cout<<0<<endl;
		}
		else
		{
			flag=true;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
			for(int k=1;k<=n;k++)
			{
				if(abs(x[j]-x[i])==3&&flag==true)
				{
					ans[i]++;
				}
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		if(ans[i]==0)
		{
			continue;	
		}
		else
		{
			cout<<ans[i]-3<<endl;
		}
	}
	return 0;
}
