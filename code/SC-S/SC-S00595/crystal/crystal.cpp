#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6,M=12000;
int a[N];
int dp[M][M];
//dp[i][j]:第i到j区间内，使其相等需要多少的代价
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int num = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dp[i][j]=dp[i][j-1]+((a[j]-a[j-1])*(j-i));
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(dp[i][j]<=m)
			{
				mx=max(mx,(j-i+1));
			}
		}
	}
	cout<<mx;
}