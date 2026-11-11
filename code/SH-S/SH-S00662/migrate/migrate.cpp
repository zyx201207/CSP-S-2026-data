#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000010];
int cnt[2000010];
int ans[2000010];
int n,d;
void dfs(int step,int step1,int p)
{
	if(step1>a[n])
	{
		return;
	}
	if(cnt[step1]==0)
	{
		ans[step1]=step;
	}
	if(step<ans[step1])
	{
		ans[step1]=step;
		cnt[step1]=0;
	}
	if(step==ans[step1])
	{
		cnt[step1]++;
	}
	for(int i=step1+1;i<=n;i++)
	{
		if(a[i]-a[step1]<=d)
		{
			dfs(step+1,a[i],a[i]-step1);
		}
		else
		{
			return;
		}
	}
	if(step1>=n)
	{
		return;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		int p=a[1];
		for(int j=1;j<=n;j++)
		{
			a[j]-=p;
			a[j]++;
		}
		if(n<=35)
		{
			int sum=0;
			for(int l=1;l<=n;l++)
			{
				dfs(1,a[l],0);
				for(int j=1;j<=n;j++)
				{
					if(cnt[j]==2)
					{
						sum++;
					}
				}
				memset(cnt,0,sizeof cnt);
				memset(ans,0,sizeof ans);
			}
			cout<<sum<<endl;
		}
		else
		{
			int q=a[2]-a[1];
			int pq=p/q;
			cout<<max(1ll*0,n-2*pq+1)<<endl;
		}
	}
}
