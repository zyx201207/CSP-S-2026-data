#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int _case, T, n;
long long d;
long long x[maxn];
long long sum[maxn];
long long dp[2][maxn];

void solve1(){	//²âÊÔµã 1~10
	while(T --){
		long long ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i ++){
			cin >> x[i];
		}
		for(int i = 1; i <= n; i ++){
			for(int j = 1;j <= n;j ++)	sum[j] = 0;
			dp[0][i] = 0,	dp[1][i] = 1;
			sum[i] = 1;
			for(int j = i + 1; j <= n; j ++){
				int l = lower_bound(x + 1, x + n + 1, x[j] - d) - x;
				if(l == j)	break;
				int r = upper_bound(dp[0] + i + 1, dp[0] + j, dp[0][l]) - dp[0] - 1;
				dp[0][j] = dp[0][l] + 1,	dp[1][j] = sum[r] - sum[l - 1];
				if(dp[1][j] == 2)	ans ++;
				sum[j] = sum[j - 1] + dp[1][j];
			}
		}
		cout << ans << "\n";
	}
}

void solve2(){	//²âÊÔµã 11,12 
	while(T --){
		long long ans = 0;
		scanf("%d %lld", &n, &d);
		for(int i = 1; i <= n; i ++){
			scanf("%lld", &x[i]);
		}
		int t = d / (x[2] - x[1]);
		if(t >= 1)	ans = n - 2 * t + 1;
		ans = max(ans, 0LL);
		printf("%lld\n", ans);
	}
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> _case >> T;
	if(_case <= 10)	solve1();
	else if(_case <= 12)	solve2();
//	else if(_case <= 14)	solve3();
	return 0;
}
