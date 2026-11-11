#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
const int INF=2147483647;
int tu[510][MAXN] ;
int w[MAXN];
int minn[510][510];
int c, n, m, d, q ;
void solve(){
	cin >> c >> n >> m >>d >> q ;
	for (int i=1;i<=n ; i ++) {
		for (int j = 1 ; j <= n ; j ++) {
			minn[i][j] = INF;
		}
	}
	for (int i = 1 ;i <= m;i ++) {
		cin >> w[i] ;
	}
	for (int i = 1;i <= n ; i ++) {
		int ki ; cin >>ki ;
		for (int j=1;j<=ki;j++) {
			int dx,kx;cin >> dx >> kx ;
			tu[i][dx] = kx ;
			if(tu[i - 1][dx]) {
				minn[i - 1][i] = minn[i][i - 1] = min(minn[i - 1][i], tu[i - 1][dx] + tu[i][dx]) ;
			}
		}
	}
	for (int i = 1 ; i <= n;i++) {
		minn[i][i]= 0 ;
	}
	for (int i = 1 ;i<= q; i ++) {
		int xr,yr;cin>>xr >>yr;
		int min_ans = INF;
		for (int j = 1;j<=n;j++){
			for (int k= 1;k<=n;k++){
				if(tu[j][xr]&&tu[k][yr]){
					bool pan = true;
					int sum = 0 ;
					for (int l = min(j,k) ; l <= max(j, k) - 1 ; l ++) {
						if(minn[l][l + 1] == INF) {
							pan = false ;
							break ;
						}
						sum += minn[l][l + 1] ;
					}
					if(pan) {
						min_ans = min(sum + tu[j][xr] + tu[k][yr] + w[xr] + w[yr],min_ans) ;
					}
				}
			}
		}
		cout << min_ans << "\n" ;
	}
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	freopen("subway.in", "r", stdin) ;
	freopen("subway.out", "w", stdout) ;
	int t = 1 ;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}