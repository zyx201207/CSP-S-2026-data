#include<bits/stdc++.h>
using namespace std;
const int maxn1=1e2+10,maxn2=1e3+10,inf=1e9+10;
int c,n,k,ans;
int de[maxn2];
vector<int>e[maxn2];
int read()
{
	int ret=0,w=1;char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
	return ret*w;
}
void init()
{
	ans=inf;
	for(int i=1;i<=n;i++) e[i].clear();
}
void input()
{
	n=read(),k=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v),e[v].push_back(u);
	}
}
void dfs(int u,int fa)
{
}
void deal1()
{
//	for(int i)
}
void dfs2(int u,int fa,int dep)
{
	de[u]=min(de[u],dep);
	for(int v:e[u]) if(fa!=v) dfs2(v,u,dep+1);
}
void deal2()
{
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int res=0;
			for(int k=1;k<=n;k++) de[k]=inf;
			dfs2(i,0,0);
			dfs2(j,0,0);
			for(int k=1;k<=n;k++) res=max(res,de[k]);
			ans=min(ans,res);
		}
	}
}
void solve()
{
	init();
	input();
	if(k!=2) deal1();
	else if(k==2) deal2();
	printf("%d\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	int t=read();
	while(t--) solve();
	return 0;
}