#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000015],ans;
void dfs(int dep,int now,int y,int maxn)
{
	if(dep==maxn)
	{
		if(now==y)
		{
			ans++;
		}
		return;
	}
	for(int i=now+1;i<=y;i++)
	{
		if(x[i]-x[now]>d) return;
		dfs(dep+1,i,y,maxn);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		long long ans2=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++)
		{
			cin >> x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				int now=i,sum=0;
				ans=0;
				for(int k=i;k<j;k++)
				{
					if(x[k+1]-x[now]>d&&x[k]-x[now]<=d)
					{
						now=k;
						sum++;
					}
				}
				if(now!=j&&x[j]-x[now]<=d) sum++;
				if(x[j]-x[now]>d) continue;
				dfs(0,i,j,sum);
				if(ans==2) ans2++;
			}
		}
		cout << ans2 << endl;
	}
	return 0;
} 
