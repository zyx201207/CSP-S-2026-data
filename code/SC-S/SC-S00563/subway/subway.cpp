#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x * 10) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
void write(int x){
	if(x < 0){putchar('-');x = -x;}
	if(x > 9)write(x / 10);
	putchar(x % 10 + '0');
}

const int MAX_N = 505, MAX_M = 5e5 + 5, max_num = 1e18; 
int C, N, M, D, Q, K, a, t;
int w[MAX_M];
int ans, dis[MAX_N][MAX_N];
vector<pair<int, int>>node[MAX_M];

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	C = read(); N = read(); M = read(); D = read(); Q = read();
	for(int i = 1;i <= N;i ++)
		for(int j = 1;j <= N;j ++){
			if(i == j) dis[i][j] = 0;
			else dis[i][j] = max_num;
		}
	for(int i = 1;i <= M;i ++)
		w[i] = read();
	for(int i = 1;i <= N;i ++){
		K = read();
		for(int j = 1;j <= K;j ++){
			a = read(); t = read();
			for(auto y : node[a]){
				int id = y.first, t_id = y.second;
				dis[id][i] = dis[i][id] = min(dis[id][i], t_id + t);
			}
			node[a].push_back({i, t});
		}
	}
	for(int i = 1;i <= N;i ++){
		for(int j = 1;j <= N;j ++){
			if(i == j)continue;
			for(int k = 1;k <= N;k ++){
				if(i == k || j == k) continue;
				dis[i][j] = dis[j][i] = min(dis[i][k] + dis[k][j], dis[i][j]);
			}
		}
	}

	for(int i = 1, x, y;i <= Q;i ++){
		x = read(); y = read();
		ans = max_num;
		for(auto u : node[x])
			for(auto v : node[y])
				ans = min(dis[u.first][v.first] + u.second + v.second, ans);
		ans = ans + w[x] + w[y];
		write(ans);
		putchar('\n');
	}
	return 0;
}