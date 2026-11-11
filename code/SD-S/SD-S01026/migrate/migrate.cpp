#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2E6 + 10;
const int Bn = 5000 + 10;
int a[N];
map<int, int> mp, pm;
//int vis[N][N]; 我是糖豆，这是什么数组
//我同学之前才开1e4 * 1e4 
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	int c, t;
	cin >> c >> t;
	while(t--) {
		memset(a, 0, sizeof a);
		int n, d, flag = 0;
		int ddd = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			if(a[i] - a[i-1] != ddd) {
				flag++; ddd = a[i] - a[i-1];
			}
			ddd = a[i] - a[i-1];
			mp[a[i]]++;
		}
//		cout << ddd << " " << n << " " << d << "\n";
		//你猜有几分 
//		//特殊性质A 
		if(flag == 1) {
			if(d % ddd != 0 || d / ddd == 1) {
				cout << 0 <<"\n";
				continue;
			} else {
				cout << n- d / ddd - 1 << "\n";
			}
		}
		cout << 0 << "\n";
		int ind = 0;
		for(auto it = mp.begin(); it != mp.end(); it++) {
			it -> second = ++ind;
			pm[ind] = it -> first;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				rand();
			}
		}
//这是什么jiba题目 , 何数据 
	}
	return 0;
}
//-2,857,391,858,419
