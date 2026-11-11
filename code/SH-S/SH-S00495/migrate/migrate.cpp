#include <bits/stdc++.h>
using namespace std;

int c,t,x[2000005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		bool flag=1;
		int ans=0;
		for(int i = 1;i<=n;i++)
		{
			cin>>x[i];
			if(i!=1&&x[i]-x[i-1]>d)flag=0;
			if((x[i]-x[i-1])*2<=d)
			{
				ans++;
			}
		}
		if(flag==0)cout <<0<<endl;
		else
		{
			cout <<ans-3<<endl;
		}
	}
	return 0;
}

