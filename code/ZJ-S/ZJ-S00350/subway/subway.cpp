#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
struct node{
	int a,t;
};
int c,n,m,d,q;
int w[N];
bool vis[N];
vector<int> l[N],a[N];
int t[N][510];
int dist[N];
void bfs(int start,int end)
{
	queue<int> q;
	q.push(start);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = 0; i < a[u].size() ;i ++)
		{
			int v = a[u][i];
			int ti = t[u][v];
			if(vis[v] == false)
			{
				vis[v] = true;
				//cout << l[v].size() << '\n';
				for(int j = 0; j < l[v].size(); j ++)
				{
					int nv = l[v][j];
					if(nv == v) continue;
					dist[nv] = min(dist[nv],dist[u] + ti + t[nv][v]);
					q.push(nv);
					//cout <<dist[u] << "%%%"<< u << "%%%" << v << "%%%" << nv <<"%%%"<< ti <<"%%%" <<t[nv][v] << "%%%"<< dist[nv]<<'\n';
				}
			}
		}
	}
	return;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)
	{
		cin >> w[i];
		dist[i] = 0x3f3f3f3f;
	}
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		for(int j = 1; j <= x; j ++)
		{
			vis[i]= false;
			int b, c;
			cin >> b >> c;
			l[i].push_back(b);
			t[b][i] = c;
			a[b].push_back(i);
		}
	}
//	for(int i = 1; i <= m; i ++)
//	{
//		for(int j = 1; j <= n; j ++)
//		{
//			cout << t[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	for(int i = 1; i <= q; i ++)
	{
		int x,y;
		cin >> x >> y;
		memset(dist,0x3f,sizeof dist);
		memset(vis,0,sizeof vis);
		dist[x] = w[x];
		bfs(x,y);
		dist[y] += w[y];
		cout << dist[y] << '\n';
	}
	return 0;
}
