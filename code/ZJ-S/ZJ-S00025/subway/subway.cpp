#include<bits/stdc++.h>
using namespace std;
const int MAXX=100005;
int c,n,m,d,q;
int vis[MAXX],cur[MAXX],s[20];
struct node
{
	int u,w;
	bool operator<(const node&a) const
	{
		return w<a.w;
	}
};
vector<int> edge[MAXX];
vector<int> dis[MAXX];
int a[505],b[505];
void dij(int s)
{
	memset(cur,0x3f,sizeof(cur));
	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	q.push({s,0});
	cur[s]=0;
	while(!q.empty())
	{
//		cout << "**********";
		int u=q.top().u;
		q.pop();
		if(vis[u]==1)
		{
			continue;
		}
		for(int i=0;i<edge[u].size();i++)
		{
			int v=dis[u][i],w=edge[u][i];
//			cout << v << " " << w << endl;
			if(cur[v]>cur[u]+w)
			{
				cur[v]=cur[u]+w;
				q.push({v,cur[v]});
			}
		}
		vis[u]=1;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> s[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int g;
		cin >> g;
		for(int j=1;j<=g;j++)
		{	
			cin >> a[j] >> b[j];
			for(int k=1;k<j;k++)
			{
//				cout << "***********" << endl;
				int u=a[j],v=a[k];
//				cout << b[k] << endl; 
//				cout << edge[u].size() << " ";
				edge[u].push_back(b[j]+b[k]);
				edge[v].push_back(b[j]+b[k]);
				dis[u].push_back(v);
				dis[v].push_back(u);
			} 
		}
//		cout << "**" << edge[1].size();
//		 cout << endl;
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		cout << edge[i].size();
//		for(int j=0;j<edge[i].size();j++)
//		{
//			cout << edge[i][j] << " ";
//		}
//		cout << endl;
//	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		dij(x);
		cout << cur[y]+s[x]+s[y] << "\n";
	}
}



/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/                    