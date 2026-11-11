#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5; //好像开不到2e6！？！？！？

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int c, t;
	cin >> c >> t;

	while (t--) {
		int n;//数目
		long long d;//步长
		long long x[N] = {}; //坐标
		vector<int>g1[N];//一级
		int z[N];

		cin >> n >> d;

		for (int i = 1; i <= n; ++i) { //输入+一级

			cin >> x[i];

			for (int j = i - 1; j >= 1; --j) {

				if (x[j] + d < x[i]) {
					z[j] = i - 1;
					break;
				}

				z[j] = i;
				g1[j].push_back(i);//j--(1)-->i
			}

		}

		int ans = 0;

		for (int i = 1; i <= n; ++i) {

			if (g1[1].size() == 0)
				continue;
			/*
			一级为(all)g1[i1][j1]也是二级的"i"
			=>二级(all)g1[ g1[i1][j1] ][j2]
			*/
			vector<int>g2;
			map<int, long long>mp;

			for (int j = 0; j < g1[i].size(); ++j) { //二级（单个）

				int u1 = g1[i][j];

				for (int k = 0; k < g1[u1].size(); ++k) {

					int u2 = g1[u1][k];
					mp[u2] += 1;

					if (mp[u2] == 1) {
						g2.push_back(u2);//i--(2)-->u2
					}
				}
			}

			for (int j = 0; j < g2.size(); ++j) { //寻找为2的

				if (mp[g2[j]] == 2 && g2[j] > z[i]) {
					ans += 1;
//cout<<i<<"->"<<g2[j]<<' '<<z[i]<<' '<<mp[g2[j]]<<'\n';
				}
			}
		}

		cout << ans << '\n';

	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
