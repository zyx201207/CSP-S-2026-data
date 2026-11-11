#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,m,a[1010],f[1010][1010],ct[1010][1010],cnt=0;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=INT_MAX;
				ct[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(a[j]-a[i])<=m)
				{
					f[i][j]=1;
					ct[i][j]=1;
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(f[i][k]+f[k][j]<f[i][j])
					{
						f[i][j]=f[i][k]+f[k][j];
						ct[i][j]=ct[i][k]*ct[k][j];
					}
					else if(f[i][k]+f[k][j]==f[i][j]) 
					{
						ct[i][j]+=ct[i][k]*ct[k][j];
					}
				}
			}
		}
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
//				cout<<ct[i][j]<<" "; 
				if(ct[i][j]==2)
				{
					cnt++;
				}
			}
//			cout<<"\n";
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
//这个应该有24pts吧
//^v^我是不是有 S1=了 
