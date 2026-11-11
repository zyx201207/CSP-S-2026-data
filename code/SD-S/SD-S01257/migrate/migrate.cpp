#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
int a[10010];
int f[10010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int TT,T,n,m,x,ans=0;
	cin>>TT>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=0;i<=n;i++)
		{
			f[i]=0;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]-a[1]%m==0||a[i]-a[1]<=m)
			{
				f[i]=1;
			}
		}
		int k=1;
		for(int i=1;i<=n;i++)
		{
			k=1;
			if(f[i]==0)
				while(a[i]-a[i-k]<=m)
				{
					f[i]+=f[i-k];
					k++;
				}
		}
		f[1]=0; 
		for(int i=1;i<=n;i++)
		{
			if(f[i]==2)
			{
				ans++;
			}
		}
		for(int i=2;i<=n;i++)
		{
			if(f[i]!=1)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(f[j]-f[i]==2)
					{
						ans++;
					}
				}
			}
			
		}
		cout<<ans<<endl;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

