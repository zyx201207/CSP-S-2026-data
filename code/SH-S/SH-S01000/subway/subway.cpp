#include <bits/stdc++.h>
using namespace std;
#define ptt pair <int, int>
#define ll long long 

const int N = 520;
const int M = 5e5 + 10;
const ll INF = 1e16;

int c, n, m, d, q;
int w[M];

vector <ptt> sta[M];
vector <ptt> sub[N];

ll g[N][N];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++)cin >> w[i];
	for(int i = 1; i <= n; i ++){
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; j ++){
			int a, t;
			scanf("%d%d", &a, &t);
			sub[i].push_back(make_pair(a, t));
			sta[a].push_back(make_pair(i, t)); 
		}
	}
	for(int i = 1; i <= n; i ++)for(int j = 1; j <= n; j ++)g[i][j] = INF;
	for(int i = 1; i <= n; i ++){
		for(ptt s : sub[i]){
			for(ptt t : sta[s.first]){
				if(t.first != i)g[i][t.first] = min(g[i][t.first], (ll)s.second + (ll)t.second);
			}
		}
	}
	for(int i = 1; i <= n; i ++)g[i][i] = 0;
	
	/*for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			cout << g[i][j] << " "; 
		}cout << endl; 
	}*/
	
	for(int k = 1; k <= n; k ++){
		for(int u = 1; u <= n; u ++){
			for(int v = 1; v <= n; v ++){
				if(g[u][v] > g[u][k] + g[k][v]){
					g[u][v] = g[u][k] + g[k][v];
				}
			}
		}
	}
	//cout << endl;
	
	/*for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			cout << g[i][j] << " "; 
		}cout << endl; 
	}
	cout << endl;*/
	
	while(q --){
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans = INF;
		for(ptt u : sta[x]){
			for(ptt v : sta[y]){
				ans = min(ans, g[u.first][v.first] + w[x] + w[y] + u.second + v.second);
			}
		}
		printf("%lld\n", ans);
	}
	
	
	return 0;
}
