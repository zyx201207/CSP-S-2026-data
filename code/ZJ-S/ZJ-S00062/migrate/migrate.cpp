#include<bits/stdc++.h>
using namespace std;
void solve();
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		solve();
	}
	return 0;
}
void solve()
{
	long long d,isl[2000009];
	cout<<sizeof(isl)/8/1024;
	int n;
	scanf("%d %d",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&isl[i]);
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(isl[i]+d>=isl[j]) continue;
			int count =0;
			for(int k=i+1;k<j;k++)
			{
				if(isl[k] - isl[i] <=d && isl[j]-isl[k] <=d)
				{
					count++;
				}
				if(count >=2)
				{
					ans++;
					break;	
				}
			}
		}
	}
	printf("%d\n",ans);
}
