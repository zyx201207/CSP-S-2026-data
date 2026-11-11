#include<bits/stdc++.h>
using namespace std;
#define N 2000005
int c,t,x[N],qzh[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c == 11 || c == 12){
		while(t--){
			int n,d;
			cin >> n >> d;
			for(int i = 1;i <= n;i++)
				cin >> x[i];
			int ke = d/(x[2]-x[1]);
			if(ke == 1 || n+1-2*ke <= 0)
				cout << 0 << '\n';
			else{
				cout << n+1-2*ke << '\n';
			}
		}
	}
	else if(c == 1 || c == 2){
		while(t--){
			int n,d,cnt = 0;
			memset(qzh,0,sizeof(qzh));
			cin >> n >> d;
			for(int i = 1; i <= n;i++){
				cin >> x[i];
			}
			for(int i = 1;i <= n;i++){
				for(int j = i+1;j <= n;j++){
					int dp[15][15];
					memset(dp,0,sizeof(dp));
					dp[i][0] = 1;
					for(int k = i+1;k <= j;k++){
						for(int l = i;l < k;l++){
							if(x[k]-x[l] <= d){
								for(int o = 1;o <= j-i;o++)
									dp[k][o] += dp[l][o-1];
							}
						}
					}
//					if(i == 1 && j == 4){
//						for(int k = i+1;k <= j;k++){
//							for(int o = 1;o <= 3;o++)
//								cout << dp[k][o] << ' ';
//							cout << endl;
//						}
//					}
					for(int k = 1;k <= i-j+1;k++){
						if(dp[j][k]){
							if(dp[j][k] == 2)
								cnt ++;
							break;
						}
					}
					
					
				}
			}
			cout << cnt << '\n';
		}
		
	}
	return 0;
}
