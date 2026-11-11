#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, c, d, q, w[500005];
vector <pair<int, int>> v[505];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
		//cout << w[i] << ' ';
	}
	for(int i = 1; i <= n; i++){
		int k, x, y;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> x >> y;
			v[i].push_back({x, y});
		}
	}
	for(int i = 1; i <= q; i++){
		int st, ed;
		cin >> st >> ed;
		for(int j = 1; j <= n; j++){
			bool flag = 0, flag1 = 0;
			for(int k = 0; k < v[j].size(); k++){
				//cout << v[j][k].first << ' ' << v[j][k].second << "                ";
				if(v[j][k].first == st){
					flag = 1;
				}else if(v[j][k].first == ed){
					flag1 = 1;
				}
			}
			if(flag && flag1){
				cout << w[st] + w[ed] + v[j][st - 1].second + v[j][ed - 1].second ;//<< ' ' << w[ed] <<  ' ' << w[st] << ' ' << v[j][st - 1].second << ' ' << v[j][ed - 1].second << endl;
				break;
			}
		}
	}
	return 0;
}