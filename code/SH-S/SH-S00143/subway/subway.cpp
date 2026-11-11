#include<bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, dd, q;
int w[500005], k[505], d[505][505]; // mle??
/*
struct toline{
	int line, ti;
}
*/ 
vector<pair<int, int> > toline[500005]; // toline[i]: {lines in station i, time spent to go to it}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>dd>>q;
//	cout<<c<<n<<m<<dd<<q<<endl;
	for(int i = 1; i <= m; i++) cin>>w[i];
	for(int i = 1; i <= n; i++)
	{
		cin>>k[i];
		for(int j = 1; j <= k[i]; j++) 
		{
			int a, t; cin>>a>>t;
			toline[a].push_back({i, t});
		}
	}
//	cout<<toline[2][0]<<' '<<toline[2][1]<<endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i != j) d[i][j] = (int)4e18;
		}
	}
		for(int i = 1; i <= m; i++) // 500000
		{
			if(toline[i].size() > 1)
			{
				for(int jj = 0; jj < toline[i].size(); jj++) // 400
				{
					for(int kk = jj + 1; kk < toline[i].size(); kk++)
					{
						int j = toline[i][jj].first, k = toline[i][kk].first;
//						g[j].push_back(k), g[k].push_back(j);
						d[j][k] = d[k][j] = toline[i][jj].second + toline[i][kk].second;
					}
				}
			}
		}
//		cout<<d[1][1]<<d[1][2]<<' '<<d[2][2]<<endl;
		for(int k = 1; k <= n; k++)
		{
//			cout<<"k = "<<k<<endl;
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= n; j++)
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//					cout<<"i = "<<i<<" j = "<<j<<" d[i][j] = "<<d[i][j]<<endl;
				}
			}
		}
//		cout<<d[1][2]<<endl;
		while(q--)
		{
			int x, y, ans = (int)4e18; cin>>x>>y;
			for(int i = 0; i < toline[x].size(); i++)
			{
				for(int j = 0; j < toline[y].size(); j++)
				{
					int ii = toline[x][i].first, jj = toline[y][j].first;
//					cout<<"ii: "<<ii<<"jj: "<<jj<<"d: "<<d[ii][jj]<<endl;
//					cout<<w[x]<<'+'<<toline[x][i].second<<'+'<<d[ii][jj]<<'+'<< toline[y][j].second <<'+'<<w[y]<<endl;
					ans = min(ans, w[x] + toline[x][i].second + d[ii][jj] + toline[y][j].second + w[y]); 
				}
			}
			cout<<ans<<endl;
//			cout<<w[x] + d[x][y] + w[y]<<endl;
//			cout<<w[x] + w[y]<<endl;
		}
	return 0;
}
