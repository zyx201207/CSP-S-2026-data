#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],m,b[100],c[200006],t,ans;
void dfs(long long x,long long cnt,long long la)
{
	if(x==m+1)
	{
		ans=max(ans,cnt);
	}
	for(int i=la+1;i<=t;i++)
	{
	
		dfs(x+1,cnt&c[i],i);
		
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=35;j++)
		{
			if((a[i]>>j)&1==1)
			b[j]++;
		}
	}
	for(int i=34;i>=1;i--)
	{
		if(b[i]>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if((a[j]>>i)&1==1)
				{
					t++;
					c[t]=a[j];
				}
			}
			long long x=pow(2,30)-1;
			dfs(1,x,0);
			cout<<ans;
			return 0;
		}
	}
	cout<<0;
	
	
	return 0;
}
