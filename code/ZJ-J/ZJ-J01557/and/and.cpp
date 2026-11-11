#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, ans;
bool vis[N], a[N][32];
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		int x;
		cin >> x;
		int tot = 0;
		while(x != 0){
			if(x % 2 == 0) a[i][tot ++] = 0;
			else a[i][tot ++] = 1;
			x /= 2;
		}
	}
	for(int j = 30;j >= 0;j --){
		int sum = 0;
		for(int i = 1;i <= n;i ++){
			if(a[i][j] == 1 && vis[i] == 0) {
				sum ++;
			}
		}
		if(sum >= m){
			for(int i = 1;i <= n;i ++){
				if(a[i][j] == 0 && vis[i] != 1) {
					vis[i] = 1;
				}
			}
			ans += (1 << j);
		}
	}
	cout << ans;
    return 0;
}
//2026 csp j/s rp ++;