#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using u32 = int;

using i128 = __int128;
using u128 = unsigned __int128;

#ifdef ZYX2012_DUIPAI
mt19937_64 mrand(random_device{}());
i64 rnd(i64 l,i64 r){
	return mrand() % (r - l + 1) + l;
}
#endif

int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	//站多线少啊，我还以为n个站m条线呢
	//那还说啥了，直接去算站与站中间的距离一个Floyd然后枚举
	int tid,n,m,d,q;
	cin >> tid >> n >> m >> d >> q;

	vector<i64> w(m + 1);

	for (int i = 1;i <= m;cin >> w[i++]);

	vector<vector<int>> a(n + 1);
	vector<vector<pair<int,i64>>> c(m + 1);
	vector<vector<i64>> dis(n + 1,vector<i64>(n + 1,1e18));

	for (int i = 1;i <= n;i++){
		int k;
		cin >> k;

		a[i].resize(k);
		dis[i][i] = 0;

		for (auto &j:a[i]){
			int t;
			cin >> j >> t;
			c[j].emplace_back(i,t);
		}
	}

	for (int i = 1;i <= m;i++){
		int sz = c[i].size();
		for (int j = 0;j < sz;j++) for (int k = j + 1;k < sz;k++)
			dis[c[i][j].first][c[i][k].first] = min(dis[c[i][j].first][c[i][k].first],c[i][j].second + c[i][k].second);
	}

	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			dis[i][j] = dis[j][i] = min(dis[i][j],dis[j][i]);

	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			for (int k = 1;k <= n;k++)
				dis[j][k] = min(dis[j][k],dis[j][i] + dis[i][k]);

	for (;q--;){
		int x,y;
		cin >> x >> y;

		i64 ans = 1e18;

		for (auto i:c[x]) for (auto j:c[y]) ans = min(ans,i.second + dis[i.first][j.first] + j.second);

		cout << ans + w[x] + w[y] << '\n';
	}
}