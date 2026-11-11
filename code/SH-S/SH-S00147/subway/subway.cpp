#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 500005;

int w[N];
vector<PII> G[N];
int c, n, m, d, q;
int ans;
// -; 线路数，站数，最多多少线路经过，出行计划数 

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++){
		cin >> w[i];
		ans += w[i];
	}
	
	for (int i = 1; i <= n; i++){  // 第i条线路 
		int k;
		cin >> k;
		
		for (int j = 1; j <= k; j++){
			int ai, ti;
			cin >> ai >> ti;
			ans += ti;
			G[i].push_back({ai, ti});
		}
	}
	
	for (int i = 1; i <= q; i++){
		int s, e;
		cin >> s >> e;
	}
	
	cout << ans << endl;
	
	return 0;
}
