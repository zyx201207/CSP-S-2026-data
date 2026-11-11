#include <bits/stdc++.h>
using namespace std;
#define N 500010
#define M 510
#define ll long long
#define eb emplace_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define mp make_pair
#define fi first
#define se second
int cc,n,m,D,Q,K;
//int head[W],ver[M],edge[M],Next[M],tot;
int w[N];
ll dis[M][M],ed[N][22];
int idx[N][22],cnt[N];
//vector<pii> v[N];
inline void getmn(ll &x,ll y) {x=(x<y?x:y);}
//void ADD(int x,int y,int z) {ver[++tot]=y;edge[tot]=z;Next[tot]=head[x];head[x]=tot;}
//void dij(int rt)
//{
//	priority_queue<pli> q;
//	for (int i=1;i<=idx;i++) vis[i]=0,d[i]=0x3f3f3f3f3f3f3f3f;
//	d[rt]=0,q.push(mp(0,rt));
//	while (!q.empty())
//	{
//		int x=q.top().se;q.pop();
//		if (vis[x]) continue;
//		vis[x]=1;
//		for (int i=head[x];~i;i=Next[i])
//		{
//			int y=ver[i];
//			if (d[x]+edge[i]<d[y]) d[y]=d[x]+edge[i],q.push(mp(-d[y],y));
//		}
//	}
//}
void Floyd()
{
	for (int k=1;k<=m;++k)
		for (int i=1;i<=m;++i)
			for (int j=1;j<=m;++j)
				getmn(dis[i][j],dis[i][k]+dis[k][j]);
}
inline int read()
{
	int s=0;char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int x,y;
	cc=read(),m=read(),n=read(),D=read(),Q=read();
	for (int i=1;i<=n;++i) w[i]=read();
	for (int i=1;i<=m;++i)
	{
		K=read();
		for (int j=1;j<=K;++j)
		{
			x=read(),y=read();
			++cnt[x];
			idx[x][cnt[x]]=i,ed[x][cnt[x]]=y;
			//v[x].eb(i,y);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i=1;i<=m;++i) dis[i][i]=0;
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=cnt[i];j++)
			for (int k=j+1;k<=cnt[i];k++)
			{
				getmn(dis[idx[i][j]][idx[i][k]],ed[i][j]+ed[i][k]);
				dis[idx[i][k]][idx[i][j]]=dis[idx[i][j]][idx[i][k]];
			}
//		for (pii j:v[i])
//			for (pii k:v[i])
//			{
//				getmn(dis[j.fi][k.fi],j.se+k.se);
//				dis[k.fi][j.fi]=dis[j.fi][k.fi];
//			}
	}
	Floyd();
	for (int i=1;i<=Q;i++)
	{
		x=read(),y=read();
		ll res=1e16;
		for (int j=1;j<=cnt[x];j++)
			for (int k=1;k<=cnt[y];k++)
				getmn(res,ed[x][j]+ed[y][k]+dis[idx[x][j]][idx[y][k]]);
//		for (pii j:v[x])
//			for (pii k:v[y])
//				getmn(res,j.se+k.se+dis[j.fi][k.fi]);		
		printf("%lld\n",res+w[x]+w[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

tell n m
int merge?
tot=-1;
for i for i

N?M?

*/
