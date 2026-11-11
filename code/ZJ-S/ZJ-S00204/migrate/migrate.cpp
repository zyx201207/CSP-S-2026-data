#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t, n, tot[1005][1005];
ll d, a[2000005], sum, minx[1005][1005];
int tott, minn;
void dfs(int x, int y, int depth){
	if(depth > minn)
		return ;
	if(x >= y) {
		if(minn == depth)
			tott++;
		else
			tott = 1, minn = depth;
		return ;
	}
	for(int i = x + 1; i <= y; i++)
		if(a[i] - a[x] <= d)
			dfs(i, y, depth + 1);
	return ;
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	if(c<=2) {
		while(t--) {
			cin >> n >> d;
			for(int i = 1; i <= n; i++)
				cin >> a[i];
			sum = 0;
			for(int i = 1; i <= n; i++)
				for(int j = i + 1; j <= n; j++) {
					tott = 0, minn = 1000;
					dfs(i, j, 1);
					if(tott == 2)
						sum++;
				}
			cout << sum << '\n';
		}
		return 0;
	}
	while(t--) {
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sum = 0;
		for(int i = 1; i <= n; i++)
			fill(minx[i] + 1, minx[i] + 1 + n, 1e18),
			     fill(tot[i] + 1, tot[i] + 1 + n, 0);
		for(int len = 2; len <= n; len++)
			for(int i = 1, j = len; j <= n; i++, j++) {
				if(a[j] - a[i] <= d)
					minx[i][j] = tot[i][j] = 1;
				else
					for(int k = i + 1; k < j; k++)
						if(tot[i][k] && tot[k][j] && tot[i][k] < 3 && tot[k][j] <= 3) {
//							if(i==1&&j==7)cerr << i << ',' << j << ';' << k << ':' << minx[i][k] << '+' << minx[k][j] << ',' << minx[i][j] << '\n';
							if(minx[i][k] + minx[k][j] < minx[i][j])
								tot[i][j] = min(3, tot[i][k] * tot[k][j]), minx[i][j] = minx[i][k] + minx[k][j];
							else if(minx[i][k] + minx[k][j] == minx[i][j])
								tot[i][j] = min(3, tot[i][j] + tot[i][k] * tot[k][j]);
						}
//				cerr << i << ',' << j << ':' << minx[i][j] << ',' << tot[i][j] << '\n';
				if(tot[i][j] == 2)
					sum++;
			}
		cout << sum << '\n';
	}
	return 0;
}
