#include <iostream>
#include <vector>
#include <cstring>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 7, M = 505;
typedef long long ll;
typedef pair <int, ll> pll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q;
vector <pll> belong[N];
ll dis[M][M], w[N];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		int l; cin >> l;
		for(int j = 1; j <= l; j++){
			int x, v;
			cin >> x >> v;
			belong[x].push_back(make_pair(i, v));
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int i = 1; i <= m; i++){
		for(auto u : belong[i]){
			for(auto v : belong[i]){
				if(u.fi == v.fi) continue ;
				dis[u.fi][v.fi] = min(dis[u.fi][v.fi], u.se + v.se);
				dis[v.fi][u.fi] = min(dis[v.fi][u.fi], u.se + v.se);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int l = 1; l <= n; l++)
			for(int r = 1; r <= n; r++) dis[l][r] = min(dis[l][r], dis[l][i] + dis[i][r]);
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		ll mn = inf;
		for(auto u : belong[x]){
			for(auto v : belong[y]){
				mn = min(mn, u.se + v.se + dis[u.fi][v.fi]);
			}
		}
		cout << mn + w[x] + w[y] << "\n";
	}
	return 0;
}
