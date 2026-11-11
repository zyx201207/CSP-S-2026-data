#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;

int C, n, m, d, Q;
int w[500010];
struct node{ int v; ll c;};
vector<node>a[500600];
priority_queue<PLL, vector<PLL>, greater<PLL> > q;
ll dis[500600]; bool vis[500600];
vector<int>f[500010];

void solve()
{
	cin >> C >> n >> m >> d >> Q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		int K; cin >> K;
		for(int j = 1; j <= K; j++)
		{
			int A, T; cin >> A >> T;
			a[i + m].push_back({A, T});
			a[A].push_back({i + m, T});
			f[A].push_back(i + m);
		}
	}
	for(int cq = 1; cq <= Q; cq++)
	{
		ll ANS = 1e18; 
		int l, r; cin >> l >> r;
		for(int fst = 0; fst < f[l].size(); fst++)
		{
			for(int fnd = 0; fnd < f[r].size(); fnd++)
			{
				ll fl = f[l][fst], fr = f[r][fnd];
				memset(dis, 127, sizeof(dis));
				memset(vis, 0, sizeof(vis));
				ll ans = w[l] + w[r];
				if(fl == fr)
				{
					int cnt = 0;
					for(int i = 0; i < a[fl].size(); i++)
					{
						if(a[fl][i].v == l)
						{
							ans += a[fl][i].c;
							cnt++;
						} 
						if(a[fl][i].v == r)
						{
							ans += a[fl][i].c;
							cnt++;
						}
						if(cnt == 2) break;
					}
				}
				else
				{
					q.push({0, fl});//f[i]地铁站，i地铁线路 
					dis[fl] = 0;
					while(!q.empty())
					{
						int x = q.top().second;
						q.pop();
						if(vis[x]) continue;
						vis[x] = 1;
						for(int i = 0; i < a[x].size(); i++)
						{
							int y = a[x][i].v; ll yd = a[x][i].c;
							if(dis[x] + yd < dis[y])
							{
								dis[y] = dis[x] + yd;
								q.push({dis[y], y});
							}
						}
					}
					ans += dis[fr]; 
					for(int i = 0; i < a[fl].size(); i++)
						if(a[fl][i].v == l)
						{
							ans += a[fl][i].c;
							break; 
						} 
					for(int i = 0; i < a[fr].size(); i++)
						if(a[fr][i].v == r)
						{
							ans += a[fr][i].c;
							break;
						}
				}
				ANS = min(ANS, ans);
			}
		}
		cout << ANS << '\n';
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	solve();
	return 0;
}

