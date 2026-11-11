#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5+5,M = 505;
struct edge {int v,w;};
int data_point_type,m,n,maxmt,T,into_val[N],dis[M][M];
vector<edge>meet_subway[N];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> data_point_type >> m >> n >> maxmt >> T;
	for(int i = 1;i <= n;i++) cin >> into_val[i];
	for(int i = 1;i <= m;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			int v,w;
			cin >> v >> w;
			meet_subway[v].push_back({i,w});
		}
	}
	for(int u = 1;u <= m;u++) for(int v = 1;v <= m;v++) dis[u][v] = 1e18;
	for(int u = 1;u <= m;u++) dis[u][u] = 0;
	for(int u = 1;u <= n;u++) for(auto e1:meet_subway[u]) for(auto e2:meet_subway[u]) dis[e1.v][e2.v] = dis[e2.v][e1.v] = min(dis[e1.v][e2.v],e1.w+e2.w);
	for(int mid = 1;mid <= m;mid++) for(int u = 1;u <= m;u++) for(int v = 1;v <= m;v++) dis[u][v] = min(dis[u][v],dis[u][mid]+dis[mid][v]);
	while(T--)
	{
		int u,v,ans = 1e18;
		cin >> u >> v;
		for(auto st_e:meet_subway[u]) for(auto ed_e:meet_subway[v]) ans = min(ans,dis[st_e.v][ed_e.v]+st_e.w+ed_e.w);
		ans += into_val[u]+into_val[v];
		cout << ans << '\n';
	}
	return 0;
}
