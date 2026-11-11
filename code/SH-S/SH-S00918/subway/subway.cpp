#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N = 500+4,M = 5e5+4;
const int INF = 0x3f3f3f3f;
int n,m,d,q;
int w[M],k[N];
vector <PII> pos[N];
vector <int> rail[N];
int t[N][N];
int a[N][N];
int r[N][N];
int f[N][N];
void input()
{
	scanf("%d%d%d%d%d",&n,&n,&m,&d,&q);
	for(int i=1; i<=m; i++) scanf("%d",w+i);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",k+i);
		for(int j=0; j<k[i]; j++)
		{
			int tmp;
			scanf("%d%d",&tmp,&t[i][j]);
			pos[tmp].push_back({i,j});
			rail[i].push_back(tmp);
		}
	}
	memset(r,INF,sizeof(r));
}

void make_r()
{
	for(int i=1; i<=n; i++)
		r[i][i] = 0;
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<rail[i].size(); j++)
		{
			int u = rail[i][j];
			if(pos[u].size() == 1) continue;
			for(int l=0; l<pos[u].size(); l++)
			{
				int v = pos[u][l].first;
				if(v == i) continue;
				r[i][v] = min(t[i][j]+t[v][pos[u][l].second],r[i][v]);
			}
		}
	}
}
void make_f()
{
	memset(f,INF,sizeof(f));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			f[i][j] = r[i][j];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				f[i][j] = min(f[i][k]+f[k][j],f[i][j]);
}


int value(int x,int y)
{
	int ans = 2e9;
	for(int i=0; i<pos[x].size(); i++)
	{
		for(int j=0; j<pos[y].size(); j++)
		{
			int tmp = f[pos[x][i].first][pos[y][j].first];
			int X = w[x]+t[pos[x][i].first][pos[x][i].second];
			int Y = w[y]+t[pos[y][j].first][pos[y][j].second];
			ans = min(ans,tmp+X+Y);
		}
	}
	return ans;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	input();
	make_r();
	make_f();
	d = q;
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",value(x,y));
	}
	return 0;
}
