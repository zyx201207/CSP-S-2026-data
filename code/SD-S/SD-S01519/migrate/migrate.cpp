#include<bits/stdc++.h>
using namespace std;
long long n,d,c,t,a[2000005],b[10][101],f[10]; 
void dfs(long long x,long long s)
{
	int o=0;
	for(int i=x;i<=n;i++)
	{
		if(abs(a[i]-a[s-1])<=d||s==1)
		{
			f[s]=i;
			o=1;
			dfs(i+1,s+1);
		}
	}
	if(o==0)
	{
		for(int i=1;i<s;i++)
		{
	
			for(int j=i;j>1;j--)
			{
				b[f[i]][j-1]++;
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=10;j++)
				b[i][j]=0;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		
			dfs(1,1);

			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=10;j++)
				{
				
					if(b[i][j]==2)
					{
						ans++;
						break;
					}
						
				}
			}
			printf("%d\n",ans);
		
	}
	
	return 0;
} 
//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
