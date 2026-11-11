#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 300;
int c, t;
int x[maxn], dis[maxn][maxn][maxn], cnt[maxn][maxn][maxn];

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		int n, d; cin >> n >> d;
		for(int i = 1;i<=n;i++) cin >> x[i];
		memset(dis, 0x3f, sizeof dis);
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				dis[0][i][j] = (x[j]-x[i]<=d)?1:4e18;
				cnt[0][i][j] = (x[j]-x[i]<=d)?1:0;
			}
		}
		for(int k = 1;k<=n;k++){
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++){
					dis[k][i][j] = dis[k-1][i][j];
					cnt[k][i][j] = cnt[k-1][i][j]; 
				}
			}
			for(int i = 1;i<=n;i++){
				for(int j = 1;j<=n;j++){
					int a = dis[k][i][j], b = dis[k-1][i][k] + dis[k-1][k][j];
					if(a==b){
						cnt[k][i][j] +=cnt[k-1][i][k] * cnt[k-1][k][j];
					}
					if(a>b){
						dis[k][i][j] = dis[k-1][i][k] + dis[k-1][k][j];
						cnt[k][i][j] = cnt[k-1][i][k] * cnt[k-1][k][j];
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(2 == cnt[n][i][j]) ans++;
				//cout << cnt[n][i][j] << " " ;
			}
			//cout << endl;
		}
		cout << ans << endl; 
	}
}

