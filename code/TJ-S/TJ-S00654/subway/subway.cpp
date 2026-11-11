#include<bits/stdc++.h>
using namespace std;
const int M = 4e5 + 5;
struct node{
	int v;
	bool friend operator<(node x, node y){
		return x.v > y.v;
	}
};
struct AT{
	int a, t;
}at[505][M];
priority_queue<node> pq;
int c, n, m, d, q, w[M], k[M];
vector<int> e[M];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++){
			cin >> at[i][j].a >> at[i][j].t;
		}
	}
	for(int i = 1; i <= q; i ++){
		long long ans = 0;
		int x, y;cin >> x >> y;
		ans = w[x] + w[y];
		queue<int> q;
		cout << ans << endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
