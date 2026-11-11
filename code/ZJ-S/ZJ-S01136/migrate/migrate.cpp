#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,he,ans,Min,a[2000005];
void dfs(int st,int en,int step)
{
	if(st==en)
	{
		if(step<Min)
		{
			Min=step;
			ans=1;
		}
		else if(step==Min) ans++;
		return;
	}
	int s=0;
	for(int i=st+1;i<=en;i++)
	{
		s=a[i]-a[st];
		if(s<=d) dfs(i,en,step+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		he=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				Min=2e9;
				ans=0;
				dfs(i,j,0);
				if(ans==2) he++;
			}
		}
		cout<<he<<endl;
	}
}
