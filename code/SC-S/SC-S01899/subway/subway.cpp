#include<bits/stdc++.h>
using namespace std;

const int N = 500 + 10, M = 5e5 + 10;
int c, n, m, d, q;
long long w[M], k[N];

vector<int> a[N], t[N];

vector<pair<int, int>>road[M];
vector<pair<int, int>>G[M];
bool vis[M][N];

long long Min;

int st;

void dfs(const int &ed, int x, long long nowt, int ID, int POS){
	if(x == ed){ // 到达终点
		nowt += t[ID][POS];
		Min = min(Min, nowt);
		return;
	}
	
	if(nowt > Min) return;
	
	if(vis[x][ID]) return;
	vis[x][ID] = true;
	
	for(const pair<int, int> & i : road[x]){ // 换线
		if(x == st){
			if(ID == 0) dfs(ed, x, nowt + t[i.first][i.second], i.first, i.second);
		}
		else if(i.first != ID){ 
			dfs(ed, x, nowt + t[ID][POS] + t[i.first][i.second], i.first, i.second);
		}
	}
	
	for(int i = POS + 1; i <= k[ID]; ++i){ // 向前走
		dfs(ed, a[ID][i], nowt, ID, i);
	}
	for(int i = POS - 1; i >= 1; --i){ // 向后走
		dfs(ed, a[ID][i], nowt, ID, i);
	}
}

int main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	t[0].push_back(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) cin >> w[i];
	for(int i = 1; i <= n; ++i){
		cin >> k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j = 1; j <= k[i]; ++j){
			int x, y;
			cin >> x >> y;
			road[x].push_back({i, j}); // x 是 第 i 路 第 j 站
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	
	while(q--){
		int x, y;
		cin >> x >> y;
		
		st = x;
		
		long long ans = w[x] + w[y];
		Min = 1e18;
		dfs(y, x, 0, 0, 0);
		ans += Min;
		cout << ans << "\n";
		
		for(int i = 0; i <= m; ++i){ 
			for(int j = 0; j <= n; ++j){
				vis[i][j] = false;
			}
		}
	}
	return 0;
}
/*

暴力都写不出来, 先看下一题

15:32 - 16:27

T2

题意
						  (换乘)
地铁口 -> 站厅 -> 站台 -> 站厅 -> 站台... -> 站厅 -> 地铁口

m 个点, 第 i 个点到 进 / 出 站 需要 w[i] 
n 条边, 在 j 出下车 需要 t[i][j]

*/