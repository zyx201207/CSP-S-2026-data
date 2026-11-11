#include <bits/stdc++.h>
using namespace std;
long long a[2002000],f[2002000],l[2002000],dp[1010][1010],p[20],sum[1010][1010];
void dfs(int g,int x,int m,int y)
{
	if(x==m)
	{
		if(y==dp[g][m])
		{
			sum[g][m]++;
		}
		return;
	}
	for(int i=x+1;i<=f[x];i++)
	{
		dfs(g,i,m,y+1);
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T,n,r,cnt;
	long long d;
	cin>>c>>T;
	if(c<=10)
	{
		for(int z=1;z<=T;z++)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			r=1;
			for(int i=1;i<=n;i++)
			{
				for(;r<n;r++)
				{
					if((a[r+1]-a[i])>d)
					{
						break;
					}
				}
				f[i]=r;
			}
			for(int i=n;i>=1;i--)
			{
				l[f[i]]=i;
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					dp[i][j]=dp[i][l[j]]+1;
				}
			}
			cnt=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					sum[i][j]=0;
					dfs(i,i,j,0);
					if(sum[i][j]==2)
					{
						cnt++;
						cout<<i<<j<<'\n';
					}
				}
			}
			cout<<cnt<<'\n';
		}
	}
	if((c==11)||(c==12))
	{
		for(int z=1;z<=T;z++)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			if(n<=2)
			{
				cout<<0<<'\n';
				continue;
			}
			r=d/(a[2]-a[1]);
			if(r<2)
			{
				cout<<0<<'\n';
				continue;
			}
			cnt=0;
			for(int i=1;i<=n;i++)
			{
				if((i+r+r-1)<=n)
				{
					cnt++;
				}
			}
			cout<<cnt<<'\n';
		}
	}
	return 0;
}
