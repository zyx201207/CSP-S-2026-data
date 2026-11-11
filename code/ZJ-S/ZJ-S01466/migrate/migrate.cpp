#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,x[2000005],d[5005][5005],n,ans;
ll dfs(int a,int b)
{
	if(d[a][b]!=n+1)
		return d[a][b];
	if(x[b]<=x[a]+m)
	{
		for(int i=a+1;i<b;i++)
		{
			for(int j=i+1;j<b-1;j++)
				d[i][j]=1;
			d[a][i]=1;
			d[i][b]=1;
		}
		return d[a][b]=1;	
	}
	int i=a+1;
	while(x[i]<=x[a]+m&&i<=b)
	{
		d[a][i]=1;
		d[a][b]=min(d[a][b],dfs(i,b)+1);
		i++;
	}
	return d[a][b];
}
int find(int a,int b,int p,int s)
{
	if(x[p]+m>=x[b])
		if(s+1==d[a][b])
			return 1;
		else
			return 0;
	int s1=0,i=p+1;
	while(x[i]<=x[p]+m&&i<=b)
	{
		s1+=find(a,b,i,s+1);
		i++;
	}
	return s1;
}
void solve()
{
	ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&x[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			d[i][j]=n+1;
	for(int i=1;i<=n;i++)
		for(int j=n;j>=i+1;j--)
			dfs(i,j);			
	/*for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
			cout<<d[i][j]<<' ';
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(d[i][j]!=n+1&&d[i][j]>1)
			{
				if(find(i,j,i,0)==2)
					ans++;
			}
	printf("%d\n",ans);
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	scanf("%d%d",&C,&T);
	while(T--)
		solve();
	return 0;
}
