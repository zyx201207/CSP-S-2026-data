#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N=500010,M=510;
const ll INF=1e18;

//n：地铁线路数  m：地铁站数 
int n,m,md,q;
int w[N];
ll d[M][M];
vector<pii> ava[N];//x：方点下标 y：距离 

void floyd()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway6.in","r",stdin);
//	freopen("t.out","w",stdout);
	
	int C;
	scanf("%d%d%d%d%d",&C,&n,&m,&md,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			d[i][j]=(i==j? 0: INF);
	
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			for(pii t:ava[x]) d[i][t.x]=d[t.x][i]=min(d[i][t.x],(ll)t.y+y);
			ava[x].push_back({i,y});
		}
	}
	
	floyd();
	
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=INF;
		for(pii u:ava[x])
			for(pii v:ava[y])
			{
				ans=min(ans,(ll)w[x]+w[y]+u.y+v.y+d[u.x][v.x]);
			}
		printf("%lld\n",ans);
	}
	
	return 0;
}