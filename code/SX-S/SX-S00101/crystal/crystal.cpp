#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n, m, maxx, cnt;
long long a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=maxx;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=cnt;j<=m;j++)
		{
			dp[i][j]=max(dp[i][j],);
		}
	}*/
	int s = sqrt(m * 2);
	if (m >= s * (s + 1) / 2) {
		cout << s + 1;
	} else {
		cout << s;
	}
	return 0;
}
