#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int w[500005];
vector<int> vst[500005], wst[500005];
vector<int> vli[505], wli[505];
long long f[505][505];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 0; j < k; j++){
			int a, t;
			cin >> a >> t;
			vli[i].push_back(a);
			wli[i].push_back(t);
			vst[a].push_back(i);
			wst[a].push_back(t);
		}
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < vli[i].size(); j++)
			for (int k = 0; k < vst[vli[i][j]].size(); k++)
				f[i][vst[vli[i][j]][k]] = min(f[i][vst[vli[i][j]][k]], (long long)wli[i][j] + wst[vli[i][j]][k]);
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++)
//			cout << f[i][j] << ' ';
//		cout << '\n';
//	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
//	for (int i = 1; i <= n; i++){
//		for (int j = 1; j <= n; j++)
//			cout << f[i][j] << ' ';
//		cout << '\n';
//	}

	while (q--){
		int x, y;
		cin >> x >> y;
		long long ans = 1e18;
		for (int i = 0; i < vst[x].size(); i++)
			for (int j = 0; j < vst[y].size(); j++){
//				cout << "from line " << vst[x][i] << " to " << vst[y][j] << ", cost: " << f[vst[x][i]][vst[y][j]] + wst[x][i] + wst[y][j] << '\n';
				ans = min(ans, f[vst[x][i]][vst[y][j]] + wst[x][i] + wst[y][j]);
			}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}

