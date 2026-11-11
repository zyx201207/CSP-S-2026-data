#include<bits\stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
vector<int> s[N];
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); 
	int c, T;
	cin >> c >> T;
	while (T--){
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++){
			int u, v;
			cin >> u >> v;
			s[u].push_back(v);
			s[v].push_back(u);
		}
		int m = (n-1) / 2;
		if (k == 1){
			cout << (m + 1) / 2 + 1 << endl;
		}
		else if (k < m){
			if (m == 2){
				if (k == 1) cout << 2 << '\n';
				if (k == 2) cout << 1 << '\n';
			}
			else if (m == 3){
				if (k <= 2) cout << 2 << '\n';
				if (k >= 3) cout << 1 << '\n';
			}
			else if (m == 4){
				if (k <= 3) cout << 2 << '\n';
				if (k >= 4) cout << 1 << '\n';
			}
			else if (m == 5){
				if (k <= 4) cout << 2 << '\n';
				if (k >= 5) cout << 1 << '\n';
			}
			else if (m % 4 == 1 || m % 4 == 2){
				int t = (k - 2) / 4;
				int dis = (m / 2) / 2 + 1;
				cout << dis - t<< '\n';
			}
			else {//3 || 0
				int t = k / 4;
				int dis = (m / 2 - 1) / 2 + 1;
				cout << dis - t + 1<< '\n';
			}
		}
		else if (k >= m && k < n){
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	} 
	return 0;
}
