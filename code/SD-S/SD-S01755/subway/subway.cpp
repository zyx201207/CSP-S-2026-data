#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const string FILE_PRE = "subway";
/*
注意到地铁上的步行用时显然为 0，且各线路不共用站台 
将各线路沿途所有站台缩为一个点，各站厅分别视为一个点，跑最短路，再加 w_x + w_y 
点数 N = O(n+m)
边数 M = O(m+Σk) 
但是看上去绝对会 T。 
把站厅点暂时丢掉，用线路点建图最短路，再加枚举？似乎也不可行。
哦我怎么在 Deepseek 式思考。哦不是豆包式就行。
诶我想想，建图应该是 O(n^2 Σk) 的。
然后 O(n^3) Floyd，O(d^2) 枚举每次询问方案。
哦好像还真是豆包式。 
还是不太行，就这样了。 
*/
int c, n, m, d, q, w[500005];
vector<pair<int, int> > zhantai[500005];
ll dis[505][505];
int main(){
	freopen((FILE_PRE+".in").c_str(), "r", stdin);
	freopen((FILE_PRE+".out").c_str(), "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> c >> n >> m >> d >> q;
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k; cin >> k;
		for(int j = 1; j <= k; j++){
			int a, t; cin >> a >> t;
			for(auto v: zhantai[a])
				dis[v.first][i] = dis[i][v.first] = min(dis[i][v.first], 1ll*t + v.second);
			zhantai[a].push_back({i, t});
		}
		dis[i][i] = 0;
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--){
		int x, y; cin >> x >> y;
		ll ans = LLONG_MAX;
		for(auto u: zhantai[x])
			for(auto v: zhantai[y])
				ans = min(u.second + v.second + dis[u.first][v.first], ans);
		cout << ans + w[x] + w[y] << '\n';
	}
	
	cout << flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 这，这不对吧，要么我复杂度算高了，要么样例掺水了（我个人认为后者可能性更大），本地 0.44s 怎么可能跑 1e11？ 
// 用时：1.0h，期望得分：[68, 92]pts 

// 诶题面锅了？ 
