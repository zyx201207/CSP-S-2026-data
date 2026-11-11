#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000010],vis[5010],b[5010],f[5010];
void bfs(int s)
{
	queue<pair<int,int>>q;
	vis[s]=0;
	b[s]=1;
	q.push({s,0});
	while(!q.empty())
	{
		pair<int,int> t=q.front();
		q.pop();
		int x=t.first;
		int st=t.second;
		int id=upper_bound(a+1,a+n+1,a[x]+d)-a-1;
		for(int i=x+1;i<=id;i++)
		{
			if(vis[i]==st+1)
			{
				b[i]++;
				q.push({i,st+1});
			}
			else if(vis[i]==0)
			{
				vis[i]=st+1;
				b[i]=1;
				q.push({i,st+1});
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.ont","w",stdout);
	scanf("%d%d",&c,&t);
	if(c<=6)
	{
		while(t--)
		{
			long long sum=0;
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			for(int i=1;i<=n;i++)
			{
				memset(vis,0,sizeof(vis));
				memset(b,0,sizeof(b));
				bfs(i);
//				for(int j=1;j<=n;j++) cout<<b[j]<<" ";
//				cout<<endl;
				for(int j=1;j<=n;j++) if(b[j]==2) sum++;
			} 
			printf("%lld\n",sum);
		}
	}
	else
	{
		while(t--)
		{
			long long sum=0;
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
			for(int i=1;i<=n;i++)
			{
				int id=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
				if(id==n+1) id--;
				if(id-i<=1) continue;
				id--;
				int x=upper_bound(a+1,a+n+1,a[id-1]+d)-a-1;
				int y=upper_bound(a+1,a+n+1,a[id]+d)-a-1;
				sum+=y-x;
			}
			printf("%lld\n",sum);
		} 
	}
	return 0;
} 
