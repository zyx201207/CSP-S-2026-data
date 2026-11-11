#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const lint M1=2e6+1000,M2=5e3+100;
lint C,T;
lint n,d;
lint x[M1];
lint pre[M1],k;
struct node{
	lint to,next;
}a[M1];
struct stu{
	lint x,v;
};
void add(lint u,lint v){a[++k]={v,pre[u]},pre[u]=k;}
lint dp[M2][M2],s[M2][M2];
queue<stu> q;
void bfs(lint p)
{
	q.push({p,0});
	for(lint i=1;i<=n;i++) dp[i][p]=1e15;
	for(lint i=1;i<=n;i++) s[i][p]=0;
	dp[p][p]=0;
	s[p][p]=0;
	while(!q.empty())
	{
		stu op=q.front();
		lint tp=op.x,pp=op.v;
		q.pop();
		for(lint i=pre[tp];i;i=a[i].next)
		{
			lint too=a[i].to;
			if(pp+1<dp[too][p])
			{
				dp[too][p]=pp+1;
				s[too][p]=1;
				q.push({too,dp[too][p]});
			}
			else if(pp+1==dp[too][p]) s[too][p]++;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--)
	{
		lint ans=0;
		scanf("%lld%lld",&n,&d);
		for(lint i=1;i<=n;i++) scanf("%lld",&x[i]);
		k=0;
		for(lint i=1;i<=n;i++) pre[i]=0;
		for(lint i=1;i<=n;i++)
		{
			for(lint j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d) add(i,j);
				else break;
			}
		}
		for(lint i=1;i<n;i++) bfs(i);
		for(lint j=1;j<=n;j++)
		{
			for(lint i=j+1;i<=n;i++)
			{
				if(s[i][j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
