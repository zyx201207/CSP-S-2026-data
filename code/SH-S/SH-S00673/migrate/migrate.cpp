#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long c,t,a[N];
long long dp[N];//飞到第i个岛上有多少条路径 
long long ans[N];
//考虑dp和搜索 
long long n,d;
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		long long ans = 0;
		for(int i = 1;i <= 1e6;i++) a[i] = 0;

		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> a[i];
		sort(a + 1,a + 1 + n);
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(abs(a[i] - a[j]) > 0) dp[j]++;
			}
		}
		for(int i = 1;i <= n;i++){
			if(dp[i] == 2) ans++;	
		}
		cout << ans << "\n";
	}	
	return 0;
}
