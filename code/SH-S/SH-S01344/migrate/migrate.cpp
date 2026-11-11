#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+10;

long long a[N];
long long ci[N];
long long dp[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	
	
	int c,t;
	cin >> c >> t;
	while(t--){
		long long n,d;
		cin >> n >> d;
		
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		int ans = 0;
		for(int st = 1;st <= n;st++){
			for(int i = st;i <= n;i++){
				dp[i] =0x3f3f3f3f;
				ci[i] = 0;
			}
			dp[st] = 0;
			ci[st] = 1;
			for(int i = st+1;i <= n;i++){
				
				int mi = 0x3f3f3f3f;
				int cnt = 0; 
				for(int idx = i - 1;idx >= st;idx--){
				
					if(a[i] - a[idx] > d){
						break;
					} 
					if(dp[i] > dp[idx] + 1){
						mi = dp[idx] + 1;
						dp[i] =dp[idx] + 1;
						cnt = 0;
						ci[i] = ci[idx];
					}else{
						if(mi == dp[idx] + 1){
							cnt++;
						}
					}			
				}
				ci[i] += cnt;
			}
			
			int cnt = 0;
			for(int i = st;i <= n;i++){
				if(ci[i] == 2){
					cnt++;
				}
			}
			ans+=cnt;
		}
		cout << ans << endl;
		
	}
	
	return 0;
} 
