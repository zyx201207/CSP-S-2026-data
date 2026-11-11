#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000001],dp[2000001],cnt;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1;i<=n;i++){
			cin >> x[i];
			x[i] -= x[i-1];
			if(i>1) dp[i] = dp[i-1]+x[i];
		}
		x[1]=0;
		dp[1]=0;
		cnt = 0;
		for(int i = 2;i<=n;i++){
			for(int j = 1;j<i;j++){
//				cout << dp[i] <<" "<< dp[j] << endl;
				if(dp[i]-dp[j] == d*2-1) cnt++;
			}
		}
		cout << cnt<<endl;
	}
	return 0;
}
