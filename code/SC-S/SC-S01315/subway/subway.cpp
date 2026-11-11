#include<iostream>
#include<queue>
#include<vector>
#define int long long
using namespace std;
const int N=5e5+5,M=5e6+5,MAX=1e9;
struct Edge {
	int to,next,val;
} edge[M<<1];
int tot,head[N];
void add(int x,int y,int val) {
	edge[++tot].to=y;
	edge[tot].val=val;
	edge[tot].next=head[x];
	head[x]=tot;
	return ;
}
int c,n,m,d,q;
int a[N],di[N],shi[N],zdl[5005][5005],flag[N];
void dijistra(int x) {
	priority_queue<pair<int,int> > q1;
	q1.push({0,x});
	while (!q1.empty()) {
		int now=q1.top().second,val=-q1.top().first;
		q1.pop();
		if (flag[now]) continue;
		flag[now]=1;
		for (int i=head[now]; i; i=edge[i].next) {
			int y=edge[i].to;
			if (zdl[x][y]>val+edge[i].val) {
				zdl[x][y]=val+edge[i].val;
				q1.push({-zdl[x][y],y});
			}
		}
	}
	return ;
}
vector<int> v[N];
struct Edge2{
	int to,next,val;
}edge2[N];
int tot2,head2[N];
void add2(int x,int y,int val)
{
	edge2[++tot2].to=y;
	edge2[tot2].val=val;
	edge2[tot2].next=head2[x];
	head2[x]=tot2;
	return ;
}
int xianlu[505][505],flag2[505];
int xianluflag[505][505],xianlubian[505];
void xlzdl(int x)
{
	priority_queue<pair<int,int> > q1;
	q1.push({0,x});
	while (!q1.empty()) {
		int now=q1.top().second,val=-q1.top().first;
		q1.pop();
		if (flag2[now]) continue;
		flag2[now]=1;
		for (int i=head2[now]; i; i=edge2[i].next) {
			int y=edge2[i].to;
			if (xianlu[x][y]>val+edge2[i].val) {
				xianlu[x][y]=val+edge2[i].val-xianlubian[y];
				q1.push({-xianlu[x][y],y});
			}
		}
	}
	return ;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for (int i=1; i<=m; i++) {
		scanf("%lld",&a[i]);
	}
	for (int i=1,ge; i<=n; i++) {
		scanf("%lld",&ge);
		for (int j=1; j<=ge; j++) {
			scanf("%lld%lld",&di[j],&shi[j]);
			xianlubian[i]=shi[j]*2;
			if (c<=11) {
				for (int p=1; p<j; p++) {
					add(di[p],di[j],shi[j]+shi[p]);
					add(di[j],di[p],shi[j]+shi[p]);
				}
			}
			else if (c>=12 && c<=19)
			{
				for (int p=0;p<v[di[j]].size();p++)
				{
					int now=v[di[j]][p];
					if (xianluflag[now][i]) continue;
					xianluflag[now][i]=1;
					xianluflag[i][now]=1;
					int val=xianlubian[now]+xianlubian[i];
					add2(now,i,val);
					add2(i,now,val);
				}
				v[di[j]].push_back(i);
			}
		}
	}
	if (c<=11)
	{
		for (int i=1; i<=m; i++) {
			for (int j=1; j<=m; j++) {
				flag[j]=0;
				zdl[i][j]=MAX;
			}
			dijistra(i);
		}
		for (int i=1,qx,qy; i<=q; i++) {
			scanf("%lld%lld",&qx,&qy);
			cout<<zdl[qx][qy]+a[qx]+a[qy]<<"\n";
		}
	}
	else if (c>=12 && c<=19)
	{
		for (int i=1;i<=505;i++)
		{
			for (int j=1;j<=505;j++)
			{
				flag2[j]=0;
				xianlu[i][j]=MAX;
			}
			xlzdl(i);
		}
		for (int i=1,qx,qy;i<=q;i++)
		{
			scanf("%lld%lld",&qx,&qy);
			int minn=MAX;
			for (int j=0;j<v[qx].size();j++)
			{
				for (int p=0;p<v[qy].size();p++)
				{
					int v1=v[qx][j],v2=v[qy][p];
					minn=min(minn,xianlu[v1][v2]+xianlubian[v2]);
				}
			}
			cout<<minn+a[qx]+a[qy]<<"\n";
		}
	}
	return 0;
}