#include<bits/stdc++.h>
using namespace std;
int c,t;
const int N=2e6+5;
int a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		int ca=0;
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i!=1)
			{
				ca=a[i]-a[i-1];
				if(ca>d)
				{
					flag=0;
				}
			}
		}
		if(flag==0)
		{
			cout<<0<<endl;
			continue;
		}
		else
		{
			cout<<n/2;
		}
	}
	
	return 0;
}
