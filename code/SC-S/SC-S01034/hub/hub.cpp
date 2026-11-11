#include<bits/stdc++.h>
using namespace std;
char input[1<<20],*pf,*pe;
#define gc() (pf==pe&&(pe=(pf=input)+fread(input,1,1<<20,stdin),pf==pe)?EOF:*pf++)
int rdi()
{
	int n=0,c=gc();
	for(;!isdigit(c);c=gc());
	for(;isdigit(c);n=n*10+c-48,c=gc());
	return n;
}
const int N=1e6+35;
const int inf=1e9+35;
int iu[N],iv[N];
int g[N<<1];
int gb[N];
int dep[N];
bool use[N];
void prepare(int p)
{
	dep[p]=1;
	use[p]=1;
	for(int i=gb[p];i<gb[p+1];i++)
	{
		int u=g[i];
		if(use[u])
		{
			continue;
		}
		prepare(u);
		dep[p]=max(dep[p],dep[u]+1);
	}
	use[p]=0;
}
void reroot(int p,int up,int &q,int &d)
{
	int md=up,sd=0;
	for(int i=gb[p];i<gb[p+1];i++)
	{
		int u=g[i];
		if(use[u])
		{
			continue;
		}
		if(md<dep[u])
		{
			sd=md;
			md=dep[u];
		}
		else if(sd<dep[u])
		{
			sd=dep[u];
		}
	}
	if(md<d)
	{
		q=p;
		d=md+1;
	}
	use[p]=1;
	for(int i=gb[p];i<gb[p+1];i++)
	{
		int u=g[i];
		if(use[u])
		{
			continue;
		}
		if(dep[u]==md)
		{
			reroot(u,sd+1,q,d);
		}
		else
		{
			reroot(u,md+1,q,d);
		}
	}
	use[p]=0;
}
int s[N];
int idn=0;
int q[N];
int h=0,t=0;
bool tag[N];
void getdep(int n)
{
	h=0,t=0;
	for(int i=1;i<=n;i++)
	{
		use[i]=0;
		dep[i]=0;
	}
	for(int i=1;i<=idn;i++)
	{
		use[s[i]]=1;
		q[t++]=s[i];
	}
	while(h<t)
	{
		int p=q[h++];
		for(int i=gb[p];i<gb[p+1];i++)
		{
			int u=g[i];
			if(use[u])
			{
				continue;
			}
			use[u]=1;
			q[t++]=u;
		}
	}
	for(int i=t-1;i>=0;i--)
	{
		int p=q[i];
		use[p]=0;
		for(int j=gb[p];j<gb[p+1];j++)
		{
			int u=g[j];
			dep[p]=max(dep[p],dep[u]+1);
		}
	}
}
void solve()
{
	int n=rdi(),k=rdi();
	for(int i=1;i<=n+1;i++)
	{
		gb[i]=0;
		use[i]=0;
		tag[i]=0;
		dep[i]=0;
		iu[i]=0;
		iv[i]=0;
		g[i]=g[n+1]=0;
		q[i]=0;
		s[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		gb[iu[i]=rdi()]++;
		gb[iv[i]=rdi()]++;
	}
	for(int i=1;i<=n;i++)
	{
		gb[i+1]+=gb[i];
	}
	for(int i=1;i<n;i++)
	{
		g[--gb[iu[i]]]=iv[i];
		g[--gb[iv[i]]]=iu[i];
	}
	int mp=0,mq=0,md=inf;
	for(int p=1;p<=n;p++)
	{
		prepare(p);
		int q=0,d=0;
		for(int i=gb[p];i<gb[p+1];i++)
		{
			int u=g[i];
			if(d<dep[u])
			{
				q=u;
				d=dep[u];
			}
		}
		int sd=0;
		for(int i=gb[p];i<gb[p+1];i++)
		{
			int u=g[i];
			if(u==q)
			{
				continue;
			}
			sd=max(sd,dep[u]);
		}
		use[p]=1;
		reroot(q,0,q,d);
		use[p]=0;
		d=max(d,sd);
		if(d<md)
		{
			mp=p;
			mq=q;
			md=d;
		}
	}
	idn=0;
	s[++idn]=mp;
	s[++idn]=mq;
	tag[mp]=1;
	tag[mq]=1;
	while(idn<k)
	{
		getdep(n);
		int v=0;
		for(int i=1;i<=idn;i++)
		{
			int p=s[i];
			for(int j=gb[p];j<gb[p+1];j++)
			{
				int u=g[j];
				if(tag[u])
				{
					continue;
				}
				if(dep[v]<dep[u])
				{
					v=u;
				}
			}
		}
		s[++idn]=v;
		tag[v]=1;
	}
	getdep(n);
	int v=0;
	for(int i=1;i<=idn;i++)
	{
		int p=s[i];
		for(int j=gb[p];j<gb[p+1];j++)
		{
			int u=g[j];
			if(tag[u])
			{
				continue;
			}
			if(dep[v]<dep[u])
			{
				v=u;
			}
		}
	}
	cout<<dep[v]<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	int c=rdi(),t=rdi();
	int cc=c,cd=c;
	swap(cc,cd);
	for(int i=1;i<=t;i++)
	{
		solve();
	}
	return 0;
}
//lpy