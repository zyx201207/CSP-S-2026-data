#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010],ans,cc,lans;
void dfs(int x,int y,int step)
{
	if(x>y) return;
	if(x==y)
	{
		if(step<ans) cc=1;
		else if(step==ans) cc++;
		ans=min(ans,step);
		return;
	}
	for(int i=x;i<=n;i++)
	{
		if(abs(a[x]-a[i])>d) break;
		dfs(i,y,step+1);
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				lans=INT_MAX;
				cc=0;
				dfs(i,j,0);
				if(cc==2) ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

