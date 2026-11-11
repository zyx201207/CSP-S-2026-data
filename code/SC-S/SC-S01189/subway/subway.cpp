#include<bits/stdc++.h>
using namespace std;


int main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false),cin.tie(0);
	int c, n, m, d, q;cin >> c >> n >> m >> d >> q;
	vector<int> M(m + 1);
	for(int i = 1;i <= m; i++) cin >> M[i];
	/*；接下来2ki个正整数为ai,1,ti,1,ai,2,ti,2,...,ai,ki
	,ti,ki
	，其
	中ai,j 表示第 i 条线路经过的第j 个地铁站，ti,j 表示从第 i 条线路经过的第j 个地铁站的站厅走到第i条线
	路的站台需要的时间*/
	int t;
	vector<vector<int>> A(n + 1), G(m + 1);
	for(int l = 1;l <= n; l++){
		int k;cin >> k;
		A[l].resize(k + 1);
		for(int j = 1;j <= k; j++){
			cin >> A[l][j] >> t;
			if(j == 1) continue;
			G[A[l][j - 1]].push_back(A[l][j]);
			G[A[l][j]].push_back(A[l][j - 1]);
			
		}
	}
	
	
	t *= 2;
	struct OP{
		int Z, L, F;
	};
	while(q--){
		int x, y;cin >> x >> y;
		int ans = M[x] + M[y];
		
		queue<OP> Q;
		Q.push({x, 0, -1});
		while(!Q.empty()){
			
			OP now = Q.front();
			Q.pop();
			
			if(now.Z == y){
				ans += t * now.L;
				break;
			}
			for(int v : G[now.Z]){
				if(v == now.F) continue;
				Q.push({v, now.L + 1, now.Z});
			}
			
		}
		cout << ans << '\n';
	}
	
	
	
	// 0 2 5 20 2 4 1 9 2 5 3 1 5 2 7 4 6 3 2 3 3 4 5 7 1 3 1 2
	
	/*
	0 2 5 20 2
	4 1 9 2 5
	3 1 5 2 7 4 6
	3 2 3 3 4 5 7
	1 3
	1 2
	*/
	
	return 0;
}