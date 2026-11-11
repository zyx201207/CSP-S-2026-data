#include <bits/stdc++.h>
#define int long long
#define ll long long
#define f(i,l,r) for(int i =l;i<=r;i++)
#define fe(i,l,r) for(int i = l;i>=r;i--)
#define endl '\n'

using namespace std;

const int N = 5e3 + 5;

int n,d;
int v[N];
int dp[N][N];
int sum[N][N];
int p[N][N];

int tong[N][N];

signed main1() {
	cin >> n >>d;
	f(i,1,n)cin >> v[i];
	int ans = 0;
	f(i,0,n+4)f(j,0,n+4)dp[i][j] = sum[i][j] = p[i][j] = tong[i][j] = 0;
	int badou = 1;
	f(i,1,n){
		dp[i][i] = 1;
		p[i][i] = 0;
		while(v[badou] < v[i]-d){
			f(j,1,badou)tong[j][p[badou][j]] -= dp[badou][j];
			badou++;
		}
		f(j,1,i-1){
			p[i][j] = p[badou][j] + 1;
//			dp[i][j] = dp[badou][j];
//			f(l,badou+1,i-1){
//				if(p[l][j] + 1 == p[i][j])dp[i][j] += dp[l][j];
//			}
			dp[i][j] = tong[j][p[badou][j]];
			if(v[j] >= v[i]-d)p[i][j] = 1,dp[i][j] = 1;
//		f(j,1,n)cout << dp[i][j] << ' ';cout << endl;
//		f(j,1,n)cout << p[i][j] << ' ';cout << endl;
		}
		f(j,1,i-1)ans += (dp[i][j] == 2);
		
		f(j,1,i)tong[j][p[i][j]] += dp[i][j];
		
	}
	cout << ans << endl;
//4 2 1 2 3 4
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;cin >> T>>T;
	while(T--)main1();
	return 0;
}
/*
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/

