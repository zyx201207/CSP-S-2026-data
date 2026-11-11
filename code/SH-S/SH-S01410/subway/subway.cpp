#include<bits/stdc++.h>
using namespace std;

int ditie[10005];
int a[10005][10005];

int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i<= m; i++){
		int x;
		cin >> x;
		for(int j = 1;j <= x; j++){
			cin >> ditie[j];
		}
	}
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= q; i++){
		int x,y;
		cin >> x >> y;
		cout << ditie[x] + ditie[y] + a[1][x] + a[1][y] << "\n";
	}
	return 0;
} 
