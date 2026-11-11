#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 +100;
int f[400][400];
int x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin >> c >> t;
	if(c <= 25){
		while(t--){
			int n,d;
			cin >> n >> d;
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					f[i][j] = 1e18;
				}
			}
			for(int i = 1;i <= n;i++){
				cin >> x[i];
				int p = i - 1;
				while(p >= 1&& x[i]-x[p] <= d){
					f[i][p] = f[p][i] = 1;
					p--;
				}
			}
			for(int k = 1;k <= n;k++){
				for(int i = 1;i <= n;i++){
					for(int j = 1;j <= n;j++){
						if(f[i][k] + f[k][j] < f[i][j]){
							f[i][j] = f[i][k] + f[k][j];
						}
					}
				}
			}
			int ans =0;
			for(int i = 1;i <= n;i++){
				for(int j =i + 2;j <= n;j++){
					int cnt = 0;
					for(int k = i + 1 ;k < j;k++){
						if(f[i][j] == f[i][k] + f[k][j]) cnt++;
					}
					if(cnt == 2) ans++;
				}
			}
			cout << ans <<"\n";
		}
	}
	
	return 0;
}
