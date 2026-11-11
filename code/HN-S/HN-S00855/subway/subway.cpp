#include<bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second 

int read(){
	int val = 0, ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)){
		val = (val << 3) + (val << 1) + (ch ^ 48);
		ch = getchar();
	}
	return val;
}

using namespace std;

const int MAXM = 5e5 + 5, MAXN = 505;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q;

int l[MAXN], w[MAXM];
ll dis[MAXN][MAXN];

vector<pii> lk[MAXM];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++) w[i] = read();
	for(int i = 1, x, t; i <= n; i++){
		l[i] = read();
		for(int j = 1; j <= l[i]; j++){
			x = read(), t = read();
			lk[x].push_back({i, t});
		}
	}
	memset(dis, INF, sizeof(dis));
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int p = 1; p <= m; p++){
		int len = lk[p].size();
//		cout << len << '\n';
		for(int i = 0; i < len; i++){
			int x = lk[p][i].fi;
			for(int j = 0; j < i; j++){
				int y = lk[p][j].fi;
				if(p == 2){
//					cout << x << ' ' << y << '\n';
				}
				dis[y][x] = dis[x][y] = min(dis[x][y], (ll)lk[p][i].se + lk[p][j].se);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			if(i == k) continue;
			for(int j = 1; j <= n; j++){
				if(j == i || j == k) continue;
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--){
		int x = read(), y = read();
		ll ans = INF;
		for(int i = 0; i < lk[x].size(); i++){
			int a = lk[x][i].fi;
			for(int j = 0; j < lk[y].size(); j++){
				int b = lk[y][j].fi;
				ans = min(ans, dis[a][b] + lk[x][i].se + lk[y][j].se);
			}
		}
//		cout << dis[1][2] << '\n';
		printf("%lld\n", ans + w[x] + w[y]);
	}

	return 0;
}

