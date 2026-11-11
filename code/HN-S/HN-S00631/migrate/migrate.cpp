#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int n,d;
long long minn[2000005]={INT_MAX};
int b[200005];
void dfs(int cal,int cnt)
{
	if(cal>n)
	{
		return ;
	}
	if(minn[cal]>cnt)
	{
		minn[cal]=cnt;
		b[cal]=1;
	}
	else if(minn[cal]==cnt)
	{
		b[cal]++;
	}
	for(int i=cal+1;i<=n;++i)
	{
		if(a[i]-a[cal]>d)
		{
			break;
		}
		dfs(i,cnt+1);
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		if(c<=2)
		{
			int ans=0;
			for(int i=1;i<=n;++i)
			{
				for(int i=1;i<=n;++i)
				{
					minn[i]=INT_MAX;
					b[i]=0;
				}
				dfs(i,0);
				for(int j=i+1;j<=n;++j)
				{
					if(b[j]==2)
					{
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}

