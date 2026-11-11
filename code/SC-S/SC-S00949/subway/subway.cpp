#include<bits/stdc++.h>
using namespace std;

const long long MAXX = 1e6 + 105;
const long long NN = 5 * 1e5 +6;
int c,n,m,d,q;
int w[MAXX],xr[MAXX],yr[MAXX],k[MAXX],a[500][NN],t[500][NN];
int tsa,tsb;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	int r = q;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= r;i ++){
		cin >> k[i];
		if(k[i] > 2) tsa += 1;
		for(int j = 1;j <= k[i];j ++) cin >> a[i][j] >> t[i][j];
	}
	int T = t[1][1];
	for(int i = 1;i <= r;i ++) for(int j = 1;j <= k[i];j ++) if(t[i][j] != T) tsb += 1;
	for(int i = 1;i <= r;i ++) cin >> xr[i] >> yr[i];

	if(tsa == 0){
		for(int i = 1;i <= r;i ++){
			long long time = 0;
			int cf = xr[i],zd = yr[i];
			while(true){
				if(cf == zd) break;
				for(int j = 1;j <= n;j ++){
					if(a[j][1] == cf){
						time += t[j][1];
						cf = a[j][2];
						break;
					}
					else if(a[j][2] == cf){
						time += t[j][2];
						cf = a[j][1];
						break;
					}
					
				}
			}
			cout << time << "\n";
		}
		return 0;
	}
	else{
		for(int i = 1;i <= r;i ++){
			int dp[5000][5000];
			long long time = 0;
			int cf = xr[i],zd = yr[i];
		while(true){
			if(cf == zd) break;
			for(int j = 1;j <= n;j ++){
					for(int l = 1;l <= k[i];l ++){
						dp[j][l] =min(dp[j + 1][l],dp[j][l] + 2);
					}
				}
			}
			time = dp[cf][zd];
			cout << time << "\n";
		}
		return 0;
	}
	return 0;
}