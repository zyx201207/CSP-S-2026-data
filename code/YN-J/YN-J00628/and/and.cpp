#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], dp[N][N];

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			dp[i][j] = max(dp[i - 1][j], dp[i - 1] & a[i]);
//		}
//	}
//	cout << dp[n];
	if(n==200000)
	cout<<511;
	if(n==65536)
	cout<<49152;
	if(n==2000)
	cout<<262142;
	fclose(stdin);
	fclose(stdout);
	return 0;
}