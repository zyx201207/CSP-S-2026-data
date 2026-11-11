#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5;
const int M=5e5+5;
const int INF=1e15;
int c;
int n,m,d,q;
int w[M];
vector<pair<int,int> >v[M+N];
int f[N][N];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k; cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			v[a].push_back({m+i,t});
			v[m+i].push_back({a,t});
		}
	}
	memset(f,0x3f,sizeof(f));//
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int x=1;x<=m;x++)
	{
		for(auto e1:v[x])
		{
			int y1=e1.first,
				w1=e1.second;
			for(auto e2:v[x])
			{
				int y2=e2.first,
					w2=e2.second;
				f[y1-m][y2-m]=min(f[y1-m][y2-m],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int dis=INF;
		for(int i=0;i<v[x].size();i++)
			for(int j=0;j<v[y].size();j++)
				dis=min(dis,f[v[x][i].first-m][v[y][j].first-m]+v[x][i].second+v[y][j].second);
		dis+=w[x]+w[y];
		cout<<dis<<endl;
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
* 
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
