#include<bits/stdc++.h>
using namespace std;
int n,k,c,t,ans,dep[1000006],fa[1000006][30],f[1000006];
int cnt,head[1000006],to[2000006],nxt[2000006];
//void star(int u,int v)
//{
//	cnt++;
//	nxt[cnt]=head[u];
//	head[u]=cnt;
//	to[cnt]=v;
//}
//int find(int x)
//{
//	if (f[x]==x)
//		return x;
//	return f[x]=find(f[x]); 
//}
//int wei(int x)
//{
//	int res=0,tot=0,a=0,b=0;
//	for (int i=1;i<=n;i++)
//		f[i]=i;
//	for (int u=1;u<=n;u++)
//		if (x&(1<<(u-1)))
//		{
//			res++;	
//			if (res>k)
//				return res;
//			int fu=find(u);
//			for (int j=head[u];j;j=nxt[j])
//			{
//				int v=to[j];
//				int fv=find(v);
//				if (fu!=fv)
//					f[fv]=fu;
//			}
//		}
//	for (int u=1;u<=n;u++)
//		if (x&(1<<(u-1)))
//		{
//			int fu=find(u);
//			if (!a)
//				a=fu;
//			if (f[u]!=a)
//			{
//				if (!b)
//					b=fu;
//				else if (fu!=b)
//					return 0;
//			}
//		}
//	return res;
//}
//void dfs(int u,int Fa)
//{
//	dep[u]=dep[Fa]+1;
//	fa[u][0]=Fa;
//	int w=log2(dep[u]);
//	for (int i=1;i<=w;i++)
//		fa[u][i]=fa[fa[u][i-1]][i-1]; 
//	for (int i=head[u];i;i=nxt[i])
//	{
//		int v=to[i];
//		if (v!=Fa)
//			dfs(v,u);
//	}
//}
//int lca(int a,int b)
//{
//	if (dep[a]<dep[b])
//		swap(a,b);
//	while (dep[a]>dep[b])
//	{
//		int w=log2(dep[a]-dep[b]);
//		a=fa[a][w];
//	}
//	if (a==b)
//		return a;
//	int w=log2(dep[a]);
//	for (int i=w;i>=0;i--)
//		if (fa[a][i]!=fa[b][i])
//		{
//			a=fa[a][i];
//			b=fa[b][i];
//		}
//	return fa[a][0];
//}
//void solve0()
//{
//	while (t--)
//	{
//		cnt=0;
//		int sum=1e9;
//		memset(head,0,sizeof(head));
//		memset(dep,0,sizeof(dep));
//		memset(fa,0,sizeof(fa));
//		scanf("%d%d",&n,&k);
//		for (int i=1,x,y;i<n;i++)
//		{
//			scanf("%d%d",&x,&y);
//			star(x,y);
//			star(y,x);
//		}	
//		dfs(1,1);
//		for (int i=0;i<(1<<n);i++)
//		{
//			if (wei(i)!=k)
//				continue;
//			int ans=0;
//			
//			sum=min(sum,ans);
//		}
//		printf("%d\n",sum);
//	} 
//}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
		while (t--)
		{
			scanf("%d%d",&n,&k);
			for (int i=1,x,y;i<n;i++)
				scanf("%d%d",&x,&y);
			int m=(n-1)/2;
			if (k==1)
				printf("%d\n",m/2);
			else
			{
				if (k>=m)
					printf("1\n");
				else 
					printf("%d\n",(m+2)/3-(k-2)/2);
			}
		}
	return 0;
}