#include<bits/stdc++.h>
using namespace std; 
long long n,d,a[2100000],sum,c,t,b[2100000],f[2100000];
void dfs(long long x,long long y,long long k,long long ans)
{
	if(x==y) 
	{ 
		if(k==ans) sum++;
		return ;
	}
	if(k>ans) return ;
	for(long long i=x+1;i<=y;i++) 
	{
		if(a[x]-a[i]<=d) dfs(i,y,k+1,ans);
	} 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(f,0,sizeof(f));
		long long ans1=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>a[i];
		for(long long i=2;i<=n;i++) 
		{
			b[i]=a[i]-a[i-1];
			if(b[i]>d) f[i]=1;
		}
		for(long long i=1;i<n;i++)
		{
			for(long long j=i+1;j<=n;j++) 
			{
				if(f[i]==0&&f[j]==0)
				{
					sum=0;
					long long q=j-i,w=0;
					if(q%d==0) w=q/d;
					 else w=q/d+1;
					dfs(i,j,0,w);
					if(sum==2) ans1++;
				}
			}
		}
		cout<<ans1<<endl;
	} 
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6 
*/
