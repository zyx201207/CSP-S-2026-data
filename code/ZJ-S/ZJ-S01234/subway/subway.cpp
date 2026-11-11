#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
const int M=1e5+10;

inline int read()
{
	char c=getchar();
	while(!isdigit(c))
	{
		c=getchar();
	}
	long long val=0;
	while(isdigit(c))
	{
		val=(val<<3)+(val<<1)+1ll*(c^48);
		c=getchar();
	}
	return val;
}
int T,n,m,d,q;

int a[N];
long long c[N];
long long num[N];

struct Node
{
	int v;
	long long w;
	bool friend operator < (const Node& x,const Node& y)
	{
		return x.w>y.w;
	}
};
vector<Node> e[N];

struct Edge
{
	int s,t,id;
	long long ans;
};
Edge que[M];

bool cmp(Edge x,Edge y)
{
	return x.s<y.s;
}

long long h[N];
bool flag[N];

void dij(int x)
{
	memset(h,0x3f,sizeof(h));
	memset(flag,false,sizeof(flag));
	priority_queue<Node> q;
	q.push((Node){x,0});
	h[x]=0;
	
	while(!q.empty())
	{
		int u=q.top().v;
		long long len=q.top().w;
		q.pop();
		if(flag[u])
		{
			continue;
		}
		flag[u]=true;
		for(auto i:e[u])
		{
			if(h[u]+i.w<h[i.v])
			{
				h[i.v]=h[u]+i.w;
				q.push((Node){i.v,h[i.v]});
			}
		}
	}
	return ;
}
bool recmp(Edge x,Edge y)
{
	return x.id<y.id;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	T=read(),n=read(),m=read(),d=read(),q=read();
	int k;
	for(int i=1;i<=m;i++)
	{
		num[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		
		k=read();
		for(int i=1;i<=k;i++)
		{
			a[i]=read(),c[i]=read();
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(i!=j)
				{
				 
				 	e[a[i]].push_back((Node){a[j],c[i]+c[j]});
				}
			}
		}
	}                                             
	for(int i=1;i<=q;i++)
	{
		que[i].s=read();
		que[i].t=read();
		que[i].id=i;
	}
	sort(que+1,que+1+q,cmp);
	for(int i=1;i<=q;i)
	{
		int u=que[i].s;
		dij(u);
		while(que[i].s==u)
		{
			que[i].ans=h[que[i].t]+num[que[i].s]+num[que[i].t];
			i++;
		}
	}
	sort(que+1,que+1+q,recmp);
	for(int i=1;i<=q;i++)
	{
		cout<<que[i].ans<<"\n";
	}
	return 0;
}