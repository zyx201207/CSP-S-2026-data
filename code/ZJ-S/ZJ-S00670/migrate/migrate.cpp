#include<bits/stdc++.h>
using namespace std;
int f[1005][1005],cnt[1005][1005],x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		memset(f,0x3f,sizeof f);
		memset(cnt,0,sizeof cnt);
		bool flag=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(x[i-1]!=x[i]-1&&i!=1)
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			cout<<n+1-2*d<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)	
			{
				if(x[i]-x[j]<=d)
				{
					f[i][j]=1;
					f[j][i]=1;
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)	
			{
				for(int j=1;j<=n;j++)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)	
			{
				for(int j=1;j<=n;j++)
				{
					if(f[i][k]+f[k][j]==f[i][j])
					{
						cnt[i][j]++;
					}
				}
			}
		}
		int cntn=0;
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)	
			{
				for(int j=1;j<=i;j++)
				{
					if(cnt[i][j]==2)
					{
						cntn++;
					}
				}
			}
		}
		cout<<cntn<<endl;
	}
	return 0;
}
