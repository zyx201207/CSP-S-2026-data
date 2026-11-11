#include<bits/stdc++.h>
using namespace std;
int a[301000];
struct dian
{
	int w;
	int last;
	int dis;
	int book;
}r[301000];
struct lu
{
	int dis;
	int next;
	int to;
}l[301000];
struct chelu
{
	int nextzhan;
	int to;
}cl[301000];
struct che
{
	int last;
	int dis;
	int book;
}cr[301000];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,T,e=0,f=0;
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&T);
	for(int i=1;i<=m;i++)
	scanf("%d",&r[i].w);
	for(int i=1;i<=n;i++)
	{
		int k,v,u,vo,uo;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int v,o;
			scanf("%d%d",&v,&o);
			e++;
			l[e].dis=o;
			l[e].next=r[v].last;
			l[e].to=i;
			r[v]last=e;
			f++;
			cl[f].to=v;
			cl[f].nextzhan=cr[i].last;
			cr[i].last=f;
			}
		}
	}
	queue<int>q;
	for(int zz=1;zz<=T;zz++)
	{
		for(int i=0;i<=n;++)
		{
			cr[i].dis=100000000;
			cr[i].book=0;
		}
		int ff,tt;
		scanf("%d%d",&ff,&tt);
		int t=r[ff].last;
		while(t!=0)
		{
			int y=l[t].to;
			cr[y].dis=l[t].dis;
			t=l[t].next;
		}
		int pp=0;
		for(int i=1;i<=n;i++)
		{
			if(cr[i].dis<cr[pp].dis)
			pp=i;
		}
		q.push(pp);
		cr[pp].book=1;
		while(q.size()!=0)
		{
			int x=q.front();q.pop();
			int t=cr[x].last;
			while(t!=0)
			{
				int y=cl[t].to;
				int ttt=cr[y].last;
				while(ttt!=0)
				{
					int yy=
				}
			}
		}
	}
	return 0;
}
