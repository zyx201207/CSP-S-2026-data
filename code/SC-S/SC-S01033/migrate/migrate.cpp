#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int x[N];
 int d;
int solve(int l, int r){
	for(int i = l + 1; i <= r; i++){
		if(x[i] - x[i - 1] > d){
			return 0;
		}
	}
	int cnt = 0;
	for(int k = l + 1; k < r; k++){
		if(x[k] - x[l] <= d && x[r] - x[k] <= d) cnt++;
		if(cnt > 2){
			return 0;
		}
	}
	return 1;
}
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		//A
		bool hasa = 1;
		int sum = x[2] - x[1];
		for(int i = 3; i <= n; i++){
			if(x[i] - x[i - 1] != sum) hasa = 0;
		}
		if(hasa){
			if(sum > d || d - sum < sum || x[n] - x[1] <= d){
				cout << "0\n";
				continue;
			}
			int mx = d / sum;
			if(mx == 2){
				cout << n - 3 << "\n";
				continue;
			}else{
				int mx1 = n - 2 * mx + 1;
				cout << mx1 << "\n";
				continue;
			}
		}else{
			int ans = 0;
			for(int i = 1; i <= n; i++){
				for(int j = i + 1; j <= n; j++){
					if(x[j] - x[i] < d){
						continue;
					}
					ans += solve(i, j);
				}
			}
			cout << ans << "\n";
		}
		
	}
	return 0;
}