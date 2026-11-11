#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[20],ans;

void dfs(int now)
{
	if(want==y) return;
	for(int j=1;j<=want-now;j++)
	{
		if(a[x+j]-a[x]>d) ci[x+j][]++;
		a[x+1][j]=1;
	}
	dfs(want);
}

bool pan(int x,int y)
{
	int ci[20][20];//到第n个岛用m次的方案数； 
	for(int i=1;i<=n-1;i++)
	{
		dfs(x);
		if(ci[y][j]=2) break;
	}
	return 0;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++) cin>>a[j];
		for(int j=1;j<n;j++)
		for(int k=j+1;k<n;k++)
		{
			if(pan(j,k))ans++;
		}
		printf("%d\n",ans);
	}

	return 0;
}
