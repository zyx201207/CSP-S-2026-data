#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 505,M = 5e5 + 5;
int w[M],k[N],t[N][M],ex[M][25],c[N][20005],a[M];
long long dis[M];
vector<pair<int,pair<int,pair<int,int> > > > v[M];
vector<pair<int,int>> g[M];
void bfs(int s)
{
	queue<pair<int,pair<int,pair<int,int>>>> q;
	q.push({s,{0,{0,0}}});
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[s] = 0;
	while(!q.empty())
	{
		pair<int,pair<int,pair<int,int>>> ss = q.front();
		q.pop();
		for(int i = 0;i < v[ss.fi].size();i++)
		{
			pair<int,pair<int,pair<int,int>>> f = v[ss.fi][i];
			int ee = f.fi,ww = f.se.fi;
			if(f.se.se.fi != ss.se.se.fi)
				ww += c[f.se.se.fi][ss.fi];
			if(dis[ee] > dis[ss.fi] + ww)
			{
				dis[ee] = dis[ss.fi] + ww;
				q.push({ee,{t[f.se.se.fi][f.se.se.se],{f.se.se.fi,f.se.se.se}}});
			}
		}
	}
}
void bfs2(int s,int el)
{
	queue<pair<int,int>> q;
	q.push({s,0});
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[s] = 0;
	while(!q.empty())
	{
		bool fl = 0;
		pair<int,int> ss = q.front();
		q.pop();
		for(int i = 0;i < g[ss.fi].size();i++)
		{
			pair<int,int> f = g[ss.fi][i];
			int ee = f.fi,ww = 1;
			if(f.se != ss.se && ss.se != 0)
				ww++;
			if(dis[ee] > dis[ss.fi] + ww)
			{
				dis[ee] = dis[ss.fi] + ww;
				q.push({ee,f.se});
			}
			if(ee == el)
			{
				fl = 1;
				break;
			}
		}
		if(fl)
			break;
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int l,n,m,d,q;
	cin >> l >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	bool f = 1;
	int T;
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		if(k[i] > 2)
			f = 0;
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[j];
			cin >> t[i][j];
			T = t[i][j];
			if(m <= 20000)
				c[i][a[j]] = t[i][j];
			if(j >= 2)
			{
				v[a[j]].push_back({a[j - 1],{t[i][j],{i,j}}});
				v[a[j - 1]].push_back({a[j],{t[i][j - 1],{i,j - 1}}});
				g[a[j]].push_back({a[j - 1],i});
				g[a[j - 1]].push_back({a[j],i});
			}
		}
	}
	if(12 <= l && l <= 19)
	{
		while(q--)
		{
			int x,y;
			cin >> x >> y;
			bfs2(x,y);
			cout << dis[y] * T + w[x] + w[y] << "\n";
		}
	}
	else
	{
		while(q--)
		{
			int x,y;
			cin >> x >> y;
			bfs(x);
			cout << dis[y] + w[x] + w[y] << "\n";
		}	
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
