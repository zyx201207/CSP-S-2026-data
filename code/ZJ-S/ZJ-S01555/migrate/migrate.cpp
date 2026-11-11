#include<bits/stdc++.h>
using namespace std;
long long w,e;
long long t;
long long n,dis;
long long x[2000005];
long long c[2000005];
long long d[2000005];
void dfs(long long now,long long de)
{
	if(now>n)	return;
	if(de==d[now])	c[now]++;
	if(de<d[now])	d[now]=de,c[now]=0;
	if(de>d[now])	return ;
	long long nxt=now+1;
//	cout<<(x[nxt]-x[now]<=dis)<<endl;
	while(x[nxt]-x[now]<=dis)
	{
		dfs(nxt,de+(x[nxt]-x[now]));
		nxt++;
	}
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>w>>t;
	for(long long T=1;T<=t;T++)
	{
		memset(x,0,sizeof x);
		memset(c,0,sizeof c);
		memset(d,0x3f,sizeof d);
		long long ans=0;
		cin>>n>>dis;
		for(long long i=1;i<=n;i++)	cin>>x[i];
		for(long long i=1;i<=n;i++)
		{
			dfs(i,0);
			for(long long j=i;j<=n;j++)
			{
				if(c[j]==2)	ans++;
//				cout<<d[j]<<" "<<c[j]<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//ÂäÄ»£¿ÀáÄ¿£¿ 
