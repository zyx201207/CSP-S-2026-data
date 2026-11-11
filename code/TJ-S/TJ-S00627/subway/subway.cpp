#include<bits/stdc++.h>
using namespace std;
const long long MAX=9000000000000000000;
int c,n,m,d,q;
int w[500005];
vector< pair<int,int> > e[500005];
vector< pair<int,int> > E[505];
long long f[505][505];
void floyd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				f[i][j]=0;
				continue;
			}
			f[i][j]=MAX;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<E[i].size();j++)
		{
			long long len=E[i][j].second;
			f[i][E[i][j].first]=min(f[i][E[i][j].first],len);
			f[E[i][j].first][i]=min(f[E[i][j].first][i],len);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i][k]!=MAX && f[k][j]!=MAX) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q ;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i] ;
	}
	for(int i=1;i<=n;i++)
	{
		int k,a,t;
		cin >> k ;
		for(int j=1;j<=k;j++)
		{
			cin >> a >> t ;
			e[a].push_back(make_pair(m+i,t));
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=0;i<e[k].size();i++)
		{
			for(int j=i+1;j<e[k].size();j++)
			{
				//cout << e[k][i].first << ' ' << e[k][j].first << endl ;
				E[e[k][i].first-m].push_back(make_pair(e[k][j].first-m,e[k][i].second+e[k][j].second));
				E[e[k][j].first-m].push_back(make_pair(e[k][i].first-m,e[k][i].second+e[k][j].second));
			}
		}
	}
	floyd();
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout << f[i][j] << ' ' ;
		}
		cout << endl ;
	}*/
	int in1,in2;
	for(int i=1;i<=q;i++)
	{
		cin >> in1 >> in2 ;
		long long ans=MAX;
		for(int x=0;x<e[in1].size();x++)
		{
			for(int y=0;y<e[in2].size();y++)
			{
				ans=min(ans,f[e[in1][x].first-m][e[in2][y].first-m]+e[in1][x].second+e[in2][y].second);
			}
		}
		cout << ans+w[in1]+w[in2] << endl ;
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
