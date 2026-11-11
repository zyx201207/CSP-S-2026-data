#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[5001];
long long f[5001][5001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		memset(f,0,sizeof(f));
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		long long k=abs(x[1]);
		for(int i=1;i<=n;i++)x[i]+=k;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(j-i==2*d-1)ans++;	
			}
		}
		printf("%d",ans);
	}
	return 0;
}