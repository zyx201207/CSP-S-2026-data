#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define M 2000010
#define ll long long
#define eb emplace_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
int cc,T,n,K,cnt;
//int head[N],ver[M],Next[M],tot;
vector<int> v[N];
int dep[N],invdep[N],mxdep[N],idep[N];
int pre[N],suf[N];
pii ed[M];
//void ADD(int x,int y) {ver[++tot]=y;Next[tot]=head[x];head[x]=tot;}
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	invdep[x]=1;
	for (int y:v[x])
	{
		if (y==fa) continue;
		dfs1(y,x);
		invdep[x]=max(invdep[x],invdep[y]+1);
	}
}
int dfs2(int x,int fa,int up)
{
	int res=x;
	int l=v[x].size();
	suf[l]=0;
	for (int i=0;i<l;i++) pre[i]=max((i==0?0:pre[i-1]),invdep[v[x][i]]+1);
	for (int i=l-1;i>=0;i--) suf[i]=max(suf[i+1],invdep[v[x][i]]+1);
	for (int i=0;i<l;i++)
	{
		int y=v[x][i];
		if (y==fa) continue;
		int _res=dfs2(y,x,1+max(up,max(i==0?0:pre[i-1],i==l-1?0:suf[i+1])));
		if (mxdep[_res]<mxdep[res]) res=_res;
		invdep[x]=max(invdep[x],invdep[y]+1);
	}
	mxdep[x]=max(up,invdep[x]);
	if (mxdep[x]<mxdep[res]) res=x;
	return res;
}
void dfs3(int x,int fa,int lim,int nd)
{
	idep[x]=0;
	for (int y:v[x])
	{
		if (y==fa||y==lim) continue;
		dfs3(y,x,lim,nd);
		idep[x]=max(idep[x],idep[y]+1);
	}
	if (idep[x]>=nd) ++cnt;
}
void clr()
{
	for (int i=1;i<=n;i++) dep[i]=invdep[i]=mxdep[i]=idep[i]=0;
}
int check(int mid)
{
//	cout << "mid=" << mid << endl;
	clr();
	cnt=0;
	dfs1(1,0);
	int tt=dfs2(1,0,0);
	dfs3(tt,0,0,mid);
//	cout << "tt=" << tt << " cnt=" << cnt << endl;
	if (max(1,cnt)<=K) return 1;
	for (int i=1;i<n;i++)
	{
		int c=0;
		clr();
		int x=ed[i].fi,y=ed[i].se;//x root & leaf
		dfs1(x,y);
		int tx=dfs2(x,y,0);
		cnt=0,dfs3(tx,0,y,mid);
//		cout << "x=" << x << " y=" << y << endl;
//		cout << "tx=" << tx << " cnt=" << cnt << endl;
		c+=max(1,cnt);
		clr();
		dfs1(y,x);
		int ty=dfs2(y,x,0);
		cnt=0,dfs3(ty,0,x,mid);
//		cout << "ty=" << ty << " cnt=" << cnt << endl;
		c+=max(1,cnt);
		if (c<=K) return 1;
	}
	return 0;
}
int mxD;
int a[N],vis[N];
void sol1dfs1(int x,int fa)
{
	vis[x]=1;
	for (int y:v[x])
	{
		if (y==fa) continue;
		if (a[y]) sol1dfs1(y,x);
	}
}
void sol1dfs2(int x,int fa,int d)
{
	dep[x]=min(dep[x],d);
	vis[x]=1;
	for (int y:v[x])
	{
		if (y==fa) continue;
		if (!a[y]) sol1dfs2(y,x,d+1);
	}
}
void sol1()
{
	int ans=1e9;
	int p=(1<<n);
	for (int j=1;j<p;j++)
	{
		int c=0,sum=0;
		for (int i=0;i<n;i++) vis[i+1]=0,dep[i+1]=1e9,a[i+1]=(j>>i)&1,sum+=(j>>i)&1;
		if (sum>K) continue;
//		cout << "a : ";
//		for (int i=1;i<=n;i++) cout << a[i] << ' ';
//		cout << endl;
		for (int i=1;i<=n;i++) if (a[i]&&!vis[i]) ++c,sol1dfs1(i,0);
//		cout << "c=" << c << endl;
		if (c>2) continue;
		for (int i=1;i<=n;i++) if (a[i]) dep[i]=0,sol1dfs2(i,0,0);
		mxD=0;
		for (int i=1;i<=n;i++) mxD=max(mxD,dep[i]);
//		cout << endl;
		ans=min(ans,mxD);
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int x,y;
//	memset(head,-1,sizeof(head));tot=-1;
	mxdep[0]=1e9;
	scanf("%d%d",&cc,&T);
	while (T--)
	{
		scanf("%d%d",&n,&K);
//		tot=-1;
//		for (int i=1;i<=n;i++) head[i]=-1;
		for (int i=1;i<=n;i++) v[i].clear();
		for (int i=1;i<n;i++) scanf("%d%d",&x,&y),v[x].eb(y),v[y].eb(x),ed[i]=mp(x,y);
		if (K>=n) {printf("0\n");continue;}
		if (n<=10) {sol1();continue;}
//		if (cc==13||cc==14) {}
		int l=1,r=n;
		while (l<r)
		{
			int mid=(l+r)>>1;
			if (check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
/*
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/

