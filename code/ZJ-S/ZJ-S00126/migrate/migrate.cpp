#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
long long dis[2000005];
long long cnt[2000005];
long long n,d;
void bfs(long long s)
{
	for(long long i=1;i<=n;i++) dis[i]=1e9,cnt[i]=0;
	queue<long long> q;
	q.push(s);
	dis[s]=0;
	cnt[s]=1;
	while(!q.empty())
	{
		long long t=q.front();
		q.pop();
		long long p=upper_bound(x+1,x+1+n,x[t]+d)-x;
		for(long long i=t+1;i<p;i++)
		{
			if(dis[i]>dis[t]+1)
			{
				dis[i]=dis[t]+1;
				cnt[i]=cnt[t];
				q.push(i);
			}
			else if(dis[i]==dis[t]+1) cnt[i]+=cnt[t];
		}
	}
}
void init()
{
	for(long long i=1;i<=n+1;i++) x[i]=0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--)
	{
		init();
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
		  cin>>x[i];
		x[n+1]=x[n]+d-1;
		long long ans=0;
		for(long long i=1;i<=n;i++)
		{
			bfs(i);
			for(long long j=i+1;j<=n;j++)
			  if(cnt[j]==2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
