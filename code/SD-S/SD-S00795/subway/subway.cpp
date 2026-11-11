#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd()
{
	int x=0;char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);x=(x<<3)+(x<<1)+(c^48),c=getchar());
	return x;
}
int t[500005],d[5005][5005];
struct way{int v,w;}a[500005][25];
int b[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=rd(),n=rd(),m=rd(),l=rd(),q=rd();
	for(int i=1;i<=m;i++)
		t[i]=rd();
	for(int i=1;i<=n;i++)
		for(int j=1,k=rd(),u,w;j<=k;j++)
			u=rd(),w=rd(),a[u][++b[u]]={i,w};
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<b[i];j++)
			for(int k=j+1;k<=b[i];k++)
				d[a[i][j].v][a[i][k].v]=d[a[i][k].v][a[i][j].v]=
				min(d[a[i][j].v][a[i][k].v],a[i][j].w+a[i][k].w);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--)
	{
		int x=rd(),y=rd(),ans=1e18;
		for(int i=1;i<=b[x];i++)
			for(int j=1;j<=b[y];j++)
				ans=min(ans,a[x][i].w+a[y][j].w+d[a[x][i].v][a[y][j].v]);
		cout<<t[x]+t[y]+ans<<'\n';
	}
	return 0;
}
