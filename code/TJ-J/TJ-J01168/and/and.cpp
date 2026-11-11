#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], mx = 0;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	if(m == 1) cout << mx;
	else if(m == n){
		int ans = a[1];
		for(int i = 2; i <= n; i ++){
			ans = ans & a[i];
		}
		cout << ans;
	}else if(m == 2){
		int ans = -1;
		for(int i = 1; i <= n; i ++){
			for(int j = i + 1; j <= n; j ++){
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
	}
	else if(m == n - 1){
		int ans = -1;
		for(int i = 1; i <= n; i ++){
			int tmp;
			if(i == 1) tmp = a[2];
			else tmp = a[1];
			for(int j = 2; j <= n; j ++){
				if(i == 1 && j == 2) continue;
				if(j == i) continue;
				tmp &= a[j];
			}
			ans = max(ans, tmp);
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
