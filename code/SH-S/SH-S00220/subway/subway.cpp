#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,D,q;
int w[250010];
int a[510][510];
int t[510][510];
int x[100010];
int y[100010];
int k[500010];
int d[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> D >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
		for(int j = 2;j <= k[i];j++){
			d[a[i][j - 1]][a[i][j]] = 0;
			d[a[i][j]][a[i][j - 1]] = 0;
		}
		d[a[i][1]][a[i][2]] = t[i][1];
		d[a[i][2]][a[i][1]] = t[i][1];
		d[a[i][k[i]]][a[i][k[i - 1]]] = t[i][k[i]];
		d[a[i][k[i - 1]]][a[i][k[i]]] = t[i][k[i]];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= k[i];j++){
			for(int i2 = 1;i2 <= n;i2++){
				for(int j2 = 1;j2 <= k[i2];j2++){
					if(i != i2 && a[i][j] == a[i2][j2]){
						d[a[i][j - 1]][a[i2][j2]] = t[i][j] + t[i2][j2];
						d[a[i][j + 1]][a[i2][j2]] = t[i][j] + t[i2][j2];
						d[a[i2][j2 - 1]][a[i][j]] = t[i][j] + t[i2][j2];
						d[a[i2][j2 + 1]][a[i][j]] = t[i][j] + t[i2][j2];
					}
				}
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	} 
	for(int i = 1;i <= q;i++){
		cin >> x[i] >> y[i];
		cout << d[x[i]][y[i]] + w[x[i]] + w[y[i]] << '\n';
	}
	return 0;
}
