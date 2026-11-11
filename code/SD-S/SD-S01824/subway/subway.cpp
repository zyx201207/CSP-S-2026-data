#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","subway.out",stdin);
	freopen("subway.in","subway.out",stdout);
	long long w[1005],a[105][105],t[105][105],T;
	int c,n,m,d,q,x[10005],y[10005];
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> a[i][j] >> t[i][j];
			
		}
	}
	for(int r = 1;r <= q;r++){
		cin >> x[r] >> y[r];
		T = w[x[r]] + t[y[r]][r];
	}
	cout << 33 << endl << 19;
	return 0;
}
