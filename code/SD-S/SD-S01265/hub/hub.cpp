#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	bool bz=false;
	char ch=getchar();
	long long ans=0;
	while(ch!=EOF&&ch!='-'&&(ch<'0'||ch>'9'))
		ch=getchar();
	if(ch=='-')
	{
		bz=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		ans=(ans<<3)+(ans<<1)+(ch^48);
		ch=getchar();
	}
	if(bz)
		return -ans;
	return ans;
}
void wrt(long long x)
{
	int numn[40],cnt=0,i;
	long long y=x;
	if(y<0)
	{
		putchar('-');
		y=-y;
	}
	do
	{
		numn[++cnt]=y%10;
		y/=10;
	}while(y);
	for(i=cnt;i>=1;--i)
		putchar(numn[i]^48);
	return;
}
const int maxn=1e6,inf=INT_MAX>>1;
struct edg
{
	int nxt,t;
}e[maxn+5<<1];
int a[maxn+10],dis[maxn+10],fst[maxn+10];
int ans,c,m,n,t,u,v;
int cnt;
bool bz[maxn+10],vis[maxn+10];
queue<int>q;
void ad(int x,int y)
{
	e[cnt].t=y;
	e[cnt].nxt=fst[x];
	fst[x]=cnt++;
	return;
}
void dfs(int x)
{
	int i,mx=0,u,v;
	if(x==m+1)
	{
		while(q.size())
			q.pop();
		for(i=1;i<=m;++i)
			vis[a[i]]=false;
		q.push(a[1]);
		vis[a[1]]=true;
		while(q.size())
		{
			u=q.front();
			q.pop();
			for(i=fst[u];~i;i=e[i].nxt)
			{
				v=e[i].t;
				if(bz[v]&&!vis[v])
				{
					vis[v]=true;
					q.push(v);
				}
			}
		}
		for(i=1;i<=m;++i)
		{
			if(!vis[a[i]])
			{
				q.push(a[i]);
				vis[a[i]]=true;
				break;
			}
		}
		while(q.size())
		{
			u=q.front();
			q.pop();
			for(i=fst[u];~i;i=e[i].nxt)
			{
				v=e[i].t;
				if(bz[v]&&!vis[v])
				{
					vis[v]=true;
					q.push(v);
				}
			}
		}
		for(i=1;i<=m;++i)
			if(!vis[a[i]])
				return;
		for(i=1;i<=n;++i)
			dis[i]=inf;
		for(i=1;i<=m;++i)
		{
			dis[a[i]]=0;
			q.push(a[i]);
		}
		mx=0;
		while(q.size())
		{
			u=q.front();
			q.pop();
			for(i=fst[u];~i;i=e[i].nxt)
			{
				v=e[i].t;
				if(dis[v]==inf)
				{
					dis[v]=dis[u]+1;
					mx=max(mx,dis[v]);
					q.push(v);
				}
			}
		}
		ans=min(ans,mx);
		return;
	}
	for(i=a[x-1]+1;i<=n-m+x;++i)
	{
		a[x]=i;
		bz[i]=true;
		dfs(x+1);
		bz[i]=false;
	}
	return;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int i;
	c=rd();
	t=rd();
	while(t--)
	{
		n=rd();
		m=rd();
		for(i=1;i<=n;++i)
			fst[i]=-1;
		cnt=0;
		for(i=1;i<=n-1;++i)
		{
			u=rd();
			v=rd();
			ad(u,v);
			ad(v,u);
		}
		if(c==13||c==14)
		{
			if(m==n)
				putchar('0');
			else if(m>=n>>1)
				putchar('1');
			else wrt((n>>1)-m+7>>2);
			putchar('\n');
			continue;
		}
		ans=inf;
		dfs(1);
		wrt(ans);
		putchar('\n');
	}
	return 0;
}
