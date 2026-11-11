#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int x[N],flag=1;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int p=x[2]-x[1];
		for(int i=3;i<=n;i++)
		{
			if(x[i]-x[i-1]!=p)
			{
				flag=0;
			}
		}
		if(flag==1)
		{
			int ch=x[2]-x[1];
			if(d>=ch*3)
			{
				cout<<0<<'\n';
			}
			else if(d<=ch)
			{
				cout<<0<<'\n';
			}
			else if(d>ch&&d<ch*3)
			{
				if(n==4)
				{
					ans=1;
				}
				else
				{
					ans=n-3;
				}
				cout<<ans<<'\n';
			}
		}
	}	
	return 0;
}
