#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+10;
typedef long long ll;
ll c,T;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		ll n,d,ans = 0,sum = 0;
		cin >> n >> d;
		int a[N];
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			sum += a[i];
		}
		if(sum == 0){
			cout << "0\n";
			continue;
		}
		ll lock = (n/2)+1;
		if(n % 2 == 0){
			lock = n/2;
		}
		else if(sum/n == a[lock]){
			cout << a[lock] << '\n';
			continue;
		}
		for(int i = 1;i < n;i++){
			int dp[N];
			dp[0] = 0;
			dp[1] = 1;
			for(int j = i+1;j <= n;j++){
				for(int k = 1;k <= d;k++){
					if(j - k < i) break;
					dp[j] += dp[j-k];
				} 
			}
			for(int j = 1;j <= n;j++){
				if(dp[j] > 2){
					ans++;
				}
			}
		}
		ll po = sqrt(ans)/2;
		cout << po << endl;
	}
	return 0;
}

