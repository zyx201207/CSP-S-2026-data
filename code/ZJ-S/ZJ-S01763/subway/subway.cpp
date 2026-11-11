#include<iostream> 
#include<algorithm> 
#include<vector> 
#include<queue> 
#define pll pair<long long,long long> 
using namespace std; 
int cid,n,m,D,Q; 
long long a[500005],d[505][505],vis[505]; 
struct stu 
{ 
	long long x,y; 
}; 
vector<stu>b[500005],v[505]; 
priority_queue<pll,vector<pll>,greater<pll> >q; 
void dij(int st) 
{ 
	for(int i = 1;i <= n;i++) d[st][i] = 1e18,vis[i] = 0; 
	q.push({0,st}); d[st][st] = 0; 
	while(!q.empty()) 
	{ 
		int x = q.top().second; q.pop(); 
		if(vis[x]) continue; 
		vis[x] = 1; 
		for(auto w : v[x]) 
		{ 
			long long y = w.x,z = w.y; 
			if(d[st][y] > d[st][x] + z) 
			{ 
				d[st][y] = d[st][x] + z; 
				q.push({d[st][y],y}); 
			}
		}
	}
}
int main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> cid >> n >> m >> D >> Q;
	for(int i = 1;i <= m;i++) cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			int x,y;
			cin >> x >> y;
			b[x].push_back({i,y});
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int w1 = 0;w1 < (int)b[i].size();w1++)
		{
			long long x = b[i][w1].x,z = b[i][w1].y;
			for(int w2 = w1 + 1;w2 < (int)b[i].size();w2++)
			{
				long long y = b[i][w2].x,zz = b[i][w2].y;
				v[x].push_back({y,z + zz});
				v[y].push_back({x,z + zz});
			}
		}
	}
	for(int i = 1;i <= n;i++) dij(i);
	while(Q--)
	{
		int x,y;
		cin >> x >> y;
		long long ans = 1e18;
		for(auto w1 : b[x])
		{
			for(auto w2 : b[y])
			{
				ans = min(ans,a[x] + w1.y + d[w1.x][w2.x] + w2.y + a[y]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}