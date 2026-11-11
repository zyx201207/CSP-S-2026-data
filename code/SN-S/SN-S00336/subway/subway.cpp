// 西安市铁一中学 王正清和 SN-S00336
#include<bits/stdc++.h>
#define fir first
#define sec second
#define mkp make_pair
#define ll long long
using namespace std;
int byx, aqx = 1;

const ll infll = 1000000000000000010ll;
const int maxm = 500000;
int cas, n, m, o, q, W[maxm + 10];
ll F[510][510];
vector<pair<int, int> > V[maxm + 10];
void upd(ll& x, ll y)
{
	if (y < x) x = y;
}
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
void wangzqh()
{
	cin >> byx >> n >> m >> o >> q;
	for (int i = 1;i <= m;i++) cin >> W[i];
	for (int i = 1;i <= n;i++)
	{
		int k; cin >> k;
		while (k--)
		{
			int a, t; cin >> a >> t;
			V[a].push_back(mkp(i, t));
		}
	}
	
	for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++) F[i][j] = infll;
	for (int i = 1;i <= n;i++) F[i][i] = 0;
	for (int i = 1;i <= m;i++) 
	{
		int sz = V[i].size();
		for (int a = 0;a < sz;a++) for (int b = 0;b < sz;b++)
			upd(F[V[i][a].fir][V[i][b].fir], V[i][a].sec + V[i][b].sec);	
	}
	
	for (int k = 1;k <= n;k++) for (int i = 1;i <= n;i++) for (int j = 1;j <= n;j++)
		upd(F[i][j], F[i][k] + F[k][j]);
		
	while (q--)
	{
		int u, v; cin >> u >> v;
		int szu = V[u].size(), szv = V[v].size(); ll ans = infll;
		for (int a = 0;a < szu;a++) for (int b = 0;b < szv;b++) 
			upd(ans, F[V[u][a].fir][V[v][b].fir] + V[u][a].sec + V[v][b].sec);
		ans += W[u] + W[v]; cout << ans << "\n";
	}
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	init();
	aqx = 1;
	while (aqx--) wangzqh();
	return 0;
}

