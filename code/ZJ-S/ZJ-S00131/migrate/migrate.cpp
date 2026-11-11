#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000010];
long long sl=0;
long long mins=0xfffffffffffffff;
void dfs(int l,int r,int sum)
{
	if(l==r)
	{
		if(mins>sum)
		{
			mins=sum;
			sl=1;
		}
		else if(mins==sum)
		{
			sl++;
		}
		return;
	}
	for(int i=l+1;i<=r;i++)
	{
		if(a[i]-a[l]>d) return;
		else
		{
			dfs(i,r,sum+1);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		cin>>n>>d;
		bool ccff=1;
		long long ans=0;
		long long minj=0xfffffffffffffff;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i!=1) minj=min(minj,a[i]-a[i-1]);
		}
		if(minj>=d)
		{
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				sl=0;
				mins=0xfffffffffffffff;
				dfs(i,j,0);
				if(sl==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

