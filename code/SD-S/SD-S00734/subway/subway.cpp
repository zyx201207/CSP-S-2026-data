#include<bits/stdc++.h>
using namespace std;
long long n,m,d,q;
long long w[1000100];
long long G[510][510];
long long a,t,k[510];
struct pa
{
	int first;
	long long seconed;
};
vector<pa> z[1000100];
vector<pa> s[510];
void Solve()
{
	memset(G,0x3f,sizeof G);
	cin >> n >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++)
	{
		G[i][i]=0;
		cin >> k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin >> a >> t;
			z[a].push_back({i,t});
			s[i].push_back({a,t});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<s[i].size();j++)
		{
			int su=s[i][j].first;
			long long sw=s[i][j].seconed;
			for(int k=1;k<z[su].size();k++)
			{
				int u=z[su][k].first;
				long long w=sw+z[su][k].seconed;
				G[i][u]=min(G[i][u],w);
				G[u][i]=min(G[u][i],w);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	
//	for(int i=1;i<=n;i++){
//	for(int j=1;j<=n;j++)
//	cout << G[i][j] << ' ';cout << '\n';}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		long long cnt=0x7ffffffffffffff;
		for(int i=0;i<z[x].size();i++) for(int j=0;j<z[y].size();j++)
		{
			//cout << G[z[x][i].first][z[y][j].first] << ']';
			cnt=min(cnt,G[z[x][i].first][z[y][j].first]+z[x][i].seconed+z[y][j].seconed);
		}
		cout << cnt+w[x]+w[y] << '\n';
	}
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;//cin >> T;
	while(T--)
		Solve();
	return 0;
}
