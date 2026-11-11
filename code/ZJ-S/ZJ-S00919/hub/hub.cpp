#include<bits/stdc++.h>
using namespace std;
int id,t,n,m,i,x,y,head[101],a[101],fa[101],dep[101],f[101][21],s,min_;
bool fl[101];
struct tree
{
	int nxt,a;
}e[201];
void edge(int x,int y)
{
	s++;
	e[s].nxt=head[x];
	e[s].a=y;
	head[x]=s;
	return ;
}
int find(int x)
{
	if(fa[x]==x)
	  return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	fa[x]=y;
	return ;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
	  swap(x,y);
	int i;
	for(i=20;i>=0;i--)
	   if(dep[f[x][i]]>=dep[y])
	     x=f[x][i];
	if(x==y)
	  return x;
	for(i=20;i>=0;i--)
	   if(f[x][i]!=f[y][i])
	   {
	   	x=f[x][i];
	   	y=f[y][i];
	   }
	return f[x][0];
}
void dfs(int x,int y)
{
	int i;
	if(x>m)
	{
		int j,s=0,min__,max_=0;
		for(i=1;i<=m;i++)
		   fa[a[i]]=a[i];
		for(i=1;i<=m;i++)
		   for(j=head[a[i]];j;j=e[j].nxt)
		      if(fl[e[j].a]&&find(a[i])!=find(e[j].a))
		        merge(a[i],e[j].a);
		for(i=1;i<=m;i++)
		   if(find(a[i])==a[i])
		     s++;
		if(s>2)
		  return ;
		for(i=1;i<=n;i++)
		{
			min__=INT_MAX;
			for(j=1;j<=m;j++)
			   min__=min(min__,dep[i]+dep[a[j]]-2*dep[lca(i,a[j])]);
			max_=max(max_,min__);
		}
		min_=min(min_,max_);
		return ;
	}
	for(i=n-m+x;i>y;i--)
	{
		a[x]=i;
		fl[i]=true;
		dfs(x+1,i);
		fl[i]=false;
	}
	return ;
}
void DFS(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	int i;
	for(i=1;i<=20;i++)
	   f[x][i]=f[f[x][i-1]][i-1];
	for(i=head[x];i;i=e[i].nxt)
	   if(e[i].a!=fa)
	     DFS(e[i].a,x);
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&id,&t);
	while(t--)
	{
		s=0;
		min_=INT_MAX;
		memset(head,0,sizeof(head));
		scanf("%d%d",&n,&m);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			edge(x,y);
			edge(y,x);
		}
		DFS(1,0);
		dfs(1,0);
		cout<<min_<<endl;
	}
	return 0;
}
