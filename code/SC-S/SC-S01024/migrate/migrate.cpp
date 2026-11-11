#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long pos[N];
int c,T,n;
long long d;
int readi()
{
	int x=0,f=1;
 	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
long long read()
{
	long long x=0,f=1;
 	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=(x<<3ll)+(x<<1ll)+c-'0';c=getchar();}
	return x*f;
}
struct EDGE
{
	int next;
	int to;
}ls[N*4];
int num=-1,head[N]; 
void add(int a,int b)
{
	num++;
	ls[num].to=b;
	ls[num].next=head[a];
	head[a]=num;
	return ;
}
struct node
{
	int l,r;
	node(int l=0,int r=0):l(l),r(r){}
}bc[N];
long long dis[N],cnt[N];
void dfs(int x,int w)
{
	if(w>dis[x]) return ;
	if(w==dis[x]) cnt[x]++;
	if(w<dis[x]) cnt[x]=1,dis[x]=w;
	for(int i=head[x];~i;i=ls[i].next)
	{
		int v=ls[i].to;
		dfs(v,w+1);
	}
	return ;
}
void solve()
{
	n=readi(),d=read();
	for(int j=1;j<=n;j++) head[j]=-1,num=-1;
	for(int i=1;i<=n;i++) pos[i]=read();
	int l=1;
	for(int r=1;r<=n;r++)
	{
		while(l<=r && pos[r]-pos[l]>d) l++;
		bc[r]=node(l,r-1);
	}
	for(int i=1;i<=n;i++)
		for(int j=bc[i].l;j<=bc[i].r;j++) add(i,j);
	int ans=0;
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++) dis[j]=inf,cnt[j]=0;
		dfs(i,0);
		for(int j=1;j<=n;j++)
		if(cnt[j]==2) ans++;
	} 
	printf("%d\n",ans);
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=readi(),T=readi();
	while(T--) solve();
	return 0;
}