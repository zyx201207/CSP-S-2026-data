#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
long long dp1[N][N];
long long dp2[N][N];
long long a[N];
int ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int k = 1;k <= t;k++){
		int n;
		long long d;
		cin >> n;
		cin >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		for(int i = 1;i < n;i++){
			for(int j = i+1;j <= n;j++){
				if(a[j] - a[j-1] <= d) dp1[i][j] = dp1[i][j-1] + 1;
				if(a[j] - a[i] <= d) dp1[i][j] = 1;
			}
		}
		for(int i = n;i > 1;i--){
			for(int j = n-1;j >= 1;j--){
				if(a[j-1] - a[j] <= d) dp2[i][j] = dp2[i][j-1] + 1;
				if(a[i] - a[j] <= d) dp2[i][j] = 1;
			}
		}
		ans = 0;
		for(int i = 1;i < n;i++){
			for(int j = i+1;j <= n;j++){
				if(dp1[i][j] == dp2[j][i]) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
