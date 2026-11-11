#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int x[maxn];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)
	{
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++){cin>>x[i];}
		if(c==11||c==12)
		{
			int ans=1;
			if(d>=x[1]-x[n])
			{
				for(int i=n;i>=1;i--)
				{
					ans*=i;
				}
				cout<<ans;
			}
			else
			{
				if(d<x[1]-x[2]) cout<<0;
				int w=1;
				for(int i=n;i>=1;i--)
				{
					if(d>x[1]-x[i])
					{
						w=i;
					}
				}
				for(int i=2;i>=1;i--)
				{
					ans+=i;
				}
				cout<<ans;
			}
		}
	}
}
