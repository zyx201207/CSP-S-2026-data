#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[3000005],dis[5005][5005],g[5005][5005],ans,k,f;
void dfs(long long x,long long y,long long s)
{
	if(x==y)
	{
		if(s<k)
		{
			k=s;
			f=1;
        }
		else if(k==s) f++;
		return ;
	}
	for(int i=x+1;i<=n;i++)
	if(a[i]-a[x]<=d) dfs(i,y,s+1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(long long i=1;i<=n;i++)
		for(long long j=i+1;j<=n;j++)
		{
			f=0;
			k=1e18;
			dfs(i,j,0);
			if(f==2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}