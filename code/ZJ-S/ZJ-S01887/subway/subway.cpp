#include <bits/stdc++.h>
using namespace std;
struct Node {
	long long t,to;
};
long long c,n,m,d,q,w[50005],dp[5005][5005];
Node tt1,tt2;
vector <Node> v[50005];
int main () {
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	memset (dp,0x3f,sizeof dp);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1;i <= m;i ++)
		cin >> w[i];
	for (long long i = 1;i <= n;i ++) {
		long long k,x,t;
		cin >> k;
		for (long long j = 1;j <= k;j ++)
			cin >> x >> t,v[x].push_back ({t,i});
	}
	for (long long i = 1;i <= n;i ++)
		dp[i][i] = 0;
	for (long long i = 1;i <= n;i ++) {
		long long len = v[i].size ();
		for (long long j = 0;j < len;j ++) {
			for (long long k = 0;k < len;k ++) {
				tt1 = v[i][j],tt2 = v[i][k];
				if (tt1.to >= tt2.to) continue;
				dp[tt1.to][tt2.to]  = min (dp[tt1.to][tt2.to],tt1.t + tt2.t);
			}
		}
	}
	for (long long k = 1;k <= n;k ++) {
		for (long long i = 1;i < k;i ++) {
			if (dp[i][k] >= 0x3f3f3f3f3f3f3f3f)continue;
			for (long long j = 1;j <= n;j ++) {
				if (dp[k][j] >= 0x3f3f3f3f3f3f3f3f)continue;
				if (dp[i][k] + dp[k][j] < dp[i][j])dp[i][j] = dp[j][i] = dp[i][k] + dp[k][j];
			}
		}
	}
	while (q --) {
		long long x,y,Min = 0x3f3f3f3f3f3f3f3f;
		cin >> x >> y;
		long long len = v[x].size (),len2 = v[y].size ();
		for (long long j = 0;j < len;j ++) {
			for (long long k = 0;k < len2;k ++) {
				tt1 = v[x][j],tt2 = v[y][k];
				Min = min (dp[tt1.to][tt2.to] + tt1.t + tt2.t,Min);
			}
		}
		cout << Min + w[x] + w[y] << "\n";
	}
	return 0;
}
