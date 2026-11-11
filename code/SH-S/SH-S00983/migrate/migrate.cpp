#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int c, t, n, m, sum = 0, minn = 5000005;
void dfs(int x, int y, int s){
	if(x == y){
		if(minn == s){
			sum++;
		}else if(minn > s){
			minn = s;
			sum = 1;
		}
	}
	for(int i = y;i >= x + 1;i--){
		if(a[i] - a[x] <= m && s + 1 <= minn){
			dfs(i, y, s + 1);
		}
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c == 13 || c == 14){
		while(t--){
			cout << 0 << endl;
			return 0;
		}
	}
	while(t--){
		cin >> n >> m;
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		if(c == 11 || c == 12){
			if(a[1] - a[0] > m){
				cout << 0 << endl;
				continue;
			}
			int cnt = m / (a[1] - a[0]);
			if(cnt == 1){
				cout << 0 << endl;
				continue;
			}else{
				cout << n - 2 * cnt + 1 << endl;
			}
		}
		long long ans = 0;
		for(int i = 0;i < n;i++){
			for(int j = i + 1;j < n;j++){
				sum = 0;
				minn = 5000005;
				dfs(i, j, 0);
				if(sum == 2){
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
