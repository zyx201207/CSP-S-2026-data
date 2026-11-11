#include <bits/stdc++.h>
using namespace std;
#define int long long
//const int N = 2000010;
int c, n, m, d, q;
int a[3000][3000];
int w[500010];
int k[500010];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i ++){
		cin >> k[i];
		vector<int> vec;
		vector<int> vt;
		for(int j = 1, qq, pp; j <= k[i]; j ++){
			cin >> qq >> pp;
//			cout <<qq;
			vec.push_back(qq);
			vt.push_back(pp);
		}
		for(int ii = 0; ii < k[i]; ii ++){
//			cout << 111;
			for(int j = 0; j < k[i]; j ++){
				a[vec[ii]][vec[j]] = min(((a[vec[ii]][vec[j]] == 0) ? 1145141919 : a[vec[ii]][vec[j]]), vt[ii] + vt[j]);
				a[vec[j]][vec[ii]] = min(((a[vec[j]][vec[ii]] == 0) ? 1145141919 : a[vec[j]][vec[i]]), vt[ii] + vt[j]);
//				cout << a[vec[ii]][vec[j]] << ' ';
			}
//			cout << '\n';
		}
	}
	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= m; j ++){
			for(int k = 1; k <= m - i; k ++){
				a[i][j] = min({((a[j][i + k] == 0) ? 1145141919 : a[j][i + k]) + ((a[i][i + k] == 0) ? 1145141919 : a[i][i + k]), ((a[i][j] == 0) ? 1145141919 : a[i][j])});
				a[j][i] = min({((a[i + k][j] == 0) ? 1145141919 : a[i + k][j]) + ((a[i + k][i] == 0) ? 1145141919 : a[i + k][i]), ((a[j][i] == 0) ? 1145141919 : a[j][i])});
			}
		}
	}
	while(q --){
//		vis.clear();
		int x, y;
		cin >> x >> y;
		cout << a[x][y] + w[x] + w[y] << '\n';
	}
	return 0;
}
//总是要等到考试以后才知道该念的书都没有念~
//上句撤回，会写迪杰斯特拉了 
//32+pts
//歪解解++
