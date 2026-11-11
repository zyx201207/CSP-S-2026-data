#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e3+10;
int c,n,ans;
int f[maxn],mi[maxn],cnt[maxn][maxn];
ll d;
ll X[maxn];
int read()
{
	int ret=0,w=1;char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
	return ret*w;
}
ll lread()
{
	ll ret=0,w=1;char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
	return ret*w;
}
void input()
{
	n=read(),d=lread();
	for(int i=1;i<=n;i++) X[i]=lread();
}
void pre()
{
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		int l=i,r=n,mid;
		while(l<=r)
		{
			mid=l+(r-l)/2;
			if(X[mid]-X[i]>d) r=mid-1;
			else l=mid+1;
		}
		f[i]=r;
//		cout<<"f["<<i<<"]="<<f[i]<<'\n';
	}
}
void dfs(int st,int u,int dis)
{
	if(dis==mi[u]) cnt[st][u]++;
	else if(dis<mi[u]) cnt[st][u]=1,mi[u]=dis;
	else return;
	for(int i=u+1;i<=f[u];i++) dfs(st,i,dis+1);
}
void deal()
{
	ans=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cnt[i][j]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) mi[j]=maxn;
		dfs(i,i,0);
	}
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) ans+=(cnt[i][j]==2);
}
void solve()
{
	input();
	pre();
	deal();
	printf("%d\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	int t=read();
	while(t--) solve();
	return 0;
}