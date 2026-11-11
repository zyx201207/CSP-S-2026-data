#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=2e6;
int idx,bh,T,a,b,h[N],e[N],ne[N];
ll n,k,ans,dist[N],d[N];
bool f[N],st[N];
void add(int u,int v)
{
	d[u]++;
	e[idx]=v;
	ne[idx]=h[u];
	h[u]=idx++;
}
void bfs(int u)
{
	queue<int>q;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=h[u];~i;i=ne[i])
		{
			int j=e[i];
			if(!st[j])
			{
				st[j]=1;
				q.push(j);
			}
			dist[u]=min(dist[u],dist[j]+1);
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	bh=read();T=read();
	while(T--)
	{
		bool fll=0;
		ans=idx=a=b=0;
		n=read();k=read();
		for(int i=1;i<=n;i++)
		{
			h[i]=-1;
			f[i]=st[i]=d[i]=0;
			dist[i]=N;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			u=read();v=read();
			add(u,v);
			add(v,u);
		}
		for(int i=1;i<=n;i++)
			if(d[i]>d[a])a=i;
		for(int i=1;i<=n;i++)
		{
			bool fl=0;
			if(i==a)continue;
			for(int j=h[i];~j;j=ne[j])
				if(e[j]==a)
				{
					fl=1;
					break;
				}
			if(fl)continue;
			if(d[i]>d[b])b=i;
		}
		if(!b)
		{
			puts("1");
			continue;
		}
		f[a]=f[b]=1;
		for(int i=3;i<=k;i++)
		{
			ll maxi=0;
			for(int j=h[a];~j;j=ne[j])
			{
				int u=e[j];
				if(!f[u]&&d[u]>d[maxi])maxi=u;
			}
			ll mayi=0;
			for(int j=h[b];~j;j=ne[j])
			{
				int u=e[j];
				if(u==maxi)continue;
				bool fl=0;
				for(int k=h[u];~k;k=ne[k])
					if(e[k]==maxi)
					{
						fl=1;
						break;
					}
				if(fl)continue;
				if(!f[u]&&d[u]>d[mayi])mayi=u;
			}
			if(!mayi)
			{
				fll=1;
				break;
			}
			if(d[maxi]>=d[mayi])
			{
				a=maxi;
				f[a]=1;
			}
			else
			{
				b=mayi;
				f[b]=1;
			}
		}
		if(fll)
		{
			puts("1");
			continue;
		}
		for(int i=1;i<=n;i++)
			if(f[i])dist[i]=0;
		st[1]=1;
		bfs(1);
		for(int i=1;i<=n;i++)ans=max(ans,dist[i]);
		write(ans);
		puts("");
	}
	return 0;
}
