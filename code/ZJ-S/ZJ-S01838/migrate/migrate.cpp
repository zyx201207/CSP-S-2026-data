#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long tt;
long long cnt;
long long a[10000005];
long long x[2005][2005];
long long f[2005][2005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	while(m--)
	{
		cnt=0;
		memset(x,0,sizeof(x));
		memset(f,-1,sizeof(f));
		cin >> n >> tt;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++)
		{
			long long j=i+1;
			while(a[j]-a[i]<=tt&&j<=n) 
			{
			    x[i][j]=1;
				x[j][i]=1;
				j++;
			}
			j=i-1;
			while(a[i]-a[j]<=tt&&j>=1) 
			{
			    x[i][j]=1;
				x[j][i]=1;
				j--;
			}
		}
		for(int l=1;l<n;l++)
		{
			for(int i=1;i<=n-l;i++)
			{
				int j=i+l;
				for(int k=i+1;k<j;k++)
				{
					if(x[i][k]==-1||x[k][j]==-1) continue;
					if(x[i][j]!=-1) x[i][j]=min(x[i][j],x[i][k]+x[k][j]);
					if(x[i][j]==-1 )x[i][j]=x[i][k]+x[k][j];
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=i+1;k<j;k++)
					if(x[i][k]+x[k][j]==x[i][j])
						f[i][j]=f[i][k]*f[k][j];
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) 
		if(f[i][j]==2) cnt++;
		cout << cnt <<"\n";
	}
	return 0;
}