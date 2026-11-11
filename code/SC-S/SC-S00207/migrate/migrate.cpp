#include <bits/stdc++.h>
#define int long long
#define fp(i,a,b) for(int i=a;i<=b;i++)
#define pf(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

constexpr int MN = 2e6+10;
int c, t, n, d, a[MN], dp[5010][5010], pre[5010][5010];

void qwa() {
	cin>>n>>d;
	fp(i,1,n) cin>>a[i];
	int cnt = 0;
	fp(s, 1, n) {
		memset(dp, 0, sizeof dp);
		memset(pre, 0, sizeof pre);
		int p = s;
		dp[s][0] = 1;
		pre[s][0] = 1;
		fp(i,s+1,n) {
			while(a[p] + d < a[i]) p ++;
//			cout<<a[p]<<' '<<d<<' '<<a[i]<<endl;
//			cout<<p<<endl;
//			pre[i][0] = pre[i-1][0];
			fp(j,0,i-s+1) {
				if(j > 0) dp[i][j] = pre[i-1][j-1] - pre[p-1][j-1];
				pre[i][j] = pre[i-1][j] + dp[i][j];
//				cout<<dp[i][j]<<' ';
				if(dp[i][j-1]== 0 && dp[i][j] == 2) cnt ++;
			}
//			cout<<endl;
		}
	}
	cout<<cnt<<endl;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>t;
	while(t--) qwa();
	return 0;
}
