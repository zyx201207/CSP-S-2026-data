#include <bits/stdc++.h>
using namespace std;
long long W[1000100] , K[1000100] , A[1010][1000100] , T[1010][1000100];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c , n , m , d , q , k , cnt = 0 , x , y , a;
	cin >> c >> n >> m >> d >> q;
	for (i = 1 ; i <= m ; i++) {
		cin >> W[i];
	}
	for (i = 1 ; i <= n ; i++) {
		cin >> K[i];
		for (j = 1 ; j <= K[i] ; j++) {
			cin >> A[i][j] >> T[i][j];
		}
	}
	while (q--) {
		cin >> x >> y;
		if (12 <= c && 19 >= c) {
			a = T[1][1];
			for (i = 1 ; i <= m ; i++) {
				
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
