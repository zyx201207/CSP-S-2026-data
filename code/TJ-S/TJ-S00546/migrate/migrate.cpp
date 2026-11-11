#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[2200000];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		if(c==11||c==12)
		{
			cin>>n>>d;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
			}
			if(n==1||d>=(a[n]-a[1]))
			{
				cout<<0<<'\n';
			}
			else
			{
				int tmp=a[2]-a[1];
				d=d/tmp;
				if(d<=1)
				{
					cout<<0<<'\n';
				}
				else
				{
					d=d*2-1;
					cout<<n-d<<'\n';	
				}
			}
		}
		else
		{
			cin>>n>>d;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
			}
			if(n==1||d>=(a[n]-a[1]))
			{
				cout<<0<<'\n';
			}
			else
			{
				int tmp=a[2]-a[1];
				d=d/tmp;
				if(d<=1)
				{
					cout<<0<<'\n';
				}
				else
				{
					d=d*2-1;
					cout<<n-d<<'\n';	
				}
			}
		}
	}
	return 0;
} 
