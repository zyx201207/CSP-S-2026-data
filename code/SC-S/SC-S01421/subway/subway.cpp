#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505],hd[500050],hed[500050],tot,st,ed,v1[500050],v2[505],tot2;
long long w[500050];
struct node1
{
	int u,v,z;
}dtz[500050];
struct node2
{
	int u,zd,t;
}a[500050];
void add(int u,int v,int z)
{
	dtz[++tot]=(node1){hd[u],v,z};
	hd[u]=tot;
	return;
}
void add2(int u,int v,int z)
{
	a[++tot2]=(node2){hed[u],v,z};
	hed[u]=tot2;
	return;
}
struct node
{
	int u,op;
	long long ti;
	bool operator<(node x)const
	{
		return ti>x.ti;
	}
}y;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)
	{
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];++j)
		{
			int e;
			long long f;
			scanf("%d%lld",&e,&f);
			add(e,i,f);
			add2(i,e,f);
		}
	}
	while(q--)
	{
		scanf("%d%d",&st,&ed);
		priority_queue<node>q;
		node x;
		x.ti=w[st]+w[ed];
		x.u=st;
		x.op=2;
		q.push(x);
		for(int i=1;i<=m;++i)
		{
			v2[i]=0;
		}
		for(int i=1;i<=n;++i)
		{
			v1[i]=0;
		}
		while(!q.empty())
		{
			x=q.top();
			q.pop();
			if(x.op==2)
			{
				if(v2[x.u])
				{
					continue;
				}
				v2[x.u]=1;
				if(x.u==ed)
				{
					break;
				}
				for(int i=hd[x.u];i;i=dtz[i].u)
				{
					if(!v1[dtz[i].v])
					{
						y.op=1;
						y.ti=x.ti+dtz[i].z;
						y.u=dtz[i].v;
						q.push(y);
					}
				}
			}
			else
			{
				if(v1[x.u])
				{
					continue;
				}
				v1[x.u]=1;
				for(int i=hed[x.u];i;i=a[i].u)
				{
					if(!v2[a[i].zd])
					{
						y.op=2;
						y.ti=x.ti+a[i].t;
						y.u=a[i].zd;
						q.push(y);
					}
				}
			}
		}
		printf("%lld\n",x.ti);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}