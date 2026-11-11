#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,,d,q,c,w[500005],t[505][500005],a[505][500005],x[500005],y[500005]l,dis[500005],k[505];
struct Edge{
    int p,w;
};
vector<Edge> e[500005];
void dijkstra(int s)
{
	memset(dis,0x3f,sizeof(dis));
	ll now = s;
	for(int i = 0;i < e[s].size();i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(dis[j] >= 1e12)
			{
				now = j;
				break;
			}
		}
		for(int j = 0;j <= e[now].size();j++)
		{
			if(dis[now] + e[s][i].p < dis[e[now][j]])
			{
				dis[now] + e[s][i].p = dis[e[now][j]];
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)	
	{
		cin >> w[i];
	}	
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= k[i];j++)
		{
			for(int l = 1;l <= k[i];l++)
			{
				e[a[i][j]].push_back(a[i][l],t[i][j]);
				e[a[i][l]].push_back(a[i][j],t[i][j]);
			}
		}
	}
	for(int r = 1;r <= q;i++)
	{
		cin >> x[r] >> y[r];
		dijkstra(x[r]);
		cout << dis[y[r]] << endl;
	}
	return 0;
}
