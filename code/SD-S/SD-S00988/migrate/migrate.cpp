#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000006];
long long f(long long x,long long y)
{	long long t=x,s=1;
	if(x==y)
		return 0;
	for(int i=x;i<=y;i++)
	{	if(a[i]-a[t]>d)
		{	t=i-1;
			s++;
		}
	}
	return s;
}
long long dfs(long long x,long long y,long long fl)
{	if(x==y)
		return 1;
	long long ans=0;
	for(int i=x+1;i<=y;i++)
	{	if(a[i]-a[x]>d)
			break;
		if(f(i,y)==fl-1)
			ans+=dfs(i,y,fl-1);
	}
	return ans;
}
int main()
{	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{	cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++)
				if(dfs(i,j,f(i,j))==2)
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}
