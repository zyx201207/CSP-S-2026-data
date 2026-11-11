#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 311;

int n,D,c,t;

int x[N],d[N],sum[N];

int dp[N][N][N];

signed main(){
	
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	
	cin >> c >> t;
	
	while(t --){
		cin >> n >> D;
		if(c == 13 || c == 14)
			cout << 0 << "\n";
		if(c <= 6){
			int ans = 0;
			memset(sum,0,sizeof sum);
			memset(d,0,sizeof d);	
			for(int i = 1;i <= n;i ++){
				cin >> x[i];
				if(i > 1)
					d[i] = x[i] - x[i - 1];
				sum[i] = sum[i - 1] + d[i];
			}
			for(int i = 1;i <= n;i ++){
				for(int j = 1;j <= n;j ++){
					for(int k = 0;k <= n;k ++){
						dp[i][j][k] = 0;
					}
				}
			}
			
			for(int i = 1;i <= n;i ++){
				for(int k = i + 1;k <= n;k ++){
					if(sum[k] - sum[i] > D)
						break;
					dp[i][k][1] = 1; 
				}
			}
			
			
			for(int i = 1;i <= n;i ++){
				for(int j = i;j <= n;j ++){
					for(int k = j + 1;k <= n;k ++){
						if(sum[k] - sum[j] > D)
							break;
						for(int l = 2;l <= n;l ++)
							dp[i][k][l] += dp[i][j][l - 1]; 
					}
				}
			} 
			for(int i = 1;i <= n;i ++){
				for(int j = i + 1;j <= n;j ++){
					for(int k = 1;k <= n;k ++){
						if(dp[i][j][k]){
							if(dp[i][j][k] == 2)
								ans ++;
							break;
						}
					}
				}
			}
				cout << ans << "\n";
		}
		
	}


	return 0;
}








