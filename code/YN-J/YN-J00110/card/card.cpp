#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], f[500005], ans[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		for(int j=n+i-1;j<=n;j++)
		    ans[a[j]]++;
	cout<<ans;
	return 0;
}
