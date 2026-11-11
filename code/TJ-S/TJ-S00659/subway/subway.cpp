#include <bits/stdc++.h>
using namespace std;

long long c, n, m, d, q;
long long sta[200005], x[200005];
vector<long long> edge[3000006], val[3000006];
long long dis[3000006];
bool vis[3000006];
long long what[500005], to[500005][2];

void dij(long long s, long long idx)
{
	for(int i = 1; i <= idx; i++)
	{
		vis[i] = 0;
		dis[i] = 0x3f3f3f3f3f3f3f3f;
	}
	dis[s]=0;
	priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > q;
	q.push({0, s});
	while (! q.empty())
	{
		long long di = q.top().first;
		long long id = q.top().second;
		q.pop();
//		cout << id << endl;
		if (vis[id]) continue;
		vis[id] = 1;
		for (int i = 0; i < edge[id].size(); i++)
		{
			long long nx = edge[id][i];
			long long nd = val[id][i] + di;
			if (nd < dis[nx])
			{
				dis[nx] = nd;
				q.push({nd, nx});
			}
		}
	 } 
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // "\n"
    cin >> c >> n >> m >> d >> q;
    if (c <= 8)
	{
		long long idx = m;
		for (int i = 1; i <= m; i++)
		{
			cin >> sta[i];
		}
//		cout<< m<< endl;
		for (int i = 1; i <= n; i++)
		{
			long long k, y;
			cin >> k;
//				if (i == 400)cout << "?";
			for (int j = 1; j <= k; j++)
			{
				cin >> x[j] >> y;
				idx++;
				edge[x[j]].push_back(idx);
				edge[idx].push_back(x[j]);
				val[x[j]].push_back(y);
				val[idx].push_back(y);
				if (j != 1)
				{
					edge[idx].push_back(idx - 1);
					edge[idx - 1].push_back(idx);
					val[idx].push_back(0);
					val[idx - 1].push_back(0);
				 } 
			}
		}
//		for (int i = 1; i <= idx; i++)
//		{
//			cout << i << ": ";
//			for (int j = 0; j < edge[i].size(); j++)
//			{
//				cout << val[i][j] << " ";
//			}
//			cout << "\n";
//		}
//		cout << idx<< endl;
		for (int i = 1; i <= q; i++)
		{
			long long a, b;
			cin >> a >> b;
			dij(a, idx);
			cout << dis[b] + sta[a] + sta[b] << "\n";
		}
	 } 
	 else
	 {
//	 	cout << "£¿" << endl; 
	 	if (c >= 9 && c <= 11) 
	 	{
			for (int i = 1; i <= m; i++)
			{
				cin >> sta[i];
			}
	//		cout<< m<< endl;
			for (int i = 1; i <= n; i++)
			{
				long long k;
				cin >> k;
				long long o, p, q, r;
				if (k == 1)
				{
					cin >> o >> p;
					continue;
				}
				cin >>o >> p >> q >> r;
				edge[o].push_back(q);
				edge[q].push_back(o);
				val[q].push_back(p + r);
				val[o].push_back(p + r);
			}
//					for (int i = 1; i <= m; i++)
//		{
//			cout << i << ": ";
//			for (int j = 0; j < edge[i].size(); j++)
//			{
//				cout << edge[i][j] << " ";
//			}
//			cout << "\n";
//		}
			for (int i = 1; i <= q; i++)
			{
				long long a, b;
				cin >> a >> b;
				dij(a, m);
				cout << dis[b] + sta[a] + sta[b] << "\n";
			}
		} else
		{
			if (c >= 20 && c <= 21)
			{
				long long hahah = 0x3f3f3f3f3f3f3f3f;
				for (int i = 1; i <= m; i++)
				{
					cin >> sta[i];
				}
				for (int i = 1; i <= n; i++)
				{
					long long k, y;
					cin >> k;
		//				if (i == 400)cout << "?";
					for (int j = 1; j <= k; j++)
					{
						cin >> x[j] >> y;
						if (what[x[j]] == 0) what[x[j]] = i;
						else what[x[j]] = 3;
						to[x[j]][i - 1] = y;
						if (what[x[j]] == 3)
						{
							hahah = min(hahah, to[x[j]][0] + to[x[j]][1]);
						}
					}
				}
//				for (int i = 1;i<= m; i++)
//				{
//					cout<<"k"<<to[i][0] <<" "<<to[i][1]<<endl;
//				}
				for (int i = 1; i <= q; i++)
				{
					long long a, b;
					cin >> a >> b;
					if (a == b)
					{
						cout << "0\n";
						continue;
					}
					if (what[a] == what[b] && what[a] <= 2)
					{
//						cout << "@";
						cout << to[a][what[a] - 1] +to[b][what[b] - 1] + sta[a] + sta[b] << "\n";
					} else
					{
						if (what[a] != what[b] && what[a] <= 2 && what[b] <= 2)
						{
//						cout << "*";
							cout << to[a][what[a] - 1] +to[b][what[b] - 1] + sta[a] + sta[b] + hahah<< "\n";
						} else
						{
							if (what[a] == what[b] && what[a] == 3) 
							{
//							cout << "^";
								cout << min({to[a][0] + to[b][0], to[a][1] + to[b][1], to[a][1] + to[b][0] + hahah, to[a][0] + to[b][1] + hahah}) + sta[a] + sta[b] << "\n"; 
							} else
							{
								if (what[a] != what[b] && what[a] == 3)
								{
//								cout << "&";
									cout << min(to[a][what[b] - 1] + to[b][what[b]- 1], to[a][!(what[b] - 1)] + to[b][what[b] - 1] +hahah) + sta[a] + sta[b] << "\n"; 
								} else
								{
									if (what[a] != what[b] && what[b] == 3)
									{
//									cout << "%";
										cout << min(to[a][what[a] - 1] + to[b][what[a]- 1], to[b][!(what[a] - 1)] + to[a][what[a] - 1] +hahah) + sta[a] + sta[b] << "\n"; 
									}
								}
							}
						}
					}
				}
			}
		} 
	}
    return 0;
}

/*
20 2 5 20 5
4 1 9 2 5
4 1 5 2 7 4 6 5 2
3 2 3 3 4 5 7 
1 4
1 3
2 5
2 4
3 5
*/
