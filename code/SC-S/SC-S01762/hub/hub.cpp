#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int c,t,n,k;
int vis[N];
struct edge
{
	int x,y;
}w[N];
int q=0;
int A=0,B=0,C=0,dep[N],stk[N];
int head[N],nxt[N],to[N],tot=1,b[N];
void add(int x,int y)
{
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
}
void dfs(int x,int from)
{
	dep[x]=dep[from]+1;
	if(dep[x]>dep[A]) A=x;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(vis[i>>1]||y==from) continue;
		dfs(y,x);
	}
}
void dfs2(int x,int from)
{
	dep[x]=dep[from]+1;
	stk[++stk[0]]=x;
	if(dep[x]>dep[B]) B=x,C=stk[(stk[0]+1)/2];
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(vis[i>>1]||y==from) continue;
		dfs2(y,x);
	}
	stk[0]--;
}
int h[N];
void dfs3(int x,int from)
{
	h[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(vis[i>>1]||y==from) continue;
		dfs3(y,x);h[x]=max(h[x],h[y]+1);
	}
	b[++q]=h[x];
}
void get(int x)
{
	A=B=C=0;
	dfs(x,0);dfs2(A,0);dfs3(C,0);
}
int cnt[N];
ll calc()
{
	for(int i=0;i<=n;i++) cnt[i]=0;
	for(int i=1;i<=q;i++) cnt[b[i]]++;
	q=0;for(int i=n;i>=0;i--) while(cnt[i]--) b[++q]=i;
	b[q+1]=0;
	return b[k+1];
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<=max(n,tot);i++)
		{
			head[i]=nxt[i]=to[i]=vis[i]=0;
		}
		tot=1;
		for(int i=1;i<=n-1;i++)
		{
			int x,y;scanf("%d%d",&x,&y);w[i]={x,y};
			add(x,y);add(y,x);
		}
		ll ans=1e18;
		q=0;
		get(1);ans=min(ans,calc());
		for(int i=1;i<=n-1;i++)
		{
			vis[i]=1;
			q=0;
			get(w[i].x);get(w[i].y);
			ans=min(ans,calc());
			vis[i]=0;
		} 
		printf("%lld\n",ans);
	}
	return 0;	
}