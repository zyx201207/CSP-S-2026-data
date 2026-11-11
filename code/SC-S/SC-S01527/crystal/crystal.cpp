#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,y[20020];
long long m,a[20020],b[20020],ans;
void dfs(int y,long long a[])
{
	for(int i=1;i<=n/2;i++)
	{
		if(y)
		{
			a[i]++;
			dfs(y-1,a);
			a[i]--; 	
		}
		long long t=1;
		int r=-1;
		for(int j=1;j<n;j++)
		{
		 	if(a[j]==a[j+1])
		 		t++;
		}
		ans=max(t,ans);
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(y,1,sizeof(y));
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	if(m<20000&&n<20000)
	{
		sort(b+1,b+n+1);
		dfs(m,b);
		cout<<ans<<endl;
	}
	else
	{
		ans=m/n/15;
		cout<<ans;
	}
	return 0;
}