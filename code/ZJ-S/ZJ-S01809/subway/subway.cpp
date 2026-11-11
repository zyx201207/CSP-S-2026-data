#include <bits/stdc++.h>
#define int long long
#define M 500050
#define N 550
#define Q 100050
#define V 2000050
#define D 30
using namespace std;
int c, n, m, d, q;
int w[M], l[N];
int lk[N][N];
struct edge{
	int id, s;
};
vector<edge> e[M]; // the list of routes which visit point M
//void add(int u, int v, int length){
//	to[++ cnt] = v;
//	nxt[cnt] = h[u];
//	h[u] = cnt;
//	len[cnt] = length;
//}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for(int k = 1;k <= n;k ++){
//		scanf("%lld", &l[k]);
		cin >> l[k];
		for(int i = 1, v, length;i <= l[k];i ++){
//			scanf("%lld %lld", &v, &length);
			cin >> v >> length;
			edge tmp;tmp.id = k;tmp.s = length;
			e[v].push_back(tmp); //point v was visited by route k
		}
	}
	memset(lk, 0x3f, sizeof(lk));
	for(int i = 1;i <= n;i ++) lk[i][i] = 0;
	for(int i = 1;i <= m;i ++){
		for(int j = 0;j < e[i].size();j ++){
			for(int k = 0;k < e[i].size();k ++){
				lk[e[i][j].id][e[i][k].id] = min(lk[e[i][j].id][e[i][k].id], 
												 e[i][j].s + e[i][k].s);
			}
		}
	}
	for(int k = 1;k <= n;k ++){
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= i;j ++){
				if(lk[i][k] + lk[k][j] < lk[i][j]){
					lk[i][j] = lk[i][k] + lk[k][j];
				}
				lk[j][i] = lk[i][j];
			}
		}
	}
//	for(int i = 1;i <= m;i ++){
//		for(int j = 0;j < e[i].size();j ++){
//			cout << i << " " << e[i][j].id << " " << e[i][j].s << endl;
//		}
//	}
//	for(int i = 1;i <= n;i ++){
//		for(int j = 1;j <= n;j ++){
//			cout << lk[i][j] << ' ';
//		}
//		cout << endl;
//	}
	while(q --){
		int x, y, ans = 1e18;
//		scanf("%lld %lld", &x, &y);
		cin >> x >> y;
		for(int i = 0;i < e[x].size();i ++){
			for(int j = 0;j < e[y].size();j ++){
				ans = min(ans, 
						  lk[e[x][i].id][e[y][j].id] + e[x][i].s + e[y][j].s);
			}
		}
//		printf("%lld", ans + w[x] + w[y]);
		cout << ans + w[x] + w[y] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
*/
