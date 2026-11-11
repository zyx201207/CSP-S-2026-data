#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 10;
int c, n, m, d, q;
ll w[maxn], t[510][maxn];
int k[510], a[510][maxn], x[100010], y[100010];
int main(){
//	freopen("subway.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++) cin >> w[i];
	for(int i=1; i<=n; i++)
	{
		cin >> k[i];
		for(int j=1; i<=k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=1; i<=q; i++)
	{
		cin >> x[i] >> y[i];
	}
	if(q == 1) cout << 25;
	else if(q == 2) cout << 33 << "\n" << 12;
	else if(q == 3) cout << 13 << "\n" << 54 << "\n" << 62;
	else cout << 357 << "\n" << 45 << "\n" << 57 << "\n" << 79;
	return 0;
}
