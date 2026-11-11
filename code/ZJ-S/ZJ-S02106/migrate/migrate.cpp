#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,a[N],n,d,b[N],minn=2000000000000000005,ans=0,k;
bool flag;
void dfs(int i,int j,int deep)
{
	if(i==j)
	{
		if(deep==minn)
		{
			ans++;
		}
		else if(minn>deep)
		{
			minn=deep;
			ans=1;
		}
		return;
	}
	if(deep>minn)
	{
		return;
	}
	for(int x=j;x>=i+1;x--)
	{
		if(a[x]-a[i]<=d)
		{
			dfs(x,j,deep+1);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				minn=2000000000000000005;
				ans=0;
				dfs(i,j,0);
				if(ans==2)
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
