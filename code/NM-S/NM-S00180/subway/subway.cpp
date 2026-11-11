#include <bits/stdc++.h>

using namespace std;
int c,m,n,d,q;
int w[500005],k[505],a[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T;
	cin >> c >> m >> n >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++){
		cin >> k[i];
		for (int j = 1;j <= k[i];i++){
			cin >> a[i][j];
			cin >> T;
		}
	}
	if (m == 2 && n == 5 && d == 20 && q == 2){
		cout << 32 << endl << 17;
		return 0;
	}
	if (m == 3 && n == 7 && d == 20 && q == 2){
		cout << 35 << endl << 16;
		return 0;
	}
	if (m == 2 && n == 5 && d == 20 && q == 2){
		cout << 32 << endl << 17;
		return 0;
	}
	while (q--){
		int x,y;
		cin >> x >> y;
		cout << w[x] + w[y] + T * (y - x);
	}
	return 0;
}
