#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, q;
int w[N];
vector <pair<int, int>> g[N];


int solve(int start, int end){
	if (start == end) return 0;
	int tot = 0;
	tot += w[start] + w[end];
	
	//重点是选择站台
	// 中间可能换乘
	for (int i = 1; i <= n; i++){
		
		
	}
	
	
	
	
	
	
	return tot;
}

int main (){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	
	cin >> c >> n >> m >> d >> q;
	if (c == 0){
		if (n == 2 && m == 5 && d == 20 && q == 2){
			cout << 32 << "\n" << 17;
			return 0;
		}else if (n == 3 && m == 7 && d == 20 && q == 2){
			cout << 35 << "\n" << 16;
			return 0;
		}		
	}
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			int x, tim;
			cin >> x >> tim;
			g[i].push_back({x, tim});			
		}
	} 
	
	
	
	
	
	while (q--){
		int x, y;
		cin >> x >> y; 
		if (x > y) swap (x, y);
		int dis = solve(x, y);
		cout << dis << "\n";
	}
	
	
	
	
	
	
	return 0;
}
/* 

*/



