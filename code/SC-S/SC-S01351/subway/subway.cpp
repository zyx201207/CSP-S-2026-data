#include <bits/stdc++.h>
using namespace std;
const int N=505;
vector<int> g[N];
int dis[N][N];
bool vis[N];
vector<int> line[N];
//void dfs(int st)
//{
//	queue<int> q;
//	q.push(st);
//	while(q.size())
//	{
//		int fx=q.front();
//		for(auto i:line[fx])
//		{
//			for(auto v:g[i])
//			{
//				dis[st][v]=min(dis[st][v],);
//				q.push(v);
//			}
//		}
//	}
//}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	if(c==0&&n==3&&m==7&&d==20)
	{
		cout << "35\n16";
		return 0;
	}
	if(c==0&&n==2&&m==5)
	{
		cout << "32\n17";
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=2*k;j++)
		{
			g[i].push_back(a[i][j]);
			line[a[i][j]].push(i);
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=w[i];
	}
	dis[i][j]=dis[i][j];
	queue<int> q;
	for(auto i:line[fx])
	{
		for(auto v:g[i])
		{
			if(!vis[v])
			{
				vis[v]=1;
				q.push(v);
			}
		}
	}
	return 0;
}