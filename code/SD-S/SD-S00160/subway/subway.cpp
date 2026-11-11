#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define pii pair<int,int>
const int M=5e5+5;
const int N=505;
int c,n,m,d,q,w[M];
vector<pii>sub[M];
vector<pii>line[N];
ull val[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(val,0x3f,sizeof val);
	for(int i=1;i<=n;i++)
		val[i][i]=0;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1,cnt;i<=n;i++)
	{
		cin>>cnt;
		for(int j=1,a,t;j<=cnt;j++)
		{
			cin>>a>>t;
			sub[a].push_back({i,t});
			line[i].push_back({a,t});
		}
	}
	for(int u=1;u<=n;u++)
	{
		for(pii p1:line[u])
		{
			int s=p1.first;
			int v1=p1.second;
			for(pii p2:sub[s])
			{
				int v=p2.first;
				int v2=p2.second;
				val[u][v]=min(val[u][v],(v1+v2)*1ULL);
				val[v][u]=min(val[v][u],(v1+v2)*1ULL);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=n;k++)
		{
			for(int j=1;j<=n;j++)
			{
				val[i][j]=min(val[i][j],val[i][k]+val[k][j]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++)
	{
		cin>>x>>y;
		ull ans=1e18+7;
		for(pii p1:sub[x])
		{
			for(pii p2:sub[y])
			{
				ans=min(ans,1ULL*(p1.second+p2.second)+val[p1.first][p2.first]);
			}
		}
		ans+=(w[x]+w[y])*1ULL;
		cout<<ans<<'\n';
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
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
 */
