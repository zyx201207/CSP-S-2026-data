#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<lint,lint> PI;
const lint M1=2e6+1000,M2=5e5+1000,M3=1e5+1000;
lint pre[M1],pkp;
struct node{
	lint to,next,len;
}e[M1];
void add(lint u,lint v,lint l){e[++pkp]={v,pre[u],l},pre[u]=pkp;}
lint c,n,m,dd,Q,w[M2],a[M2],t[M2],k[M2],x,y;
priority_queue<PI,vector<PI>,greater<PI> > q;
lint d[M3][500],d1[M2][2];
bool f[M3][500],f1[M2][2];
void dijstra(lint s)
{
	q.push({0,s});
	d[s][s]=0;
	while(!q.empty())
	{
		PI tp=q.top();
		lint pp=tp.second,dis=tp.first;
		q.pop();
		if(f[pp][s]) continue;
		f[pp][s]=1;
		for(lint i=pre[pp];i;i=e[i].next)
		{
			lint too=e[i].to;
			if(d[too][s]>dis+e[i].len)
			{
				d[too][s]=dis+e[i].len;
				q.push({d[too][s],too});
			}
		}
	}
}
void dijstra1(lint s)
{
	q.push({0,s});
	d1[s][s]=0;
	while(!q.empty())
	{
		PI tp=q.top();
		lint pp=tp.second,dis=tp.first;
		q.pop();
		if(f1[pp][s]) continue;
		f1[pp][s]=1;
		for(lint i=pre[pp];i;i=e[i].next)
		{
			lint too=e[i].to;
			if(d1[too][s]>dis+e[i].len)
			{
				d1[too][s]=dis+e[i].len;
				q.push({d1[too][s],too});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&dd,&Q);
	for(lint i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(lint i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(lint j=1;j<=k[i];j++)
		{
			scanf("%lld%lld",&a[j],&t[j]);
			add(m+i,a[j],t[j]);
			add(a[j],m+i,t[j]);
		}
	}
	if(n<=2)
	{
		memset(d1,0x3f,sizeof(d1));
		for(lint i=1;i<=n;i++) dijstra1(i);
		while(Q--)
		{
			scanf("%lld%lld",&x,&y);
			lint ans=1e18;
			for(lint i=pre[x];i;i=e[i].next)
			{
				lint too=e[i].to;
				ans=min(ans,w[x]+w[y]+d1[x][too-m]+d1[y][too-m]);
			}
			printf("%lld\n",ans);
		}
	}
	else if(n<=500&&m<=2e4)
	{
		memset(d,0x3f,sizeof(d));
		for(lint i=1;i<=n;i++) dijstra(i);
		while(Q--)
		{
			scanf("%lld%lld",&x,&y);
			lint ans=1e18;
			for(lint i=pre[x];i;i=e[i].next)
			{
				lint too=e[i].to;
				ans=min(ans,w[x]+w[y]+d[x][too-m]+d[y][too-m]);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
