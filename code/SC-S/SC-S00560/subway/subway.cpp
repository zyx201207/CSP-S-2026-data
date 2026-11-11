#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1050;
struct node{int v, w;};
int c, n, m, d, q, w[N], k[550], A[N], T[N], e[N][550], dis[N][N];
vector<int> a[550], t[550];
priority_queue<int, vector<int>, greater<int> > que;

int x, y;
signed main(){
	freopen("subway4.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			if(i == j) continue;
			dis[i][j] = 1e18;
		}
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", &k[i]);
		for(int j = 1; j <= k[i]; j++){
			scanf("%lld%lld", &A[j], &T[j]);
			a[i].push_back(A[j]);
			t[i].push_back(T[j]);
			e[A[j]][i] = T[j];
		}
		for(int j = 1; j <= k[i]; j++){
			for(int l = 1; l <= k[i]; l++){
				if(j == l) continue;
				dis[A[j]][A[l]] = dis[A[l]][A[j]] = min({dis[A[j]][A[l]], dis[A[l]][A[j]], e[A[j]][i] + e[A[l]][i]});
			}
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			if(i == j) continue;
			for(int l = 1; l <= m; l++){
				if(i == l || j == l) continue;
				dis[i][j] = dis[j][i] = min({dis[i][j], dis[j][i], dis[i][l] + dis[l][j]});
			}
		}
	}
	while(q --){
		scanf("%lld%lld", &x, &y);
		printf("%lld\n", dis[x][y] + w[x] + w[y]);
	}
	return 0;
}